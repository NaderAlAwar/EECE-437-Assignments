#ifndef ACTION_H
#define ACTION_H
#include <vector>
class Action{

public:

	Action(void(*func)(std::vector<int> &));
	Action(const Action &);

	void printVariables();
	void executeAction();
	void updateVariables(std::vector<int>);			//this updates the variables in the Action object.
private:											//they then have to be copied back to the FSM
	void(*function)(std::vector<int> &);
	std::vector<int> variables;

};


/**
 * @brief Action constructor, takes a function pointer as an argument
 * 
 * @param c Function pointer to the function that performs an action on the FSM variables.
 */
Action::Action(void (*func)(std::vector<int>&)) {
	function = func;
}

Action::Action(const Action &newAction) {
	function = newAction.function;
	variables = newAction.variables;
}

void Action::executeAction() {
	function(variables);
}

void Action::updateVariables(std::vector<int> inputs) {
	variables = inputs;
}

void Action::printVariables() {
	std::cout << "The variables in this Action are:" << std::endl;
	for (std::vector<int>::iterator it = variables.begin(); it != variables.end(); ++it)
		std::cout << *it << std::endl;
}
#endif