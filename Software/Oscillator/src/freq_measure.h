/*
 * freq_measure.h
 *
 * Created: 09/02/2026 10:30:28
 *  Author: bb155134
 */ 

#ifndef FREQ_MEASURE_H_
#define FREQ_MEASURE_H_

#include "util.h"
#include <inttypes.h>
#include <avr/interrupt.h>
#include "ioPin.h"
#include "pins.h"
#include "util.h"

#define F_TIMER_PRES 4

volatile uint32_t last_measured_sin_ticks; /* Measured period of sin signal in clock ticks */
volatile uint32_t last_measured_pwm_ticks; /* Measured period of sin signal in clock ticks */

/**
 * \brief Initialise the frequency measure module
 */
void freq_measure_init(void);

/**
 * \brief Read the most up to date measure of sin wave frequency 
 * 
 * \return Frequency in Hz
 */
static inline uint16_t get_sin_freq(void) {
    uint32_t ticks = last_measured_sin_ticks;
    return ticks ? (uint32_t) F_CPU / (F_TIMER_PRES * ticks) : 0;
}

/**
 * \brief Read the most up to date measure of PWM frequency
 * 
 * \return Frequency in Hz
 */
static inline uint16_t get_pwm_freq(void) {
    uint32_t ticks = last_measured_pwm_ticks;
    return ticks ? (uint32_t) F_CPU / (F_TIMER_PRES * ticks) : 0;
}

/**
 * \brief Read the most up to date measure of triangle wave frequency
 * 
 * \return Frequency in Hz
 */
static inline uint16_t get_tri_freq(void) {
    return get_pwm_freq();
}

#endif /* FREQ_MEASURE_H_ */