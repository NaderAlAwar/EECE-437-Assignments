#ifndef STATE_H
#define STATE_H
#include <string>
class State {						//overload + operator. Summing states up should return an object of clas States
public:
	State();
	~State();
	State(std::string const& input);
	State(const State &);
	std::string getValue();
	void setValue(std::string const& input);
private:
	std::string value;
};

State::State() {
	value = "";
}

State::~State() {
	delete &value;
}

State::State(std::string const& input) {
	value = input;
}

State::State(const State &newState) {
	value = newState.value;
}

std::string State::getValue() {
	return value;
}

void State::setValue(std::string const& input) {
	value = input;
}
#endif // !STATE_H

