#include "State.h"

/**
 * @brief Empty constructor
 * @details Initializes value with empty string
 */
State::State(){value = "";}

/**
 * @brief Constructor with a string argument
 * @details Fills in value with the string passed to the constructor
 * 
 * @param String Used to express state value
 */
State::State(std::string x){value = x;}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param n [description]
 */
State::State(const State &n){value = n.value;}

std::string State::get_value(){return value;}

void State::set_value(std::string n){value = n;}



States::States(){states = {};}

States::States(std::vector<State> x){this->states = x;}

States::States(const States &x){ this->states = x.states;}

States States::operator+(State n){states.push_back(n);}

States States::operator+(States x){
	for(auto i = x.states.begin(); i != x.states.end(); i++){
		states.push_back(*i);
	}
	return (*this);
}

void print_states(){
	for(int)
}




States State::operator+(State x){
	std::vector<State> temp;
	temp.push_back(*this);
	temp.push_back(x);
	return *(new States(temp));
}