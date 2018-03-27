#include "Port.h"

Port::Port()
{
	enabled = true;
}


Port::Port(bool status, std::string input) {
	enabled = status;
	value = input;
}

Port::Port(const Port &newPort) {
	enabled = newPort.enabled;
	value = newPort.value;
}

void Port::setFSM(FSM* newFSM) {
	f = newFSM;
}

//TODO: complete port isEnabled function
bool Port::isEnabled() {
	std::cout<<"-1.1.1:Checking ports from port class"<<std::endl;
	
	//TODO: ERROR IS IN THIS NEXT LINE REFERENCING F
	//std::cout<<f->getCurrentState().getValue()<<std::endl;

	// for(auto i = f->myTransitions.begin(); i != f->myTransitions.end(); i++){
	// 	if (i->getStartState().getValue() == f->getCurrentState().getValue()) {				//compare start state of transition to current state of FSM
	// 		std::cout<<"-1.1.2:Found valid transition in port class"<<std::endl;
	// 		return true;
	// 	}
	// }
	return false;
}

// void Port::enable() {
// 	enabled = true;
// }

// void Port::disable() {
// 	enabled = false;
// }


bool Port::execute(){
	if(isEnabled()){
		return f->execute();
	}
	return false;
}

std::string Port::getValue() {
	return value;
}