/*
 *    MAX7456 overlay code combined with the single mic code
 *
 *    This test code creates a vertical white bar on the screen
 *    in the direction of where the user hears a sound.
 */

#define SAMPLES 1000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "display_name.h"

#define RESET 0 // PB0
#define CS 2 // PB2
#define MOSI 3 // PB3
#define MISO 4 // PB4
#define SCK 5 // PB5

// ========== Define functions ============
void ioinit(void); // Initializes IO
void welcome();
void complete();
void verticalBarShow();
void enableAndClear();
void vertical_bar(int upper, int lower);
int sound_to_vbar(int threshold, int mic0, int mic1);
void SPI_write(char address, char byte);
char SPI_read(char address);
void Initialize_ADC0(void);
void Initialize_ADC1(void);
int GetSound(int mic, int samples);
void reset();
// ========== End of Define ============

/*
 * Store, flash, and display names of author. This is not
 * done yet as we need to figure out the ASCII conversion.
 */
void displayNames();
void flashNames();
void nameShow();

void displayNames() {
    SPI_write(0x06, 37); // DMAL 1
    SPI_write(0x07, 0x1E); // T
    SPI_write(0x06, 38); // DMAL 2
    SPI_write(0x07, 0x2D); // i
    SPI_write(0x06, 39); // DMAL 3
    SPI_write(0x07, 0x32); // n
    SPI_write(0x06, 40); // DMAL 4
    SPI_write(0x07, 0x25); // a
    SPI_write(0x06, 42); // DMAL 5
    SPI_write(0x07, 0x1D); // S
    SPI_write(0x06, 43); // DMAL 6
    SPI_write(0x07, 0x31); // m
    SPI_write(0x06, 44); // DMAL 7
    SPI_write(0x07, 0x2D); // i
    SPI_write(0x06, 45); // DMAL 7
    SPI_write(0x07, 0x30); // l
    SPI_write(0x06, 46); // DMAL 7
    SPI_write(0x07, 0x2F); // k
    SPI_write(0x06, 47); // DMAL 8
    SPI_write(0x07, 0x37); // s
    SPI_write(0x06, 48); // DMAL 9
    SPI_write(0x07, 0x38); // t
    SPI_write(0x06, 49); // DMAL 10
    SPI_write(0x07, 0x29); // e
    SPI_write(0x06, 50); // DMAL 11
    SPI_write(0x07, 0x2D); // i
    SPI_write(0x06, 51); // DMAL 12
    SPI_write(0x07, 0x32); // n
}

void flashNames() {
    SPI_write(0x06, 37); // DMAL 1
    SPI_write(0x07, 0x1E); // T
    enableAndClear();
    SPI_write(0x06, 38); // DMAL 2
    SPI_write(0x07, 0x2D); // i
    enableAndClear();
    SPI_write(0x06, 39); // DMAL 3
    SPI_write(0x07, 0x32); // n
    enableAndClear();
    SPI_write(0x06, 40); // DMAL 4
    SPI_write(0x07, 0x25); // a
    enableAndClear();
    SPI_write(0x06, 42); // DMAL 5
    SPI_write(0x07, 0x1D); // S
    enableAndClear();
    SPI_write(0x06, 43); // DMAL 6
    SPI_write(0x07, 0x31); // m
    enableAndClear();
    SPI_write(0x06, 44); // DMAL 7
    SPI_write(0x07, 0x2D); // i
    enableAndClear();
    SPI_write(0x06, 45); // DMAL 7
    SPI_write(0x07, 0x30); // l
    enableAndClear();
    SPI_write(0x06, 46); // DMAL 7
    SPI_write(0x07, 0x2F); // k
    enableAndClear();
    SPI_write(0x06, 47); // DMAL 8
    SPI_write(0x07, 0x37); // s
    enableAndClear();
    SPI_write(0x06, 48); // DMAL 9
    SPI_write(0x07, 0x38); // t
    enableAndClear();
    SPI_write(0x06, 49); // DMAL 10
    SPI_write(0x07, 0x29); // e
    enableAndClear();
    SPI_write(0x06, 50); // DMAL 11
    SPI_write(0x07, 0x2D); // i
    enableAndClear();
    SPI_write(0x06, 51); // DMAL 12
    SPI_write(0x07, 0x32); // n
    enableAndClear();
}

void nameShow() {
    flashNames(); // Flash letters
    displayNames(); // Load entire name into max7456 memory
    SPI_write(0, 0x08); // Enable Display
    _delay_ms(3000);
    SPI_write(0x04, 0x06); // Clear Display on /VSync
    _delay_ms(500);
    displayNames();
    SPI_write(0, 0x08); // Enable Display
    _delay_ms(500);
    SPI_write(0x04, 0x06); // Clear Display on /VSync
    _delay_ms(500);
    displayNames();
    SPI_write(0, 0x08); // Enable Display
    _delay_ms(500);
    SPI_write(0x04, 0x06); // Clear Display on /VSync
    _delay_ms(500);
}

