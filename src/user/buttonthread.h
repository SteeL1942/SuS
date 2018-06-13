#ifndef USER_BUTTONTHREAD_H_
#define USER_BUTTONTHREAD_H_

#include "syscall/thread.h"
#include "syscall/guarded_buzzer.h"

class ButtonThread: public Thread {
private:
	Guarded_Buzzer buzzer;

public:
	ButtonThread(void *tos) :
			Thread(tos) {
	}

	void action();

	// Diesen Thread fuer "ms" Millisekunden schlafen legen,
	// um Strom zu sparen.
	void sleep(unsigned int ms) {
		buzzer.set(ms);
		buzzer.sleep();
	}
};

extern ButtonThread buttonthread;


#endif /* USER_BUTTONTHREAD_H_ */



