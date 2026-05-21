/*
 * digipot.c
 *
 * Created: 06/02/2026 10:54:31
 *  Author: bb155134
 */ 

#include "digipot.h"

uint16_t dg_buffer[DIGI_NUM] = {0};
uint8_t dirtyPots = 0;

uint16_t digi_cmd(uint16_t c) {
    uint8_t command = (c >> 8) & 0x00FF; /* Get 8 MSB */
	
	while (!(DIGI_USART.STATUS & USART_DREIF_bm)) {/* Wait for empty register */}
	DIGI_USART.DATA = command;

	while (!(DIGI_USART.STATUS & USART_DREIF_bm)) {/* Wait for empty register */}
	command = c & 0x00FF;       /* Get 8 LSB */
	DIGI_USART.DATA = command;

	while (!(DIGI_USART.STATUS & USART_TXCIF_bm)) {/* Spin */}
	DIGI_USART.STATUS |= USART_TXCIF_bm; /* Clear the Tx flag */
	return 0x0000; /* Temporary return value*/
}

uint16_t clamp_digi(uint16_t val) {
    if (val > 0x3E6) return 0x3E6;
    return val;
}

uint16_t digi_write(uint16_t data) {
    data = clamp_digi(data);
    pinLow(DIGI_CS_p);
    data = (data & 0x03FF) | 0x0400; /* Truncate to data then add command bit */
    uint16_t out = digi_cmd(data);
    pinHigh(DIGI_CS_p);
    return out;
}

void dg_write(uint8_t ident, uint16_t data) {
    data = clamp_digi(data);
    data = (data & 0x03FF) | 0x0400; /* Truncate to data then add command bit */
    if (dg_buffer[ident] != data) {
        dg_buffer[ident] = data;
        dirtyPots = 1;
    }    
}

void dg_flush() {
    dirtyPots = 1;
    if (dirtyPots) {
        pinLow(DIGI_CS_p);
        for (uint8_t i = 0; i< DIGI_NUM; i++) {
            digi_cmd(dg_buffer[i]);
        }
        pinHigh(DIGI_CS_p);
        dirtyPots = 0;
    }
}

void digi_init(void) {
    pinMode(DIGI_TX_p, OUTPUT);
    pinMode(DIGI_CLK_p, OUTPUT);
    pinMode(DIGI_CS_p, OUTPUT);
    pinMode(DIGI_RX_p, INPUT);
    
    PR.PRPC &= ~PR_USART0_bm; /* Ensure the clock is ticking the Usart module */

    DIGI_USART.CTRLB |= USART_TXEN_bm; /* Enable transmission */
    DIGI_USART.CTRLB |= USART_RXEN_bm; /* Enable receiving */
    DIGI_USART.CTRLC = USART_CMODE_MSPI_gc /* Set to Master SPI mode */
                    | USART_UCPHA_bm; /* Set required clock phase (mode 1) */
    DIGI_USART.CTRLC &= ~USART_UDORD_bm; /* Set data order (MSB first) */
    
    pinLow(DIGI_CLK_p);
    pinHigh(DIGI_TX_p);

    for (uint8_t i = 0; i < DIGI_NUM; i++) {
        dg_buffer[i] = 0x1802; /* Enable wiper movement */
    }
    dirtyPots = 1;
    dg_flush();
}
