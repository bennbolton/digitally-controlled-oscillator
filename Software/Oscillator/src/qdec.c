/*
 * qdec.c
 *
 * Created: 04/02/2026 12:52:49
 *  Author: bb155134
 */ 

#ifndef QDEC_C_
#define QDEC_C_

#include "qdec.h"

#ifdef INTERNAL_QDEC
void qdec_init(void) {
    pinMode(QDEC_A_p, INPUT);
    pinMode(QDEC_B_p, INPUT);
    *pinCTRL(QDEC_A_p) = PORT_ISC_LEVEL_gc /* Set to low level sense */
                        | PORT_OPC_PULLUP_gc; 
    *pinCTRL(QDEC_B_p)= PORT_ISC_LEVEL_gc /* Set to low level sense */
                        | PORT_OPC_PULLUP_gc;
    EVSYS.CH4MUX = evsysMUX(QDEC_A_p); /* Route QDEC_A to event channel 4 */
    EVSYS.CH4CTRL = EVSYS_QDEN_bm /* Enable Quad decoding */
        | EVSYS_DIGFILT_2SAMPLES_gc; /* Enable digital filtering with n samples */
    
    QDEC_TIMER.CTRLD = TC_EVACT_QDEC_gc /* Set quad decoder as event for timer */
                | TC_EVSEL_CH4_gc; /* set timer event source to channel 4 */

    QDEC_TIMER.PER = (ENC_LINE_COUNT * 4 - 1);
    QDEC_TIMER.CTRLA = TC_CLKSEL_DIV1_gc; /* No prescaler (div by 1) */
}
#endif

#ifndef INTERNAL_QDEC
void qdec_init(void) {
    cli();
    pinMode(QDEC_A_p, INPUT);
    pinMode(QDEC_B_p, INPUT);
    *pinCTRL(QDEC_A_p) = PORT_ISC_BOTHEDGES_gc;
    *pinCTRL(QDEC_B_p) = PORT_ISC_BOTHEDGES_gc;
    QDEC_A_p.port->INT0MASK = QDEC_A_p.bm | QDEC_B_p.bm;
    QDEC_A_p.port->INTCTRL = PORT_INT0LVL_LO_gc;

    QDEC_TIMER.CTRLA = TC_CLKSEL_OFF_gc;
    QDEC_TIMER.CTRLB = TC_WGMODE_NORMAL_gc;
    QDEC_TIMER.CTRLD = 0;
    QDEC_TIMER.PER = (ENC_LINE_COUNT * 4) - 1;
    QDEC_TIMER.CNT = 0;

    PMIC.CTRL |= PMIC_LOLVLEN_bm;

    uint8_t port = QDEC_A_p.port->IN;
    ab = ((port & QDEC_A_p.bm) ? 2 : 0) | ((port & QDEC_B_p.bm) ? 1 : 0);
    sei();
}

ISR(PORTE_INT0_vect) {
    uint8_t port = QDEC_A_p.port->IN;
    ab = (ab << 2) & 0b1111;
    ab |= ((port & QDEC_A_p.bm) ? 2 : 0) | ((port & QDEC_B_p.bm) ? 1 : 0);

    switch (ab) {
        case 0b0001:
        case 0b0111:
        case 0b1110:
        case 0b1000:
            QDEC_TIMER.CNT--;
            break;

        case 0b0010:
        case 0b1011:
        case 0b1101:
        case 0b0100:
            QDEC_TIMER.CNT++;
            break;

        default:
            break;
    }
}
#endif

int16_t get_detent_delta(void) {
    static uint16_t prev_cnt;
    static int16_t count_accum = 0;
    // Get new edges
    uint16_t curr = get_raw_qdec();
    int16_t delta = (int16_t)(curr - prev_cnt);
    prev_cnt = curr;

    // Get new detents
    count_accum += delta;
    int16_t detents = count_accum / 4;
    count_accum -= detents * 4;
    return detents;
}


int16_t get_encoder_motion(void) {
    static int32_t s = 0;
    // Infer a speed accumulation
    int16_t detents = get_detent_delta();
    s += detents * 128;
    if (s > 0) s -= 64;
    if (s < 0) s += 64;

    // Convert speed into usable steps
    if (s > 2000) return +500;
    if (s > 1000) return +50;
    if (s > 300)  return +5;
    if (s > 1)    return +1;

    if (s < -2000) return -500;
    if (s < -1000) return -50;
    if (s < -300)  return -5;
    if (s < -1)     return -1;

    return 0;
}


#endif /* QDEC_C_ */