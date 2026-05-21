/*
 * ioPin.h
 *
 * Created: 02/02/2026 10:35:56
 *  Author: bb155134
 */ 
#ifndef IOPIN_H
#define IOPIN_H

#include <avr/io.h>

#define USART_UCPHA_bm 0x02
#define USART_UDORD_bm 0x04

typedef enum {
    INPUT = 0,
    OUTPUT = 1
} io_dir_t;


typedef struct {
    PORT_t *port;
    uint8_t pin;
    uint8_t bm;
} ioPin_t;

/**
 * \brief Create an IO Pin object from port and pin number
 * 
 * \param port Pointer to the pin's port
 * 
 * \param pin The pin number
 * 
 * \return Pin structure ready for further use
 */
#define IO_PIN(port, pin) (ioPin_t) { (&port), (pin), (1u << (pin)) }


/**
 * \brief Get a pin's control register
 * 
 * \param p The pin you want the register for
 * 
 * \return A pointer towards the CTRL register
 */
static inline volatile uint8_t* pinCTRL(ioPin_t p) {
    return (volatile uint8_t*)((uintptr_t)p.port + 0x10 + p.pin);
}

/**
 * \brief Get a pin's code for use in the Event System Mux register
 * 
 * \param p The pin you want the code for
 * 
 * \return The EVSYS code for the pin
 */
static inline uint8_t evsysMUX(ioPin_t p) {
    uintptr_t base = (uintptr_t)p.port;
    if (base == (uintptr_t)&PORTA) return 0x50 + p.pin;
    if (base == (uintptr_t)&PORTB) return 0x58 + p.pin;
    if (base == (uintptr_t)&PORTC) return 0x60 + p.pin;
    if (base == (uintptr_t)&PORTD) return 0x68 + p.pin;
    if (base == (uintptr_t)&PORTE) return 0x70 + p.pin;
    if (base == (uintptr_t)&PORTF) return 0x78 + p.pin;
    else return 0;
}

/**
 * \brief Set the pin mode for a given pin
 * 
 * \param pin The pin to configure
 * 
 * \param dir The direction to set the pin (INPUT or OUTPUT)
 */
static inline void pinMode(ioPin_t pin, io_dir_t dir) {
    if (dir == INPUT) pin.port->DIRCLR = pin.bm;
    else pin.port->DIRSET = pin.bm;
}

/**
 * \brief Write a digital value to a pin out
 * 
 * \param pin The pin to write to
 * 
 * \param d The value to send (1 or 0)
 */
static inline void pinWrite(ioPin_t pin, uint8_t d) {
    if (d) pin.port->OUTSET = pin.bm;
    else pin.port->OUTCLR = pin.bm;
}

/**
 * \brief Set a pin output to HIGH
 * 
 * \param pin The pin to set
 */
static inline void pinHigh(ioPin_t pin) {
    pin.port->OUTSET = pin.bm;
}

/**
 * \brief Set a pin output to LOW
 * 
 * \param pin The pin to set
 */
static inline void pinLow(ioPin_t pin) {
    pin.port->OUTCLR = pin.bm;
}

/**
 * \brief Toggle a pin's output state (HIGH -> LOW, LOW -> HIGH)
 * 
 * \param pin The pin to toggle
 */
static inline void pinTgl(ioPin_t pin) {
    pin.port->OUTTGL = pin.bm;
}

/**
 * \brief Read the digital value on a pin
 * 
 * \param pin The pin to read
 * 
 * \return The value read from the pin's register
 */
static inline uint8_t pinRead(ioPin_t pin) {
    return pin.port->IN & pin.bm;
}

#endif /* IOPIN_H */