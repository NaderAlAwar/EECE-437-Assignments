#include "Interaction.h"
#include <iostream>
Interaction::Interaction(std::vector<Port> *ports_input, Condition *c, Action *a, const std::vector<int> & newVars){

	ports = ports_input;
	condition = c;
	action = a;
	myVariables = newVars;
}

bool Interaction::isEnabled(){

	// Check whether or not all the ports are enabled
	bool ports_enabled = true;
	for(std::vector<Port>::iterator it = ports->begin(); it != ports->end(); ++it){
		if(! (it->isEnabled())) return false;
	}

	if(ports_enabled && condition->isTrue()){

		return true;
	}else{
		return false;
	}

}

bool Interaction::execute(){
	if (isEnabled() == true) {
		std::cout << "Interaction is proceeding now:" << std::endl;
		for (std::vector<Port>::iterator it = ports->begin(); it != ports->end(); ++it) {
			it->execute();
		}
		std::cout << "Executing action of interaction:" << std::endl;
		std::cout << "Variables before: " << std::endl;
		for (int i = 0; i < myVariables.size(); i++)
			std::cout << myVariables[i] << " ";
		std::cout << std::endl;
		action->updateVariables(myVariables);
		action->executeAction();
		myVariables = action->executeAction();			//new variables after executing the action
		action->updateVariables(myVariables);
		std::cout << "Variables after: " << std::endl;
		for (int i = 0; i < myVariables.size(); i++)
			std::cout << myVariables[i] << " ";
		std::cout << std::endl << std::endl;
		return true;
	}
	return false;
}

	

