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

int counter = 0;

void CounterThread::action(){
	while(1){
		inform.p();
		++counter;
		lcd.show_number(counter, false);
	}
}

