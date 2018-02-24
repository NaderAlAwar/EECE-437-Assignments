#include "Action.h"
#include <iostream>

Action::Action(){}

Action::Action(void(*func)(std::vector<int> &)) {
	function = func;
	variables = {};
}

Action::Action(const Action &newAction) {
	function = newAction.function;
	variables = newAction.variables;
}

std::vector<int> Action::execute_action() {
	function(variables);
	return variables; //!< 	Returns variables to FSM to update each condition and action
}

void Action::update_variables(std::vector<int> inputs) {
	variables = inputs;
}

void Action::print_variables() {
	std::cout << "The variables in this Action are: " << std::endl;
	for (std::vector<int>::iterator it = variables.begin(); it != variables.end(); ++it)
		std::cout << *it << std::endl;
}