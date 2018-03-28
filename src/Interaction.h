#ifndef INTERACTION_H
#define INTERACTION_H

#include "Port.h"
#include "Condition.h"
#include "Action.h"
#include <vector>

class Interaction{

public:
	Interaction();
	Interaction(std::vector<Port> *ports, Condition *c, Action *a, const std::vector<int> & newVars);

	// Attempts interaction and returns boolean to represent result of attempt
	bool attemptInteraction();

	// Returns whether or not condition true and ports enabled
	bool isEnabled();

	bool execute();
	std::vector<Port> *ports;
private:

	
	std::vector<int> myVariables;
	Condition *condition;
	Action *action;

};


#endif