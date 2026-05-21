/*
 * menu.c
 *
 * Created: 10/02/2026 13:21:29
 *  Author: bb155134
 */ 

#include "menu.h"
#include <string.h>
#include "ioPin.h"
#include "qdec.h"

menu_page_t main_menu;

menu_page_t *current_page = NULL;

void menu_init() {
    main_menu = (menu_page_t) { 
        .title = "Main Menu", 
        .fields = {
            { 
                .name = "Shape",
                .action = ACTION_CYCLE_FIELD,
                .field_type = FIELD_DRAWING,
                .value.number_value = DRAW_TRI
            }, 
            {
                .name = "Targ Freq", 
                .action = ACTION_EDIT_FIELD,
                .field_type = FIELD_NUMBER,
                .value.number_value = 0
            }, 
            { 
                .name = "Act Freq",
                .action = ACTION_NO_ACTION,
                .field_type = FIELD_NUMBER,
                .value.number_value = 0
            },
            {
                .name = "Mark-Space",
                .action = ACTION_EDIT_FIELD,
                .field_type = FIELD_NUMBER,
                .value.number_value = 50
            },
            // {
            //     .name = "Test 2",
            //     .action = ACTION_NO_ACTION,
            //     .field_type = FIELD_NUMBER,
            //     .value.number_value = 2300
            // }
        },
        .selected_field = 0, 
        .scroll_offset = 0,
        .num_fields = 4,
        .edit_mode = 0
    };

    current_page = &main_menu;
}

static void make_title(const char *title, char *out) {
    char *p = out;
    *p++ = '=';
    *p++ = '=';
    *p++ = ' ';
    while (*title) *p++ = *title++;
    *p++ = ' ';
    *p++ = '=';
    *p++ = '=';
    *p++ = '\0';
}

void menu_draw() {
    fb_clear();
    /* Title */
    char decorated_title[25];
    make_title(current_page->title, decorated_title);
    uint8_t title_start = (128 - (strlen(decorated_title) * 5)) >> 1;
    fb_write_string(0, title_start, decorated_title);
    
    /* Fields */
    for (uint8_t screen_row = 1; screen_row < 4; screen_row++) {
        uint8_t field_index = current_page->scroll_offset + (screen_row - 1);
        menu_field_t field = current_page->fields[field_index];
        if (field_index == current_page->selected_field) fb_write_char(screen_row, (current_page->edit_mode) ? 79 : 0, '>');
        fb_write_string(screen_row, 8, field.name);
        
        switch (field.field_type) {
            case FIELD_NONE:
                break;
            case FIELD_NUMBER:
                fb_write_num_u16(screen_row, 87, field.value.number_value, 10);
                break;
            case FIELD_STRING:
                fb_write_string(screen_row, 87, field.value.string_value);
                break;
            case FIELD_DRAWING:
                fb_write_num_u16(screen_row, 87, field.value.number_value, 10);

                switch (field.value.number_value) {
                    case DRAW_SIN:
                        fb_write_string(screen_row, 87, "Sin");
                        break;

                    case DRAW_TRI:
                        fb_write_string(screen_row, 87, "Tri");
                        break;

                    case DRAW_PWM:
                        fb_write_string(screen_row, 87, "PWM");
                        break;
                    
                    default:
                        break;
                }
                break;
            case FIELD_PAGE:
                fb_write_string(screen_row, 87, "-->");
                break;
        }
    }
    // fb_flush();
}

input_buffer_t inputBuffer = {.head = 0, .tail = 0};

static void input_poll() {
    static uint8_t key_state = 0x0F;
    /* Switch 0 */
    if (pinRead(SW0_p) && !(key_state & SW0_KEY_MASK)) {
        key_state |= SW0_KEY_MASK;
        input_push_simple(MENU_INPUT_CONFIRM);
    } else if (!pinRead(SW0_p) && (key_state & SW0_KEY_MASK)) {
        key_state &= ~ SW0_KEY_MASK;
    }
    /* Switch 1 */
    if (pinRead(SW1_p) && !(key_state & SW1_KEY_MASK)) {
        key_state |= SW1_KEY_MASK;
        input_push_simple(MENU_INPUT_UP);
    } else if (!pinRead(SW1_p) && (key_state & SW1_KEY_MASK)) {
        key_state &= ~ SW1_KEY_MASK;
    }    
    /* Switch 2 */
    if (pinRead(SW2_p) && !(key_state & SW2_KEY_MASK)) {
        key_state |= SW2_KEY_MASK;
        input_push_simple(MENU_INPUT_DOWN);
    } else if (!pinRead(SW2_p) && (key_state & SW2_KEY_MASK)) {
        key_state &= ~ SW2_KEY_MASK;
    }
    /* Encoder Switch */
    if (pinRead(QDEC_SW_p) && !(key_state & SWQ_KEY_MASK)) {
        key_state |= SWQ_KEY_MASK;
        input_push_simple(MENU_INPUT_CONFIRM);
    } else if (!pinRead(QDEC_SW_p) && (key_state & SWQ_KEY_MASK)) {
        key_state &= ~ SWQ_KEY_MASK;
    }

    /* Encoder */
    int16_t motion = get_encoder_motion();
    if (motion) {
        input_push(MENU_INPUT_SCROLL, motion);
    }
    

}

void menu_process_input() {
    input_poll();
    menu_field_t *field = &(current_page->fields[current_page->selected_field]);
    input_event_t ev = input_pop();
    switch (ev.type) {
        case MENU_INPUT_NONE:
            return;
            break;

        case MENU_INPUT_UP:
            if (current_page->edit_mode) {
                if (field->field_type == FIELD_NUMBER) field->value.number_value++;
            } else if (current_page->selected_field > 0) {
                current_page->selected_field--;
                if (current_page->selected_field < current_page->scroll_offset) {
                    current_page->scroll_offset = current_page->selected_field;
                }
            }
            break;


        case MENU_INPUT_DOWN:
            if (current_page->edit_mode) {
                if (field->field_type == FIELD_NUMBER) field->value.number_value--;
            } else if (current_page->selected_field + 1 < current_page->num_fields) {
                current_page->selected_field++;
                if (current_page->selected_field >= current_page->scroll_offset + 3) {
                    current_page->scroll_offset = current_page->selected_field - 2;
                }
            }
            break;

        case MENU_INPUT_CONFIRM:
            if (current_page->edit_mode) {
                current_page->edit_mode = 0;
                return;
            }

            switch (field->action) {
                case ACTION_EDIT_FIELD:
                    current_page->edit_mode = 1;
                    break;
                
                case ACTION_ENTER_PAGE:
                    if (field->value.target_page) {
                        current_page = &field->value.target_page;
                        current_page->selected_field = 0;
                        current_page->scroll_offset = 0;
                    }
                    break;

                case ACTION_CYCLE_FIELD:
                    field->value.number_value++;
                    if (field->value.number_value >= DRAW_TYPE_COUNT) {
                        field->value.number_value = 0;
                    }
                    break;

                case ACTION_NO_ACTION:
                default:
                    break;
            }

            break;

        case MENU_INPUT_SCROLL:
            if (current_page->edit_mode) {
                if (field->field_type == FIELD_NUMBER) {
                    if ((int32_t)field->value.number_value + ev.value >= 0) {
                        field->value.number_value += ev.value;
                    } else field->value.number_value = 0;
                }
            } else {
                int16_t field_num = current_page->selected_field + ev.value;
                if (field_num < 0) current_page->selected_field = 0;
                else if (field_num >= current_page->num_fields) current_page->selected_field = current_page->num_fields - 1;
                else current_page->selected_field = field_num;
                
                if (current_page->selected_field < current_page->scroll_offset) {
                    current_page->scroll_offset = current_page->selected_field;
                } 
                else if (current_page->selected_field >= current_page->scroll_offset + 3) {
                    current_page->scroll_offset = current_page->selected_field - 2;
                }
                // if (current_page->num_fields < 3)
            }
            break;
    }
}

void update_menu() {menu_process_input(); menu_draw();}

uint16_t menu_get_target_freq(void) {
    return main_menu.fields[1].value.number_value;
}
void menu_set_meas_freq(uint16_t f) {
    main_menu.fields[2].value.number_value = f;
}

uint8_t menu_get_shape(void) {
    return main_menu.fields[0].value.number_value;
}

uint16_t menu_get_pwm_ms(void) {
    return main_menu.fields[3].value.number_value;
}