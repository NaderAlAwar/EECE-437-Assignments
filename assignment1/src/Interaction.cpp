#include "Interaction.h"

Interaction::Interaction(Port *p1, Port *p2, Condition &c, Action &a){

	port_1 = p1;
	port_2 = p2;

	condition = c;
	action = a;

}


void Interaction::attemptInteraction(){

	if(port_1->isEnabled() && port_2->isEnabled() && condition.isTrue()){
		action.executeAction();
	}

}

	

