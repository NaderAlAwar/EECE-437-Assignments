#include "Interaction.h"

Interaction::Interaction(std::vector<Port> *ports_input, Condition *c, Action *a){

	ports = ports_input;
	condition = c;
	action = a;

}

bool Interaction::isEnabled(){

	// Check whether or not all the ports are enabled
	bool ports_enabled = true;
	std::cout<<"-1.1:Checking ports..."<<std::endl;
	for(auto i = ports->begin(); i != ports->end(); i++){
		if(! (i->isEnabled())) return false;
	}

	//std::cout<<"-1.2:Checking condition ..."<<std::endl;
	if(ports_enabled && condition->isTrue()){
		
		return true;

	}else{

		return false;
	}

}

bool Interaction::execute(){
	if (isEnabled()) {
		for (auto i : *ports) {
			i.execute();
		}
		std::cout<<"1: executed ports from interaction"<<std::endl;
		action->executeAction();
		std::cout<<"2: executed action from interaction"<<std::endl;
		return true;
	}
	return false;
}

	

