/*
 * mux.c
 *
 * Created: 18/05/2026 11:14:33
 *  Author: bb155134
 */ 
#ifndef MUX_C
#define MUX_C

#include "mux.h"

void mux_init(void) {
    pinMode(MUX_SEL0_p, OUTPUT);
    pinMode(MUX_SEL1_p, OUTPUT);
    set_mux(MUX_GND);
}

void set_mux(mux_sel_t select) {
    pinWrite(MUX_SEL0_p, (select >> 0) & 1);
    pinWrite(MUX_SEL1_p, (select >> 1) & 1);
}

#endif /* MUX_C */