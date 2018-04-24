/*
 * lcd.cc
 *
 * Objekt zur grundlegenden Ansteuerung des LCDs der Chronos-Uhr
 *
 * Kann im Augenblick nur initialisieren (im Konstruktor) und
 * alle Segmente ausschalten.
 */

#include <msp430.h>
#include "machine/lcd.h"

LCD lcd; // Globales LCD-Objekt

LCD::LCD() {
  // Display-Speicher loeschen
  LCDBMEMCTL |= LCDCLRBM | LCDCLRM;

  // LCD_FREQ = ACLK/16/8 = 256Hz
  // Framefrequenz = 256Hz/4 = 64Hz, LCD mux 4, LCD on
  LCDBCTL0 = LCDDIV_15 | LCDPRE__8 | LCD4MUX | LCDON;

  // Blinkfrequenz = ACLK/8/4096 = 1Hz
  LCDBBLKCTL = LCDBLKPRE0 | LCDBLKPRE1 |
               LCDBLKDIV0 | LCDBLKDIV1 | LCDBLKDIV2 | LCDBLKMOD0;

  // I/O to COM outputs
  P5SEL |= (BIT5 | BIT6 | BIT7);
  P5DIR |= (BIT5 | BIT6 | BIT7);

  // LCD-Ausgabe aktivieren
  LCDBPCTL0 = 0xFFFF;
  LCDBPCTL1 = 0xFF;
}

void LCD::clear() { LCDBMEMCTL |= LCDCLRBM | LCDCLRM; }

void LCD::show_digit(unsigned int digit, unsigned int pos, bool upper_line){
	char *LCD_BASE = ( char *)0x0a00 ;
	char *addr ;
	int  offset=0x20 ,  x=1;
	addr = LCD_BASE + offset + x ;
	digit = 9;
	switch (digit) {
	case 0 : *addr=0b11110101;break;
	case 1 : *addr=0b01100000;break;
	case 2 : *addr=0b10110110;break;
	case 3 : *addr=0b11110010;break;
	case 4 : *addr=0b01100011;break;
	case 5 : *addr=0b11010011;break;
	case 6 : *addr=0b11010111;break;
	case 7 : *addr=0b01110000;break;
	case 8 : *addr=0b11110111;break;
	case 9 : *addr=0b11110011;break;
	default : *addr=0b11110101;
	}

}


// Hier muesst ihr selbst Code ergaenzen, beispielsweise:
void LCD::show_number(long int number, bool upper_line) {
  // ... hier steht euer Code ...
}

