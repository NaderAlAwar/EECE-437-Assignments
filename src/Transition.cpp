#include "Transition.h"
#include <iostream>


Transition::Transition() {
	startState, endState, condition, action, port = NULL;
}

Transition::Transition(const State &start, const State &end, const Port *attachedPort, Condition &argCondition, const Action &argAction) {
	startState = start;
	endState = end;
	condition = argCondition;
	action = argAction;
	port = attachedPort;
}

bool Transition::evaluateCondition(){
	return condition.isTrue();
}

void Transition::printMembers() {
	std::cout << "start state is " << startState.getValue() << std::endl;
	std::cout << "end state is " << endState.getValue() << std::endl;
	std::cout << "condition is (1 if true 0 if false) " << condition.isTrue() << std::endl;
}

void Transition::updateActionVariables(std::vector<int> inputs) {
	action.updateVariables(inputs);
}

State Transition::getStartState() {
	return startState;
}

State Transition::getEndState() {
	return endState;
}

// Condition* Transition::getCondition() {
// 	return &condition;
// }

Action *Transition::getAction() {
	return &action;
}