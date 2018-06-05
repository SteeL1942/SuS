#include "user/userthread.h"
#include <msp430.h>
#include "machine/system.h"
#include "machine/lcd.h"
#include "machine/buttons.h"

/* 512 Byte Stack */
DeclareThread(UserThread, userthread, 512);

void UserThread::action() {
	buttons.enable(buttons.UP);

  while (1) {
    /* Fuer 100ms schlafen legen, um Strom zu sparen */
    this->sleep(100);
  
    /* Watchdog anstossen */
    watchdog_reset();

    // Hier muesst ihr selbst Code ergaenzen
     //lcd.show_digit(1, 4,true); // Beispielsweiser LCD-Zugriff
     //lcd.show_number(12345,true);
     //lcd.show_char('e', 1,false);
     if(buttons.pressed(buttons.UP)) {
    	 lcd.show_number(123, true);
     }

  }
  // Achtung: Die action()-Methode darf nicht zurueckkehren,
  //          daher die Endlosschleife!
}
