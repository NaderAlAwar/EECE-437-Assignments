#include "Transition.h"
#include <iostream>


Transition::Transition(const State &start, const State &end, const Port &argPort, const Condition &argCondition, const Action &argAction) {
	startState = start;
	endState = end;
	port = argPort;
	condition = argCondition;
	action = argAction;
}

bool Transition::evaluateCondition(){
	return condition.isTrue();
}


void Transition::printMembers() {
	std::cout << "start state is " << startState.getValue() << std::endl;
	std::cout << "end state is " << endState.getValue() << std::endl;
	std::cout << "port is (1 if enabled 0 if disabled) " << port.isEnabled() << std::endl;
	std::cout << "condition is (1 if true 0 if false) " << condition.isTrue() << std::endl;
}

// void Transition::disablePort() {
// 	port.disable();
// }

// void Transition::enablePort() {
// 	port.enable();
// }

// std::string Transition::getPort() {
// 	return port.getValue();
// }

// bool Transition::isPortEnabled() {
// 	return port.isEnabled();
// }

void Transition::updateConditionVariables(std::vector<int> inputs) {
	condition.updateVariables(inputs);
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

Condition* Transition::getCondition() {
	return &condition;
}

Action *Transition::getAction() {
	return &action;
}