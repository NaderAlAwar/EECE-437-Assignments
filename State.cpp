#include "State.h"


State::State() {
	value = "";
}


State::State(std::string input) {
	value = input;
}

State::State(const State &newState) {
	value = newState.value;
}

std::string State::getValue() {
	return value;
}

void State::setValue(std::string input) {
	value = input;
}