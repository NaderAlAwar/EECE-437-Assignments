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
 * @brief Copy constructor
 */
State::State(const State &n){value = n.value;}

/**
 * @brief Returns value of private member value
 * @return State.value
 */
std::string State::get_value(){return value;}

/**
 * @brief Sets value of private member value
 * @param String State.value
 */
void State::set_value(std::string n){value = n;}

/**
 * @brief 
 * @details [long description]
 */
States::States(){states = {};}

/**
 * @brief Constructing empty State objecstss
 * 
 * @param x [description]
 */

States::States(std::vector<State> x){this->states = x;}

/**
 * @brief Copy constructor
 */
States::States(const States &x){ this->states = x.states;}

/**
 * @brief Overloading + operator to add State objects to States objects
 * 
 * @param State
 * @return States
 */
States States::operator+(State n){states.push_back(n);}

/**
 * @brief Overloading + operator to add States objects. Simply concatenates two vectors of State objects
 * @param States 
 * @return States
 */
States States::operator+(States x){
	for(auto i = x.states.begin(); i != x.states.end(); i++){
		states.push_back(*i);
	}
	return (*this);
}

/**
 * @brief Prints all individual State values inside States object
 */
void States::print_states(){
	int k = 0;
	for(auto i = states.begin(); i != states.end(); i++, k++){
		std::cout<<"s"<<k<<": "<<i->get_value()<<(i!=states.end()-1?" - ":"");
	}std::cout<<std::endl;
}

/**
 * @brief Overloading + operator to be able to add State objects
 * @details Addition of State objects is simply concatenating the two objects in a vector and
 * returning a States object with this concatenation as its states vector
 * 
 * @param State 
 * @return States 
 */
States State::operator+(State x){
	std::vector<State> temp;
	temp.push_back(*this);
	temp.push_back(x);
	return *(new States(temp));


}


