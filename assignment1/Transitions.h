#ifndef TRANSITIONS_H
#define TRANSITIONS_H

#include "Transition.h"
#include <vector>

class Transition;

class Transitions {					//should add a data structure that holds several transitions
public:								//also create a copy constructor in order to help with FSM constructor (makes it easier)
	Transitions();
	//~Transitions();
	Transitions(std::vector<Transition>);
	Transitions(const Transitions &);
	void printTransitions();
	void addTransition(const Transition &);
	void test();
	friend Transitions operator+(Transitions &lhs, const Transition &rhs) {
		lhs.addTransition(rhs);
		return lhs;
	};
private:
	std::vector<Transition> transitions;	//vector to hold transitions

};


#endif // !TRANSITIONS_H

