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
	int  offset=0x20, x = 1;
	if(upper_line){
		if(pos == 1){
			x = 1;
		}else if(pos == 2){
			x = 2;
		}else if(pos == 3){
			x = 3;
		}else if(pos == 4){
			x = 5;
		}
		addr = LCD_BASE + offset + x ;
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
	}else{
		if(pos == 1){
			x = 11;
		}else if(pos == 2){
			x = 10;
		}else if(pos == 3){
			x = 9;
		}else if(pos == 4){
			x = 8;
		}else if(pos == 5){
			x = 7;
		}
		addr = LCD_BASE + offset + x ;
		switch (digit) {
			case 0 : *addr=0b01011101;break;
			case 1 : *addr=0b00000110;break;
			case 2 : *addr=0b01101011;break;
			case 3 : *addr=0b00101111;break;
			case 4 : *addr=0b00110110;break;
			case 5 : *addr=0b00111101;break;
			case 6 : *addr=0b01111101;break;
			case 7 : *addr=0b00000111;break;
			case 8 : *addr=0b01111111;break;
			case 9 : *addr=0b00111111;break;
			default : *addr=0b01011101;
		}
	}
}
void LCD::show_char(const char letter, unsigned int pos, bool upper_line){
	char *LCD_BASE = ( char *)0x0a00 ;
	char *addr ;
	int  offset=0x20, x = 1;
	if(upper_line){
		if(pos == 1){
			x = 1;
		}else if(pos == 2){
			x = 2;
		}else if(pos == 3){
			x = 3;
		}else if(pos == 4){
			x = 5;
		}
		addr = LCD_BASE + offset + x ;
		switch (letter) {
			case 'a' : *addr=0b01110111;break;
			case 'b' : *addr=0b11000111;break;
			case 'c' : *addr=0b10010101;break;
			case 'd' : *addr=0b11100110;break;
			case 'e' : *addr=0b10010111;break;
			case 'f' : *addr=0b00010111;break;
			case 'g' : *addr=0b11010101;break;
			case 'h' : *addr=0b01100111;break;
			case 'i' : *addr=0b00010100;break;
			case 'j' : *addr=0b11100100;break;
			case 'k' : *addr=0b01010111;break;
			case 'l' : *addr=0b10000101;break;
			case 'm' : *addr=0b01010110;break;
			case 'n' : *addr=0b01000110;break;
			case 'o' : *addr=0b11000110;break;
			case 'p' : *addr=0b00110111;break;
			case 'q' : *addr=0b01110011;break;
			case 'r' : *addr=0b00000110;break;
			case 's' : *addr=0b11010001;break;
			case 't' : *addr=0b10000111;break;
			case 'u' : *addr=0b11000100;break;
			case 'v' : *addr=0b10100001;break;
			case 'w' : *addr=0b10100011;break;
			case 'x' : *addr=0b01000100;break;
			case 'y' : *addr=0b11100011;break;
			case 'z' : *addr=0b10110100;break;
			default : *addr=0b00000000;
		}
	}else{
		if(pos == 1){
			x = 11;
		}else if(pos == 2){
			x = 10;
		}else if(pos == 3){
			x = 9;
		}else if(pos == 4){
			x = 8;
		}else if(pos == 5){
			x = 7;
		}
		addr = LCD_BASE + offset + x ;
		switch (letter) {
			case 'a' : *addr=0b01110111;break;
			case 'b' : *addr=0b01111100;break;
			case 'c' : *addr=0b01011001;break;
			case 'd' : *addr=0b01101110;break;
			case 'e' : *addr=0b01111001;break;
			case 'f' : *addr=0b01110001;break;
			case 'g' : *addr=0b01011101;break;
			case 'h' : *addr=0b01110110;break;
			case 'i' : *addr=0b01000001;break;
			case 'j' : *addr=0b01001110;break;
			case 'k' : *addr=0b01110101;break;
			case 'l' : *addr=0b01011000;break;
			case 'm' : *addr=0b01100101;break;
			case 'n' : *addr=0b01100100;break;
			case 'o' : *addr=0b01101100;break;
			case 'p' : *addr=0b01110011;break;
			case 'q' : *addr=0b00110111;break;
			case 'r' : *addr=0b01100000;break;
			case 's' : *addr=0b00011101;break;
			case 't' : *addr=0b01111000;break;
			case 'u' : *addr=0b01001100;break;
			case 'v' : *addr=0b00011010;break;
			case 'w' : *addr=0b00111010;break;
			case 'x' : *addr=0b01000100;break;
			case 'y' : *addr=0b00111110;break;
			case 'z' : *addr=0b01001011;break;
			default : *addr=0b00000000;
		}
	}
}


// Hier muesst ihr selbst Code ergaenzen, beispielsweise:
void LCD::show_number(long int number, bool upper_line) {
	if ((upper_line && number <= 9999) ) {
		int pos = 4;
		while ( ( number/10 != 0 || number % 10 != 0 ) && pos >= 1) {
			int mod = number % 10;
			number = number/10;

			show_digit(mod, pos, upper_line);
			--pos;
		}
	} else if((!upper_line && number <= 99999)){
		int pos = 5;
		while ( ( number/10 != 0 || number % 10 != 0 ) && pos >= 1) {
			int mod = number % 10;
			number = number/10;

			show_digit(mod, pos, upper_line);
			--pos;
		}
	}else{
		show_string("error", false);
	}
}

void LCD::show_string(const char *text, bool upper_line){
	int pos = 1;
	if(upper_line){
		while(pos <= 4){
			show_char(*text++, pos, upper_line);
			++pos;
		}
	}else{
		while(pos <= 5){
			show_char(*text++, pos, upper_line);
			++pos;
		}
	}
}




