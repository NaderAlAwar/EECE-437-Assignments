#ifndef TRANSITION_H
#define TRANSITION_H
#include "State.h"
#include "Port.h"
#include "Action.h"
#include "Condition.h"

class Transition {					//overload + operator. Summing transitions up should return an object of clas Transitions
public:
	Transition();
	~Transition();
	Transition(const State &, const State &, const Port &, const Condition &, const Action &);
	bool attemptTransition();
	void printMembers();
	void disablePort();
	void enablePort();
private:
	State startState, endState;
	Port port;
	Condition condition;
	Action action;
};

Transition::Transition() {

}

Transition::~Transition() {

}

Transition::Transition(const State &start, const State &end, const Port &argPort, const Condition &argCondition, const Action &argAction) {
	startState = start;
	endState = end;
	port = argPort;
	condition = argCondition;
	action = argAction;
}

bool Transition::attemptTransition() {
	if (port.isEnabled() && condition.isTrue()) {
		action.executeAction();
		return true;
	}
	return false;
}

void Transition::printMembers() {
	std::cout << "start state is " << startState.getValue() << std::endl;
	std::cout << "end state is " << endState.getValue() << std::endl;
	std::cout << "port is (1 if enabled 0 if disabled) " << port.isEnabled() << std::endl;
	std::cout << "condition is (1 if true 0 if false) " << condition.isTrue() << std::endl;
}

void Transition::disablePort() {
	port.disable();
}

void Transition::enablePort() {
	port.enable();
}
#endif
