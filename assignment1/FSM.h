#ifndef FSM_H
#define FSM_H

#include "States.h"
#include "Transitions.h"


class FSM {
public:
	FSM();
	~FSM();
	FSM(const States &, const State &, const Transitions &);			//same as assignment pdf. might need to add variables and ports to args.
																		//if not, then we should get them from inside the transitions
																		//when this constructor is called (and supposing we added variables to it), 
																		//the variables should be copied into each Action and Condition inside the transitions
	void printPorts();
	void printStates();
	void drawFSM();
	void run(int);
	void reset(const state &);

private:
	States * states;
	Transitions * transitions;
};

#endif // !FSM_H

