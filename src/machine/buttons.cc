#include "buttons.h"
#include <msp430.h> // definiert Acronyme (Digital I/O Registers)

Buttons buttons; // Globales Buttons-Objekt

// Hier muesst ihr selbst Code ergaenzen

void Buttons::enable(uint8_t button_bitmap){
	P2DIR = P2DIR & ~button_bitmap;
	P2REN = P2REN | button_bitmap;
	P2OUT = P2OUT & ~button_bitmap;
}

uint8_t Buttons::read(){
	return P2IN;
}

bool Buttons::pressed(uint8_t button_bitmap){
	uint8_t actual = button_bitmap & read();
	return actual == button_bitmap;
}
