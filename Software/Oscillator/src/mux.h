/*
 * mux.h
 *
 * Created: 18/05/2026 11:11:41
 *  Author: bb155134
 */ 


#ifndef MUX_H_
#define MUX_H_

#include "pins.h"
#include "ioPin.h"

typedef enum {
    MUX_PWM = 0,
    MUX_TRI,
    MUX_SIN,
    MUX_GND
} mux_sel_t;

void mux_init(void);

void set_mux(mux_sel_t select);

#endif /* MUX_H_ */