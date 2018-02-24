#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <iostream>


/**
 * @brief Forward declaration of States
 */
class States;

/**
 * @brief State class
 */
class State{

public:

	State();
	State(std::string x);
	State(const State &n);

	States operator+(State x);

	std::string get_value();
	void set_value(std::string x);

private:

	std::string value;

};



class States{

public:
	States();
	States(const States &n);
	States(std::vector<State> n);

	void print_states();

	std::vector<State> states;

	States operator+(State x);
	States operator+(States y);
};

#endif
