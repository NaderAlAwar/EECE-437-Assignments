#include "Interaction.h"

Interaction::Interaction(std::vector<Port> *ports_input, Condition *c, Action *a){

	ports = ports_input;
	condition = c;
	action = a;

}

bool Interaction::isEnabled(){

	// Check whether or not all the ports are enabled
	bool ports_enabled = true;
	for(auto i:*ports){
		if(! (i.isEnabled())) return false;
	}

	if(ports_enabled && condition->isTrue()){
		action->executeAction();
		return true;
	}else{
		return false;
	}

}

void Interaction::execute(){

	for(auto i:*ports){
		i.execute();
	}

}

	

