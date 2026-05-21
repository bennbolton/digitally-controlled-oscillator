/*
 * LCD.c
 *
 * Created: 02/02/2026 13:07:28
 *  Author: bb155134
 */ 


#ifndef LCD_C
#define LCD_C

#include "LCD.h"

/* Font table */
const uint8_t font5x7[][5] = {
	// ASCII 32 ' '
	{0x00,0x00,0x00,0x00,0x00},
	// 33 '!'
	{0x00,0x00,0x5F,0x00,0x00},
	// 34 '"'
	{0x00,0x07,0x00,0x07,0x00},
	// 35 '#'
	{0x14,0x7F,0x14,0x7F,0x14},
	// 36 '$'
	{0x24,0x2A,0x7F,0x2A,0x12},
	// 37 '%'
	{0x23,0x13,0x08,0x64,0x62},
	// 38 '&'
	{0x36,0x49,0x55,0x22,0x50},
	// 39 '''
	{0x00,0x05,0x03,0x00,0x00},
	// 40 '('
	{0x00,0x1C,0x22,0x41,0x00},
	// 41 ')'
	{0x00,0x41,0x22,0x1C,0x00},
	// 42 '*'
	{0x14,0x08,0x3E,0x08,0x14},
	// 43 '+'
	{0x08,0x08,0x3E,0x08,0x08},
	// 44 ','
	{0x00,0x50,0x30,0x00,0x00},
	// 45 '-'
	{0x08,0x08,0x08,0x08,0x08},
	// 46 '.'
	{0x00,0x60,0x60,0x00,0x00},
	// 47 '/'
	{0x20,0x10,0x08,0x04,0x02},
	// 48 '0'
	{0x3E,0x51,0x49,0x45,0x3E},
	// 49 '1'
	{0x00,0x42,0x7F,0x40,0x00},
	// 50 '2'
	{0x42,0x61,0x51,0x49,0x46},
	// 51 '3'
	{0x21,0x41,0x45,0x4B,0x31},
	// 52 '4'
	{0x18,0x14,0x12,0x7F,0x10},
	// 53 '5'
	{0x27,0x45,0x45,0x45,0x39},
	// 54 '6'
	{0x3C,0x4A,0x49,0x49,0x30},
	// 55 '7'
	{0x01,0x71,0x09,0x05,0x03},
	// 56 '8'
	{0x36,0x49,0x49,0x49,0x36},
	// 57 '9'
	{0x06,0x49,0x49,0x29,0x1E},
	// 58 ':'
	{0x00,0x36,0x36,0x00,0x00},
	// 59 ';'
	{0x00,0x56,0x36,0x00,0x00},
	// 60 '<'
	{0x08,0x14,0x22,0x41,0x00},
	// 61 '='
	{0x14,0x14,0x14,0x14,0x14},
	// 62 '>'
	{0x00,0x41,0x22,0x14,0x08},
	// 63 '?'
	{0x02,0x01,0x51,0x09,0x06},
	// 64 '@'
	{0x32,0x49,0x79,0x41,0x3E},
	// 65 'A'
	{0x7E,0x11,0x11,0x11,0x7E},
	// 66 'B'
	{0x7F,0x49,0x49,0x49,0x36},
	// 67 'C'
	{0x3E,0x41,0x41,0x41,0x22},
	// 68 'D'
	{0x7F,0x41,0x41,0x22,0x1C},
	// 69 'E'
	{0x7F,0x49,0x49,0x49,0x41},
	// 70 'F'
	{0x7F,0x09,0x09,0x09,0x01},
	// 71 'G'
	{0x3E,0x41,0x49,0x49,0x7A},
	// 72 'H'
	{0x7F,0x08,0x08,0x08,0x7F},
	// 73 'I'
	{0x00,0x41,0x7F,0x41,0x00},
	// 74 'J'
	{0x20,0x40,0x41,0x3F,0x01},
	// 75 'K'
	{0x7F,0x08,0x14,0x22,0x41},
	// 76 'L'
	{0x7F,0x40,0x40,0x40,0x40},
	// 77 'M'
	{0x7F,0x02,0x0C,0x02,0x7F},
	// 78 'N'
	{0x7F,0x04,0x08,0x10,0x7F},
	// 79 'O'
	{0x3E,0x41,0x41,0x41,0x3E},
	// 80 'P'
	{0x7F,0x09,0x09,0x09,0x06},
	// 81 'Q'
	{0x3E,0x41,0x51,0x21,0x5E},
	// 82 'R'
	{0x7F,0x09,0x19,0x29,0x46},
	// 83 'S'
	{0x46,0x49,0x49,0x49,0x31},
	// 84 'T'
	{0x01,0x01,0x7F,0x01,0x01},
	// 85 'U'
	{0x3F,0x40,0x40,0x40,0x3F},
	// 86 'V'
	{0x1F,0x20,0x40,0x20,0x1F},
	// 87 'W'
	{0x7F,0x20,0x18,0x20,0x7F},
	// 88 'X'
	{0x63,0x14,0x08,0x14,0x63},
	// 89 'Y'
	{0x07,0x08,0x70,0x08,0x07},
	// 90 'Z'
	{0x61,0x51,0x49,0x45,0x43},
	// 91 '['
	{0x00,0x7F,0x41,0x41,0x00},
	// 92 '\'
	{0x02,0x04,0x08,0x10,0x20},
	// 93 ']'
	{0x00,0x41,0x41,0x7F,0x00},
	// 94 '^'
	{0x04,0x02,0x01,0x02,0x04},
	// 95 '_'
	{0x80,0x80,0x80,0x80,0x80},
	// 96 '`'
	{0x00,0x03,0x07,0x00,0x00},
	// 97 'a'
	{0x20,0x54,0x54,0x54,0x78},
	// 98 'b'
	{0x7F,0x48,0x44,0x44,0x38},
	// 99 'c'
	{0x38,0x44,0x44,0x44,0x20},
	// 100 'd'
	{0x38,0x44,0x44,0x48,0x7F},
	// 101 'e'
	{0x38,0x54,0x54,0x54,0x18},
	// 102 'f'
	{0x08,0x7E,0x09,0x01,0x02},
	// 103 'g'
	{0x0C,0x52,0x52,0x52,0x3E},
	// 104 'h'
	{0x7F,0x08,0x04,0x04,0x78},
	// 105 'i'
	{0x00,0x44,0x7D,0x40,0x00},
	// 106 'j'
	{0x20,0x40,0x44,0x3D,0x00},
	// 107 'k'
	{0x7F,0x10,0x28,0x44,0x00},
	// 108 'l'
	{0x00,0x41,0x7F,0x40,0x00},
	// 109 'm'
	{0x7C,0x04,0x18,0x04,0x7C},
	// 110 'n'
	{0x7C,0x08,0x04,0x04,0x78},
	// 111 'o'
    {0x38,0x44,0x44,0x44,0x38},
    // 112 'p'
    {0x7C,0x14,0x14,0x14,0x08},
    // 113 'q'
    {0x08,0x14,0x14,0x18,0x7C},
    // 114 'r'
    {0x7C,0x08,0x04,0x04,0x08},
    // 115 's'
    {0x48,0x54,0x54,0x54,0x20},
    // 116 't'
    {0x04,0x3F,0x44,0x40,0x20},
    // 117 'u'
    {0x3C,0x40,0x40,0x20,0x7C},
    // 118 'v'
    {0x1C,0x20,0x40,0x20,0x1C},
    // 119 'w'
    {0x3C,0x40,0x30,0x40,0x3C},
    // 120 'x'
    {0x44,0x28,0x10,0x28,0x44},
    // 121 'y'
    {0x0C,0x50,0x50,0x50,0x3C},
    // 122 'z'
    {0x44,0x64,0x54,0x4C,0x44},
    // 123 '{'
    {0x00,0x08,0x36,0x41,0x00},
    // 124 '|'
    {0x00,0x00,0x7F,0x00,0x00},
    // 125 '}'
    {0x00,0x41,0x36,0x08,0x00},
    // 126 '~'
    {0x08,0x04,0x08,0x10,0x08}
};

void lcd_reset(void) {
    pinLow(LCD_RESETN_p);
    _delay_ms(5);
    pinHigh(LCD_RESETN_p);
    _delay_ms(5);
}

void lcd_clear(void) {
    fb_clear();
    fb_flush();
}

void lcd_cmd(uint8_t c) {
    pinLow(LCD_CS_p);

    while (!(LCD_USART.STATUS & USART_DREIF_bm)) {/* Wait for empty register */}

    LCD_USART.DATA = c;

    while (!(LCD_USART.STATUS & USART_TXCIF_bm)) {/* Spin */}
    LCD_USART.STATUS |= USART_TXCIF_bm; /* Clear the Tx flag */
    pinHigh(LCD_CS_p);
}

void lcd_write_data(uint8_t data) {
    pinHigh(LCD_A0_p);
    lcd_cmd(data);
    pinLow(LCD_A0_p);
}

void lcd_init() {
    /* Pin Setup */
    pinMode(LCD_MOSI_p, OUTPUT);
    pinMode(LCD_CLK_p, OUTPUT);
    pinMode(LCD_A0_p, OUTPUT);
    pinMode(LCD_CS_p, OUTPUT);
    pinMode(LCD_BACKLIGHT_p, OUTPUT);
    pinMode(LCD_RESETN_p, OUTPUT);

    /* Hard Reset */
    lcd_reset();
    
    /* Registers */
    PR.PRPD &= ~PR_USART0_bm;
    
    LCD_USART.CTRLB = USART_TXEN_bm;
    LCD_USART.CTRLB &= ~USART_RXEN_bm;
    LCD_USART.CTRLC = USART_CMODE_MSPI_gc /* Set to Master SPI mode*/
                    | USART_UCPHA_bm; /* Set required clock phase (mode 3) */
    LCD_USART.CTRLC &= ~USART_UDORD_bm; /* Set data order (MSB first) */

    pinHigh(LCD_CLK_p);
    /* Finish up */
    pinLow(LCD_A0_p);
	lcd_cmd(0xE2); /* Soft reset */
    lcd_cmd(0xA0); /* Set column address indexing to increasing */
    lcd_cmd(0xA6); /* Set normal display mode (not inverted) */
    lcd_cmd(0xC8); /* Set reversed COM output scan direction */
    lcd_cmd(0xA2); /* Set the voltage bias ratio */
    lcd_cmd(0x2F); /* Enable all power control options */
    

    lcd_cmd(0xF8); /* Prepare to send booster ratio */
    lcd_cmd(0x00); /* Set booster ratio to 2x,3x,4x */

    lcd_cmd(0x21); /* Set voltage resistor ratio to 1 */

    lcd_cmd(0x81); /* Prepare to send contrast level */
    lcd_cmd(0x1E); /* Set contrast level to optimal */
    
    lcd_cmd(0xA4); /* Turn fill mode off */
    lcd_clear();
    lcd_cmd(0xAF); /* Turn the display on */
    pinHigh(LCD_BACKLIGHT_p);
}

void lcd_set_row(uint8_t row) {
    if (row > 8) return;
    lcd_cmd(0xB0 | row);
}

void lcd_set_col(uint8_t col) {
    if (col >= LCD_WIDTH) return;
    lcd_cmd(0x10 | (col >> 4)); /* Set Most significant bits of column address */
    lcd_cmd(0x00 | (col & 0x0F)); /* Set Least significant bits of column address */
}

/* Framebuffer Code */
static uint8_t framebuffer[LCD_ROWS][LCD_WIDTH];
static uint8_t dirtyRows[LCD_ROWS] = {0,0,0,0};

void fb_clear(void) {
    for (uint8_t p = 0; p < 4; p++) {
        for (uint8_t c = 0; c < 128; c++) {
            framebuffer[p][c] = 0x00;
        }
    }
    for (uint8_t i = 0; i < LCD_ROWS; i++) {
        dirtyRows[i] = 1;
    }
}

void fb_set_pixel(uint8_t x, uint8_t y, LCD_COLOR_t color) {
    if (x >= LCD_WIDTH || y >= 32) return;

    uint8_t row = y >> 3; /* Divide by 8 */
    uint8_t bit = y & 0x07; /* Modulo 8 */
    switch (color) {
        case PIXEL_CLR:
            framebuffer[row][x] &= ~(1 << bit);
            break;
        case PIXEL_SET:
            framebuffer[row][x] |= (1 << bit);
            break;
        case PIXEL_XOR:
            framebuffer[row][x] ^= (1 << bit);
            break;
    }
    dirtyRows[row] = 1;
}

void fb_write_byte(uint8_t row, uint8_t col, uint8_t data, LCD_COLOR_t color) {
    if (col >= LCD_WIDTH || row >= 4) return;
        uint8_t existing = framebuffer[row][col];
        switch (color) {
        case PIXEL_CLR:
            framebuffer[row][col] &= ~data;
            break;
        case PIXEL_SET:
            framebuffer[row][col] = data;
            break;
        case PIXEL_XOR:
            framebuffer[row][col] ^= data;
            break;
    }
    if (framebuffer[row][col] != existing) dirtyRows[row] = 1;
}

void fb_write_char(uint8_t row, uint8_t col, char c) {
    if (col + 5 >= LCD_WIDTH) return;
    for (uint8_t i = 0; i < 5; i++) {
        fb_write_byte(row, col+i, font5x7[c - 32][i], PIXEL_SET);
    }
}

void fb_write_string(uint8_t row, uint8_t col, const char *str) {
    while (*str != '\0') {
        fb_write_char(row, col, *str);
        str++;
        col += 6;
    }
}

static void pad_right(char *dest, const char *src, uint8_t width, char pad) {
    uint8_t len = 0;
    while (src[len] != '\0') len++; /* Find how long the original string was */
    uint8_t pad_count = (width > len) ? (width - len) : 0; /* Find how much padding is needed */
    /* Copy original */
    for (uint8_t i = 0; i < len; i++) { 
        dest[i] = src[i];
    }
    /* Add padding */
    for (uint8_t j = 0; j < pad_count; j++) {
        dest[len+j] = pad;
    }
    dest[len+pad_count] = '\0';
}
static void pad_left(char *dest, const char *src, uint8_t width, char pad) {
    uint8_t len = 0;
    while (src[len] != '\0') len++; /* Find how long the original string was */
    uint8_t pad_count = (width > len) ? (width - len) : 0; /* Find how much padding is needed */
    /* Add padding */
    for (uint8_t i = 0; i < len; i++) { 
        dest[i] = pad;
    }
    /* Copy Original */
    for (uint8_t j = 0; j < pad_count; j++) {
        dest[len+j] = src[j];
    }
    dest[len+pad_count] = '\0';
}

void fb_write_num_u8(uint8_t row, uint8_t col, uint8_t num, uint8_t base) {
    static const uint8_t max_digits_8bit[17] = {0,0,8,6,4,4,3,3,3,3,3,3,3,3,3,3,2};
    char buf[max_digits_8bit[base]];
    utoa(num, buf, base);
    char padded [max_digits_8bit[base]];
    pad_right(padded, buf, max_digits_8bit[base], ' ');
    fb_write_string(row, col, padded);
}

void fb_write_num_u16(uint8_t row, uint8_t col, uint16_t num, uint8_t base) {
    static const uint8_t max_digits_16bit[17] = {0,0,16,11,8,8,7,7,6,6,5,5,5,5,5,5,4};
    char buf[max_digits_16bit[base]];
    utoa(num, buf, base);
    char padded [max_digits_16bit[base]];
    // if (base == 10) pad_right(padded, buf, max_digits_16bit[base], ' ');
    // else pad_left(padded, buf, max_digits_16bit[base], '0');
    pad_right(padded, buf, max_digits_16bit[base], ' ');
    fb_write_string(row, col, padded);
}

void fb_flush(void) {
    for (uint8_t row = 0; row < 4; row++) {
        if (!dirtyRows[row]) continue; /* If row hasnt changed then dont bother rewriting */
        lcd_set_row(row);
        lcd_set_col(0);
        for (uint8_t c = 0; c < LCD_WIDTH; c++) {
            lcd_write_data(framebuffer[row][c]);
        }
        dirtyRows[row] = 0;
    }
}

#endif /* LCD_C */