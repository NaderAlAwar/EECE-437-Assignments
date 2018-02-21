#ifndef STATES_H
#define STATES_H

#include "State.h"
class States {				//should add a data structure that can hold several states
public:						//also create a copy constructor in order to help with FSM constructor (makes it easier)
	States();
	~States();
	void printStates();
private:
	State * states;			//array to hold states

};

#endif
