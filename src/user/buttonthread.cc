/*
 * buttonthread.cc
 *
 *  Created on: 13.06.2018
 *      Author: weisse00
 */

#include <user/buttonthread.h>
#include "machine/buttons.h"
#include "machine/lcd.h"

DeclareThread(ButtonThread, buttonthread, 256);

void ButtonThread::action() {
	while(1){
		this->sleep(50);

	    lcd.show_string("clic", true);
		bool state = buttons.pressed(buttons.STAR);
		if (state) {
			this->sleep(50);
		    if(buttons.pressed(buttons.STAR) == state) {
		    	 inform.v();
		    }
		}
	}
}
