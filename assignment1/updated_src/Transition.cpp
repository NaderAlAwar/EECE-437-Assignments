#include "Transition.h"
#include <iostream>


Transition::Transition() {}


Transition::Transition(const State &start, const State &end, const Port &arg_port, const Condition &arg_condition, const Action &arg_action) {
	start_state = start;
	end_state = end;
	port = arg_port;
	condition = arg_condition;
	action = arg_action;
}

bool Transition::attempt_transition() {
	if (port.is_enabled() && condition.is_true()) {
		return true;
	}
	return false;
}

void Transition::print_members() {
	std::cout << "start state is " << start_state.get_value() << std::endl;
	std::cout << "end state is " << end_state.get_value() << std::endl;
	std::cout << "port is (1 if enabled 0 if disabled) " << port.is_enabled() << std::endl;
	std::cout << "condition is (1 if true 0 if false) " << condition.is_true() << std::endl;
}

void Transition::disable_port() {
	port.disable();
}

void Transition::enable_port() {
	port.enable();
}

std::string Transition::get_port() {
	return port.get_value();
}

bool Transition::is_port_enabled() {
	return port.is_enabled();
}


void Transition::update_condition_variables(std::vector<int> inputs) {
	condition.update_variables(inputs);
}

void Transition::update_action_variables(std::vector<int> inputs) {
	action.update_variables(inputs);
}

State Transition::get_start_state() {return start_state;}

State Transition::get_end_state() {return end_state;}

Condition* Transition::get_condition() {return &condition;}

Action *Transition::get_action() {return &action;}


Transitions::Transitions(){transitions = {};}

Transitions::Transitions(std::vector<Transition> x){this->transitions = x;}

Transitions::Transitions(const Transitions &x){this->transitions = x.transitions;}


Transitions Transition::operator+(Transition t){
	std::vector<Transition> temp;
	temp.push_back(*this);
	temp.push_back(t);
	return *(new Transitions(temp));
}

Transitions Transitions::operator+(Transition n){transitions.push_back(n);}

Transitions Transitions::operator+(Transitions x){
	for(auto i = x.transitions.begin(); i!= x.transitions.end(); i++){
		transitions.push_back(*i);
	}
	return (*this);
}


