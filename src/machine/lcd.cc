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


// Hier muesst ihr selbst Code ergaenzen, beispielsweise:
void LCD::show_number(long int number, bool upper_line) {
  // ... hier steht euer Code ...
}

