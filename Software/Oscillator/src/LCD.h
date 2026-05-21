/*
 * LCD.h
 *
 * Created: 03/02/2026 13:28:49
 *  Author: bb155134
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "util.h"
#include <inttypes.h>
#include "ioPin.h"
#include <util/delay.h>
#include <stdlib.h>
#include "pins.h"

#define LCD_WIDTH 128
#define LCD_ROWS 4

/* Enum for pixel operations */
typedef enum {
    PIXEL_CLR = 0,
    PIXEL_SET = 1,
    PIXEL_XOR = 2
} LCD_COLOR_t;

/**
 * \brief Hard reset the LCD by pulling the reset pin low
 */
void lcd_reset(void);

/**
 * \brief Remove all pixel from frame buffer and display
 */
void lcd_clear(void);

/**
 * \brief Send an 8 bit command to the LCD
 * 
 * \param c The command to send
 */
void lcd_cmd(uint8_t c);

/**
 * \brief Send pixel data to the LCD
 * 
 * \param data The data to send
 */
void lcd_write_data(uint8_t data);

/**
 * \brief Initialise the LCD for display and communication
 */
void lcd_init(void);

/**
 * \brief Set the row for data to be written to
 * 
 * \param row Index (0-3) of required row
 */
void lcd_set_row(uint8_t row);

/**
 * \brief Set the column for data byte to be written to
 * 
 * \param col Index (0-127) of requried column
 */
void lcd_set_col(uint8_t col);

/**
 * \brief Clear the pixel data from just the frame buffer
 */
void fb_clear(void);

/**
 * \brief Perform a pixel operation on a specific pixel within the frame buffer
 * 
 * \param x X coordinate of pixel (0-127)
 * 
 * \param y Y coordinate of pixel (0-31)
 * 
 * \param color The operation to perform (SET, CLR, XOR)
 */
void fb_set_pixel(uint8_t x, uint8_t y, LCD_COLOR_t color);

/**
 * \brief Send a whole byte to the frame buffer
 * 
 * \param row Row of byte (0-3)
 * 
 * \param col X coordinate of byte (0-127)
 * 
 * \param data The byte to set with
 * 
 * \param color The operation to peform with the byte (SET, CLR, XOR)
 */
void fb_write_byte(uint8_t row, uint8_t col, uint8_t data, LCD_COLOR_t color);

/**
 * \brief Write a character to the frame buffer
 * 
 * \param row The row to write to
 * 
 * \param col The column to begin writing from
 * 
 * \param c The character to write
 */
void fb_write_char(uint8_t row, uint8_t col, char c);

/**
 * \brief Write a string to the frame buffer
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param str The string to write
 */
void fb_write_string(uint8_t row, uint8_t col, const char *str);

/**
 * \brief Write a (8 bit) number to the frame buffer
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param num The number to write
 * 
 * \param base The base of the number to format in (2,10,16 etc)
 */
void fb_write_num_u8(uint8_t row, uint8_t col, uint8_t num, uint8_t base);

/**
 * \brief Write a (16 bit) number to the frame buffer
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param num The number to write
 * 
 * \param base The base of the number to format in (2,10,16 etc)
 */
void fb_write_num_u16(uint8_t row, uint8_t col, uint16_t num, uint8_t base);

/**
 * \brief Flush the frame buffer to the display
 */
void fb_flush(void);

/**
 * \brief Shorthand to quickly write a character directly to the LCD
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param c The character to write
 */
static inline void lcd_write_char(uint8_t row, uint8_t col, char c) {fb_write_char(row, col, c); fb_flush();}

/**
 * \brief Shorthand to quickly write a string directly to the LCD
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param str The string to write
 */
static inline void lcd_write_string(uint8_t row, uint8_t col, const char *str) {fb_write_string(row, col, str); fb_flush();}

/**
 * \brief Shorthand to quickly write a number (8 bit) directly to the LCD
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param num The number to write
 * 
 * \param base The base of the number to format in (2,10,16 etc) 
 */
static inline void lcd_write_num_u8(uint8_t row, uint8_t col, uint8_t num, uint8_t base) {fb_write_num_u8(row, col, num, base); fb_flush();}

/**
 * \brief Shorthand to quickly write a number (16 bit) directly to the LCD
 * 
 * \param row The row to write to
 * 
 * \param col The column to start writing from
 * 
 * \param num The number to write
 * 
 * \param base The base of the number to format in (2,10,16 etc) 
 */
static inline void lcd_write_num_u16(uint8_t row, uint8_t col, uint16_t num, uint8_t base) {fb_write_num_u16(row, col, num, base); fb_flush();}

#endif /* LCD_H_ */