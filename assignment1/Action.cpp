#include "Action.h"
#include <iostream>

Action::Action() {

}

//Action::~Action() {
//
//}

Action::Action(void(*func)(std::vector<int> &)) {
	function = func;
	variables = {};
}

Action::Action(const Action &newAction) {
	function = newAction.function;
	variables = newAction.variables;
}

std::vector<int> Action::executeAction() {
	function(variables);
	return variables;							//returns variables to FSM to update each condition and action
}

void Action::updateVariables(std::vector<int> inputs) {
	variables = inputs;
}

void Action::printVariables() {
	std::cout << "The variables in this Action are:" << std::endl;
	for (std::vector<int>::iterator it = variables.begin(); it != variables.end(); ++it)
		std::cout << *it << std::endl;
}