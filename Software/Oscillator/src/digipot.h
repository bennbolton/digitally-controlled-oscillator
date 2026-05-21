/*
 * digipot.h
 *
 * Created: 06/02/2026 10:54:15
 *  Author: bb155134
 */ 

#ifndef DIGIPOT_H_
#define DIGIPOT_H_

#include "ioPin.h"
#include <inttypes.h>
#include "pins.h"

#define DIGI_NUM 5 /* The number of DigiPots in the system daisy-chained together */

/* ! Buffer for DigiPot commands */
extern uint16_t dg_buffer[DIGI_NUM];

/**
 * \brief Send one 16bit command to DigiPots
 * 
 * \param c Command to send
 * 
 * \return 16 bit word out the end of the daisy chain
 */
uint16_t digi_cmd(uint16_t c);

/**
 * \brief Flush the dg Buffer of commands to the DigiPots
 */
void dg_flush(void);

/**
 * \brief Initiliase the DigiPots
 */
void digi_init(void);

/**
 * \brief Write a wiper position directly to a DigiPot
 * 
 * \param data The wiper position to write
 * 
 * \return 16 bit word out the end of the daisy chain
 */
uint16_t digi_write(uint16_t data);

/**
 * \brief Write a wiper position into the dg Buffer
 * 
 * \param ident Identification index of the DigiPot buffer position to write to
 * \param data The wiper position to write
 */
void dg_write(uint8_t ident, uint16_t data);

/**
 * \brief Write wiper positions to some/all of the DigiPot buffers
 * 
 * \param data Array of wiper positions in order by index to send
 */
static inline void dg_multiwrite(const uint16_t *data) {
    for (uint8_t i = 0; i < DIGI_NUM; i++) {
        dg_write(i, data[i]);
    }
}

/**
 * \brief Write wiper positions directly to some/all of the Digipots
 * 
 * \param data Array of wiper positions in order by index to send
 */
static inline void digi_multwrite(const uint16_t *data) {
    dg_multiwrite(data);
    dg_flush();
}

/**
 * \brief Clamp a value between the min and max digipot command values
 * 
 * \param val The value to be clamped
 * 
 * \return The clamped value
 */
uint16_t clamp_digi(uint16_t val);

#endif /* DIGIPOT_H_ */