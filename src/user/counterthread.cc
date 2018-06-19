/*
 * counterthread.cc
 *
 *  Created on: 13.06.2018
 *      Author: weisse00
 */

#include <user/counterthread.h>
#include "machine/buttons.h"
#include "machine/lcd.h"

DeclareThread(CounterThread, counterthread, 256);
int y = 0;

int zustand = 0;

void CounterThread::action() {
	while(1){
		this->sleep(50);

	    lcd.show_string("clic", true);
		bool state = buttons.pressed(buttons.STAR);
		if (state) {
			this->sleep(50);
		    if(buttons.pressed(buttons.STAR) == state) {
		    	 y++;
		    	 zustand = 1;
		    	 lcd.show_number(y, false);
		    }
		}
	}
}


