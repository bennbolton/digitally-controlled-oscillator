/*
 * qdec.h
 *
 * Created: 04/02/2026 12:51:19
 *  Author: bb155134
 */ 

#ifndef QDEC_H_
#define QDEC_H_

#include <avr/interrupt.h>
#include <inttypes.h>
#include "ioPin.h"
#include "pins.h"

/** 
 * Uncomment the following QDEC option to use the inbuilt 
 * Xmega QDEC (requires two successive pins) or leave commented 
 * to use a custom decoder
 */
// #define INTERNAL_QDEC

#define ENC_LINE_COUNT 24 /* The number of dents on the encoder */

static volatile uint8_t ab;

/**
 * \brief Initialise the QDEC module
 */
void qdec_init(void);

/**
 * \brief Get the current readout of encoder position
 * 
 * \return The encoder position
 */
static inline uint16_t get_raw_qdec(void) {return QDEC_TIMER.CNT;}

/**
 * \brief Gets the amount of detents turned since last poll
 * 
 * \return The number of detents turned
 */
int16_t get_detent_delta(void);

/**
 * \brief Gets a scaled value of encoder turns loosely based on speed of turning
 * 
 * \return A number representing encoder motion (-500 to +500)
 */
int16_t get_encoder_motion(void);


#endif /* QDEC_H_ */