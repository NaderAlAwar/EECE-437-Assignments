#ifndef FSM_H
#define FSM_H


#include "State.h"
#include <vector>
#include "Transition.h"

class Port; //forward declaration

class FSM {
public:
	
	FSM(const std::vector<State> &, const State &, const std::vector<Transition> &, 
		const std::vector<int> &);
												//same as assignment pdf. might need to add variables and ports to args.
												//if not, then we should get them from inside the transitions
												//when this constructor is called (and supposing we added variables to it), 
												//the variables should be copied into each Action and Condition inside the transitions
	// void printPorts();
	void printStates();
	void drawFSM();
	void run(int);
	void reset(const State &);

	//TODO: implement execute, which checks transitions and executes action if source state ...
	bool execute();

	// Providing access to ports
	State getCurrentState();
	std::vector<Transition> myTransitions;

private:
	State startState, currentSate;
	std::vector<State> myStates;
	std::vector<int> myVariables;
	int steps;
};

#endif // !FSM_H

