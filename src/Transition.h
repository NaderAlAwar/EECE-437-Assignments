#ifndef TRANSITION_H
#define TRANSITION_H
#include "State.h"
#include "Action.h"
#include "Condition.h"
#include <iostream>


class Port;

class Transition {					//overload + operator. Summing transitions up should return an object of clas Transitions
public:
	Transition();
	//~Transition();
	Transition(const State &, const State &, const Port *, Condition &, const Action &);
	void printMembers();

	void updateActionVariables(std::vector<int>);
	
	State getStartState();
	State getEndState();

	Action *getAction();
	
	bool evaluateCondition();
	
	std::vector<Transition> operator+(Transition rhs) {
		std::vector<Transition> answer{ *this,rhs };
		return answer;
	}
	friend std::vector<Transition> operator+(std::vector<Transition> lhs, Transition rhs) {
		lhs.push_back(rhs);
		return lhs;
	}

	// Made public so ports can access
	State startState, endState;

private:
	const Port *port;
	Condition condition;
	Action action;
};


#endif
