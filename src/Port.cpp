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
	for(auto &i: f->myTransitions){
		if (i.getStartState().getValue().compare(f->getCurrentState().getValue()) == 0) {				//compare start state of transition to current state of FSM
			return true;
		}
	}
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