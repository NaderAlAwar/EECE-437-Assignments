#ifndef FSM_H
#define FSM_H

#include "State.h"
#include "Transition.h"
#include <vector>
#include "Port.h"


class FSM {
public:
	//FSM();
	//~FSM();
	FSM(const std::vector<State> &, const State &, const std::vector<Transition> &, const std::vector<int> &);
												//same as assignment pdf. might need to add variables and ports to args.
												//if not, then we should get them from inside the transitions
												//when this constructor is called (and supposing we added variables to it), 
												//the variables should be copied into each Action and Condition inside the transitions
	void printPorts();
	void printStates();
	void drawFSM();
	void run(int);
	void reset(const State &);

private:
	std::vector<State> myStates;
	std::vector<Transition> myTransitions;
	State startState, currentSate;
	std::vector<int> myVariables;
	std::vector<Port> myPorts;
	int steps;
};

#endif // !FSM_H

