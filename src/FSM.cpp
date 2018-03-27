#include "FSM.h"
#include <stdlib.h>
#include <time.h>

FSM::FSM(const std::vector<State> & newStates, const State & start, 
	const std::vector<Transition> & newTrans, const std::vector<int> & newVars) {
	myStates = newStates;
	startState = start;
	myTransitions = newTrans;
	myVariables = newVars;	

	for (std::vector<Transition>::iterator it = myTransitions.begin(); it != myTransitions.end(); ++it) {
		it->updateActionVariables(newVars);
	}
	currentState = startState;
	steps = 0;
}

// void FSM::printPorts() {
// 	std::cout << "The Ports are:" << std::endl;
// 	for (std::vector<Transition>::iterator it = myTransitions.begin(); it != myTransitions.end(); ++it) {
// 		std::cout << "Port " << it->getPort() << " is ";
// 		if (it->isPortEnabled())
// 			std::cout << "enabled" << std::endl;
// 		else
// 			std::cout << "disabled" << std::endl;
// 	}
		
// }



void FSM::printStates() {
	std::cout << "The states are: " << std::endl;
	for (std::vector<State>::iterator it = myStates.begin(); it != myStates.end(); ++it) {
		std::cout << it->getValue() << std::endl;
	}
}

void FSM::run(int time) {

	bool found = false;
	while (steps <= time) {		
		for (std::vector<Transition>::iterator it = myTransitions.begin(); it != myTransitions.end(); ++it) {		//check start state of each transition
			if (it->getStartState().getValue().compare(currentState.getValue()) == 0) {				//if current state is equal to start state of this transition
				if (it->evaluateCondition()) {						//if the transition succeeds
					it->getAction()->updateVariables(myVariables);
					std::cout << "Variables before: " << std::endl;
					for (int i = 0; i < myVariables.size(); i++)
						std::cout << myVariables[i] << " ";
					std::cout << std::endl;
					std::cout << "Moved from " << currentState.getValue() << " to " << it->getEndState().getValue() << std::endl;
					myVariables = it->getAction()->executeAction();			//new variables after executing the action
					it->getAction()->updateVariables(myVariables);
					currentState = it->getEndState();						//new current state					
					std::cout << "Variables after: " << std::endl;
					for (int i = 0; i < myVariables.size(); i++)
						std::cout << myVariables[i] << " ";
					std::cout << std::endl << std::endl;
					found = true;
					break;													//stop looking for transition
				}
			}
		}
	

		if (found == false) {
			std::cout << "No more transitions possible" << std::endl;
			break;
		}
		found = false;
		steps++;
	}
	std::cout << "Finished" << std::endl;
	steps = 0;
}

void FSM::reset(const State& newState) {
	startState = newState;
	currentState = newState;
}

State FSM::getCurrentState() {
	return currentState;
}


//TODO: implement execute function here: chooses a transition with source state equal to current state and executes it
bool FSM::execute(){
	for (auto it = myTransitions.begin(); it != myTransitions.end(); it++) {			//check start state of each transition
		if (it->getStartState().getValue().compare(currentState.getValue()) == 0) {		//if current state is equal to start state of this transition
			if (it->evaluateCondition()) {												//if the transition succeeds
				it->getAction()->updateVariables(myVariables);
				std::cout << "Variables before: " << std::endl;
				for (int i = 0; i < myVariables.size(); i++)
					std::cout << myVariables[i] << " ";
				std::cout << std::endl;
				std::cout << "Moved from " << currentState.getValue() << " to " << it->getEndState().getValue() << std::endl;
				myVariables = it->getAction()->executeAction();			//new variables after executing the action
				it->getAction()->updateVariables(myVariables);
				currentState = it->getEndState();						//new current state					
				std::cout << "Variables after: " << std::endl;
				for (int i = 0; i < myVariables.size(); i++)
					std::cout << myVariables[i] << " ";
				std::cout << std::endl << std::endl;
				return true;													//stop looking for transition
			}
		}
	}
	return false;
}

