/*
 * Store, flash, and display names of author. This is not
 * done yet as we need to figure out the ASCII conversion.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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

