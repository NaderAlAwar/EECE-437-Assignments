#include "Port.h"

Port::Port()
{
	enabled = true;
}

//Port::~Port()
//{
//}

Port::Port(bool status, std::string input) {
	enabled = status;
	value = input;
}

Port::Port(const Port &newPort) {
	enabled = newPort.enabled;
	value = newPort.value;
}

bool Port::isEnabled() {
	return enabled;
}

void Port::enable() {
	enabled = true;
}

void Port::disable() {
	enabled = false;
}

std::string Port::getValue() {
	return value;
}