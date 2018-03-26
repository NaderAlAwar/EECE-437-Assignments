#include "Transitions.h"
#include <iostream>



Transitions::Transitions() {

}

//Transitions::~Transitions() {
//
//}

Transitions::Transitions(std::vector<Transition> inputs) {
	transitions = inputs;
}

Transitions::Transitions(const Transitions & newTransitions) {
	transitions = newTransitions.transitions;
}

void Transitions::printTransitions() {
	std::cout << "The Transitions contained are:" << std::endl;
	for (std::vector<Transition>::iterator it = transitions.begin(); it != transitions.end(); ++it)
		it->printMembers();
}

void Transitions::addTransition(const Transition &newTransition) {
	transitions.push_back(newTransition);
}

void Transitions::test() {

}
