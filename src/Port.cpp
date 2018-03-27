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

//TODO: complete port isEnabled function
bool Port::isEnabled() {
	for(auto &i: f->myTransitions){

	}
}

// void Port::enable() {
// 	enabled = true;
// }

// void Port::disable() {
// 	enabled = false;
// }


bool Port::execute(){
	if(isEnabled()){
		f->execute();
	}
}

std::string Port::getValue() {
	return value;
}