

#include <vector>
#include <string>


class States; 	//forward declaration of class States

#ifndef STATE_H
#define STATE_H

class State {						//overload + operator. Summing states up should return an object of clas States
public:

	State();
	//~State();
	State(std::string input);
	State(const State &);
	std::string getValue();
	void setValue(std::string input);

	States operator+(State addedState);
	
	friend std::vector<State> operator+(std::vector<State> lhs, State rhs) {
		lhs.push_back(rhs);
		return lhs;
	}

private:
	std::string value;
};

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

#ifndef STATES_H
#define STATES_H

class States {				//should add a data structure that can hold several states
public:						//also create a copy constructor in order to help with FSM constructor (makes it easier)
	
	States();
	States(std::vector<State> inputStates);
	States(const States &f);

	void printStates();

	std::vector<State> states;			//vector to hold states

	States operator+(State addedState);
	States operator+(States addedStates);

};

States::States(){
	states = {};
}

States State::operator+(State addedState){
	std::vector<State> temp;
	temp.push_back(*this);
	temp.push_back(addedState);
	return *(new States(temp));
} 

States::States(std::vector<State> inputStates){
	states = inputStates;
}

States::States(const States &f){
	states = f.states;
}

States States::operator+(State addedState){
	states.push_back(addedState);
}

States States::operator+(States addedStates){
	for(auto i = addedStates.states.begin(); i != addedStates.states.end(); i++){
		states.push_back(*i);
	}
	return (*this);
}

#endif


