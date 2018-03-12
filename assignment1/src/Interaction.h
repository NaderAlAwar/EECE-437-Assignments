#ifndef INTERACTION_H
#define INTERACTION_H

#include "Port.h"
#include "Condition.h"
#include "Action.h"

class Interaction{

public:
	Interaction();
	Interaction(Port *p1, Port *p2, Condition c, Action a);

	void attemptInteraction();



private:
	Port *port_1;
	Port *port_2;

	Condition condition;
	Action action;

};


#endif