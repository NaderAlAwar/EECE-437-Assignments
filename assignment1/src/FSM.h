

#include "States.h"
#include "Transition.h"
#include <vector>
#include "Port.h"


class FSM {

//same as assignment pdf. might need to add variables and ports to args.
//if not, then we should get them from inside the transitions
//when this constructor is called (and supposing we added variables to it), 
//the variables should be copied into each Action and Condition inside the transitions

public:

	//TODO: Generalize input variables to accept custom struct from user

	/**
	 *
	 * @brief FSM constructor, where the inputs are the ones mentioned in the mathematical 
	 * definition of an FSM to maximize generality in its usage.
	 *
	 *param[in] States Input states to FSM
	 *param[in] State Initial state
	 *param[in] Transitions Input transitions to FSM
	 *param[in] Variables Input variables (integers) to FSM
	 *
	 */
	FSM(const States &, const State &, const std::vector<Transition> &, const std::vector<int> &);
												
	void printPorts();
	void printStates();
	void drawFSM();
	void run(int);
	void reset(const State &);

private:
	States *myStates;
	std::vector<Transition> myTransitions;
	State startState, currentSate;
	std::vector<int> myVariables;
	std::vector<Port> myPorts;
	int steps;
};


