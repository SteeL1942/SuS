#ifndef USER_COUNTERTHREAD_H_
#define USER_COUNTERTHREAD_H_

#include "syscall/thread.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_semaphore.h"

//Guarded_Semaphore counter(0);

class CounterThread: public Thread {
private:
	Guarded_Buzzer buzzer;

public:
	CounterThread(void *tos) :
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

extern CounterThread counterthread;
extern Guarded_Semaphore inform;

#endif /* USER_COUNTERTHREAD_H_ */



