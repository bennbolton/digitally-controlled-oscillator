/*
 * freq_measure.c
 *
 * Created: 09/02/2026 10:30:47
 *  Author: bb155134
 */ 

#include "freq_measure.h"

void freq_measure_init(void) {
	/* Sin wave measurement */
	pinMode(SIN_FREQ_p, INPUT);
	*pinCTRL(SIN_FREQ_p) = PORT_ISC_RISING_gc; /* Enable input sensing */

	EVSYS.CH0MUX = evsysMUX(SIN_FREQ_p);
	EVSYS.CH0CTRL = EVSYS_DIGFILT_1SAMPLE_gc;

	/* Setup timer */
	F_SIN_MEASURE_TC.CTRLA = TC_CLKSEL_DIV4_gc;
	F_SIN_MEASURE_TC.CTRLB = TC0_CCAEN_bm | TC_WGMODE_NORMAL_gc;
	F_SIN_MEASURE_TC.CTRLD = TC_EVACT_FRQ_gc | TC_EVSEL_CH0_gc;
	F_SIN_MEASURE_TC.CNT = 0;
	F_SIN_MEASURE_TC.INTCTRLB = TC_CCAINTLVL_LO_gc;
	

	/* Tri/PWM wave measurement */
	pinMode(PWM_FREQ_p, INPUT);
	*pinCTRL(PWM_FREQ_p) = PORT_ISC_RISING_gc; /* Enable input sensing */

	EVSYS.CH1MUX = evsysMUX(PWM_FREQ_p);
	EVSYS.CH1CTRL = EVSYS_DIGFILT_1SAMPLE_gc;

	/* Setup timer */
	F_PWM_MEASURE_TC.CTRLA = TC_CLKSEL_DIV4_gc;
	F_PWM_MEASURE_TC.CTRLB = TC1_CCAEN_bm | TC_WGMODE_NORMAL_gc;
	F_PWM_MEASURE_TC.CTRLD = TC_EVACT_FRQ_gc | TC_EVSEL_CH1_gc;
	F_PWM_MEASURE_TC.CNT = 0;
	F_PWM_MEASURE_TC.INTCTRLB = TC_CCAINTLVL_LO_gc;
	
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
	sei();
}

ISR(F_SIN_MEASURE_TC_VECT) {
    last_measured_sin_ticks = F_SIN_MEASURE_TC.CCA;
}

ISR(F_PWM_MEASURE_TC_VECT) {
    last_measured_pwm_ticks = F_PWM_MEASURE_TC.CCA;
}