#include "Port.h"

Port::Port(){
	enabled = true;
}

Port::Port(bool s, std::string x){
	enabled = s;
	value = x;
}

Port::Port(const Port &x) {
	enabled = x.enabled;
	value = x.value;
}

bool Port::is_enabled() {
	return enabled;
}

void Port::enable() {
	enabled = true;
}

void Port::disable() {
	enabled = false;
}

std::string Port::get_value() {
	return value;
}