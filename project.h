/*
 *    MAX7456 overlay code combined with the single mic code
 *
 *    This test code creates a vertical white bar on the screen
 *    in the direction of where the user hears a sound.
 */

#define F_CPU 16000000
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
bool sound_to_vbar(int threshold);
void SPI_write(char address, char byte);
char SPI_read(char address);
void Initialize_ADC0(void);
void Initialize_ADC1(void);
int GetSound(int mic, int samples);
void reset();
// ========== End of Define ============
