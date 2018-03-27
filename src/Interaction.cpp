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
		
		return true;
	}else{
		return false;
	}

}

bool Interaction::execute(){
	if (isEnabled() == true) {
		for (auto i : *ports) {
			i.execute();
		}
		action->executeAction();
		return true;
	}
	return false;
}

	

