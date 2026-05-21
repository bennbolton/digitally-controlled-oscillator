/*
 * pins.h
 *
 * Created: 09/02/2026 14:27:07
 *  Author: bb155134
 */

#ifndef PINS_H_
#define PINS_H_

/* Digipot */

#define DIGI_USART USARTC0

#define DIGI_TX_p IO_PIN(PORTC, 3) //
#define DIGI_CLK_p IO_PIN(PORTC, 1)//
#define DIGI_CS_p IO_PIN(PORTC, 0)//
#define DIGI_RX_p IO_PIN(PORTC, 2)//
#define DIDI_RDY_p IO_PIN(PORTC, 4)-

/* Freq measure */
/* - Event system 0 */

#define F_SIN_MEASURE_TC TCD0
#define F_SIN_MEASURE_TC_VECT TCD0_CCA_vect
/* - Event system 1*/
#define F_PWM_MEASURE_TC TCD1
#define F_PWM_MEASURE_TC_VECT TCD1_CCA_vect

#define SIN_FREQ_p IO_PIN(PORTE, 0)
#define PWM_FREQ_p IO_PIN(PORTA, 7)

/* LCD */

#define LCD_USART USARTD0

#define LCD_MOSI_p IO_PIN(PORTD, 3)
#define LCD_CLK_p IO_PIN(PORTD, 1)
#define LCD_A0_p IO_PIN(PORTD, 0)
#define LCD_CS_p IO_PIN(PORTF, 3)
#define LCD_BACKLIGHT_p IO_PIN(PORTE, 4)
#define LCD_RESETN_p IO_PIN(PORTA, 3)

/* QDEC */
/* - Event system 4 */

#define QDEC_TIMER TCE0

#define QDEC_A_p IO_PIN(PORTE, 1)
#define QDEC_B_p IO_PIN(PORTE, 3)
#define QDEC_SW_p IO_PIN(PORTE, 2)

/* Control */

#define CAP_SEL_SIN_p IO_PIN(PORTB, 2)
#define CAP_SEL_PWM_p IO_PIN(PORTA, 4)
#define MUX_SEL0_p IO_PIN(PORTB, 3)
#define MUX_SEL1_p IO_PIN(PORTB, 1)

/* On board */

#define SW0_p IO_PIN(PORTE, 5)
#define SW1_p IO_PIN(PORTF, 1)
#define SW2_p IO_PIN(PORTF, 2)
#define LED0_p IO_PIN(PORTR, 0)
#define LED1_p IO_PIN(PORTR, 1)


#endif /* PINS_H_ */