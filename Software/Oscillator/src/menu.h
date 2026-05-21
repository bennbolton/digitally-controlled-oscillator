/*
 * menu.h
 *
 * Created: 10/02/2026 13:21:11
 *  Author: bb155134
 */ 


#ifndef MENU_H_
#define MENU_H_

#include <inttypes.h>
#include "LCD.h"

#define MAX_MENU_FIELDS 9

typedef enum {
    ACTION_NO_ACTION = 0,
    ACTION_EDIT_FIELD,
    ACTION_ENTER_PAGE,
    ACTION_CYCLE_FIELD
} menu_action_t;

typedef enum {
    FIELD_NONE = 0,
    FIELD_NUMBER,
    FIELD_STRING,
    FIELD_DRAWING,
    FIELD_PAGE
} field_type_t;

enum {
    DRAW_SIN,
    DRAW_TRI,
    DRAW_PWM,
    DRAW_TYPE_COUNT
};

typedef struct menu_page_t menu_page_t;

typedef struct {
    char name[20];
    menu_action_t action;
    field_type_t field_type;

    union {
        uint16_t number_value;
        const char *string_value;
        menu_page_t *target_page;
    } value;
} menu_field_t;

struct menu_page_t{
    char title[20];
    menu_field_t fields[MAX_MENU_FIELDS];
    uint8_t selected_field;
    uint8_t scroll_offset;
    uint8_t num_fields;
    uint8_t edit_mode;
};


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
typedef enum {
    MENU_INPUT_NONE = 0,
    MENU_INPUT_UP,
    MENU_INPUT_DOWN,
    MENU_INPUT_CONFIRM,
    MENU_INPUT_SCROLL
} input_event_type_t;

typedef struct {
    input_event_type_t type;
    int16_t value;
} input_event_t;


typedef struct {
    input_event_t buffer[8];
    uint8_t head;
    uint8_t tail;
} input_buffer_t;

extern input_buffer_t inputBuffer;

static inline void input_push(input_event_type_t ev, int16_t value) {
    uint8_t next = (inputBuffer.head + 1) & 0x07;
    if (next == inputBuffer.tail) {inputBuffer.tail = (inputBuffer.tail + 1) & 0x07;}
    inputBuffer.buffer[inputBuffer.head] = (input_event_t) {
        .type = ev,
        .value = value
    };
    inputBuffer.head = next;
}

static inline void input_push_simple(input_event_type_t ev) {
    input_push(ev, 0);
}

static inline void clear_input_buffer(void) {
    inputBuffer.head = inputBuffer.tail;
}

static inline input_event_t input_pop(void) {
    if (inputBuffer.tail == inputBuffer.head) return (input_event_t) {.type = MENU_INPUT_NONE, .value = 0};
    input_event_t ev = inputBuffer.buffer[inputBuffer.tail];
    inputBuffer.tail = (inputBuffer.tail + 1) & 0x07;
    return ev;
}

#define SW0_KEY_MASK (1 << 0)
#define SW1_KEY_MASK (1 << 1)
#define SW2_KEY_MASK (1 << 2)
#define SWQ_KEY_MASK (1 << 3)

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern menu_page_t main_menu;

extern menu_page_t *current_page;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void menu_init(void);
void update_menu(void);

void menu_process_input(void);
void menu_draw(void);

uint16_t menu_get_target_freq(void);

void menu_set_meas_freq(uint16_t f);

uint8_t menu_get_shape(void);

uint16_t menu_get_pwm_ms(void);


#endif /* MENU_H_ */