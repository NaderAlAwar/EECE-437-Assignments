#ifndef TRANSITION_H
#define TRANSITION_H
#include "State.h"
#include "Port.h"
#include "Action.h"
#include "Condition.h"
#include <iostream>




class Transition {					//overload + operator. Summing transitions up should return an object of clas Transitions
public:
	Transition();
	//~Transition();
	Transition(const State &, const State &, const Port &, const Condition &, const Action &);
	bool attemptTransition();
	void printMembers();

	void updateConditionVariables(std::vector<int>);
	void updateActionVariables(std::vector<int>);
	
	State getStartState();
	State getEndState();
	
	bool evaluateCondition();
	
	std::string getPort();
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
	Port port;
	Condition condition;
	Action action;
};


#endif
