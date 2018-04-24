#include "user/userthread.h"
#include <msp430.h>
#include "machine/system.h"
#include "machine/lcd.h"

/* 512 Byte Stack */
DeclareThread(UserThread, userthread, 512);

void UserThread::action() {
  while (1) {
    /* Fuer 100ms schlafen legen, um Strom zu sparen */
    this->sleep(100);
  
    /* Watchdog anstossen */
    watchdog_reset();

    // Hier muesst ihr selbst Code ergaenzen
    // lcd.show_digit(1, 1); // Beispielsweiser LCD-Zugriff
  }
  // Achtung: Die action()-Methode darf nicht zurueckkehren,
  //          daher die Endlosschleife!
}
