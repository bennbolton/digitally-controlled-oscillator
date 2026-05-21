/*
 * Oscillator.c
 *
 * Created: 29/01/2026 14:59:02
 * Author : bb155134
 */ 

#include "util.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "ioPin.h"
#include "LCD.h"
#include "qdec.h"
#include "freq_measure.h"
#include "digipot.h"
#include "menu.h"
#include "control.h"
#include "oscillators.h"
#include "mux.h"


/** ============================================================
 * Oscillator Instances
 * =============================================================
*/

/* Triangle / PWM Core */

void tri_dg_write_freq_res(uint16_t D_cmd) {
    dg_write(1, D_cmd);
}

void tri_set_cap(uint8_t mode) {
    pinWrite(CAP_SEL_PWM_p, mode);
}

static oc_oscillator_t tri_osc = {
    .type = OC_TRI,

    .state = {
        .cap_mode = OC_CAP_LOW,
        .f_target = 0,
        .f_meas = 0,
        .e_accum = 0,
        .D_cmd = 0
    },

    .pid = {
        .Kp = 2.0,
        .Ki = 0.3,
        .Kd = 0
    },

    .low_band = &tri_low_band,
    .high_band = &tri_high_band,

    .get_freq = get_tri_freq,
    .set_freq_res = tri_dg_write_freq_res,
    .set_cap = tri_set_cap
};

/* Sin Core */

void sin_dg_write_freq_res(uint16_t D_cmd) {
    dg_write(2, D_cmd);
    dg_write(3, D_cmd);
}

void sin_dg_write_gain_res(uint16_t D_cmd) {
    dg_write(4, D_cmd);
}

void sin_set_cap(uint8_t mode) {
    pinWrite(CAP_SEL_SIN_p, mode);
}

static oc_oscillator_t sin_osc = {
    .type = OC_SIN,

    .state = {
        .cap_mode = OC_CAP_LOW,
        .f_target = 0,
        .f_meas = 0,
        .e_accum = 0,
        .D_cmd = 0
    },

    .pid = {
        .Kp = 1.5,
        .Ki = 0.2,
        .Kd = 0
    },

    .low_band = &sin_low_band,
    .high_band = &sin_high_band,

    .get_freq = get_sin_freq,
    .set_freq_res = sin_dg_write_freq_res,
    .set_gain_res = sin_dg_write_gain_res,
    .set_cap = sin_set_cap
    
};


void board_init() {
    CLK.CTRL = 0x01;

    pinMode(LED0_p, OUTPUT);
    pinMode(LED1_p, OUTPUT);
    pinMode(CAP_SEL_PWM_p, OUTPUT);
    pinMode(CAP_SEL_SIN_p, OUTPUT);

    pinMode(SW0_p, INPUT);
    pinHigh(LED0_p);
    pinHigh(LED1_p);

}

int main(void) {
    board_init();
    digi_init();
    lcd_init();
	menu_init();
    freq_measure_init();
    qdec_init();
    mux_init();

    uint16_t measured;
    uint8_t mux_select;
    main_menu.fields[1].value.number_value = 440;
    uint8_t loop_div = 0;
    /* Triangle Core */
    oc_set_target(&tri_osc, 440);
    oc_control_step(&tri_osc);


    /* Sin Core */
    oc_set_target(&sin_osc, 440);
    oc_control_step(&sin_osc);



    _delay_ms(10);
    clear_input_buffer();

    while (1) {
    
        menu_process_input();
        uint16_t target = menu_get_target_freq();

        
        if (loop_div++ >= 2) {
            loop_div = 0;

            /* Triangle Core */
            oc_set_target(&tri_osc, target);
            oc_control_step(&tri_osc);
    
    
            /* Sin Core */
            oc_set_target(&sin_osc, target);
            oc_control_step(&sin_osc);
            
        }

        /* Standard */
        switch (menu_get_shape()) {
            case DRAW_SIN:
                measured = sin_osc.state.f_meas;
                mux_select = MUX_SIN;
                break;

            case DRAW_TRI:
                measured = tri_osc.state.f_meas;
                mux_select = MUX_TRI;
                break;

            case DRAW_PWM:
                measured = tri_osc.state.f_meas;
                mux_select = MUX_PWM;
                break;
            
            default:
				measured = 0;
                mux_select = MUX_GND;
                break;
        }
        uint16_t pwm_ms = menu_get_pwm_ms();
        dg_write(0, ((uint32_t) pwm_ms << 10) / 100); //multiply by 1024 and divide by 100
        set_mux(mux_select);
        menu_set_meas_freq(measured);


        /* Finish Up */
        menu_draw();
        dg_flush();
        fb_flush();
 
        /* End */
        
    }
}

