#ifndef INTERACTION_H
#define INTERACTION_H

#include "Port.h"
#include "Condition.h"
#include "Action.h"
#include <vector>

class Interaction{

public:
	Interaction();
	Interaction(std::vector<Port*> *ports, Condition *c, Action *a);

	// Returns whether or not condition true and ports enabled
	bool isEnabled();

	bool execute();

private:

	std::vector<Port*> *ports;

	Condition *condition;
	Action *action;

};


#endif