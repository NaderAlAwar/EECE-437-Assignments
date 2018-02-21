#ifndef TRANSITIONS_H
#define TRANSITIONS_H

#include "Transition.h"

class Transitions {					//should add a data structure that holds several transitions
public:								//also create a copy constructor in order to help with FSM constructor (makes it easier)
	Transitions();
	~Transitions();
	void printTransitions();
private:
	Transition * transitions;		//array to hold transitions
};

#endif // !TRANSITIONS_H

