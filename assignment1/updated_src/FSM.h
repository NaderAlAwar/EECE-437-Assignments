#ifndef FSM_H
#define FSM_H

#include "State.h"
#include "Transition.h"
#include "Port.h"
#include <vector>


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
	FSM(const States &, const State &, const Transitions &, const std::vector<int> &);
												
	void print_ports();
	void print_states();
	void draw_FSM();

	/**
	 * @brief Runs the FSM t times

	 * 
	 * @param t [description]
	 * @param l [description]
	 */
	void run(int, bool t = false);
	void reset(const State &);

	State initial_state, current_state;


private:
	States *states;
	Transitions transitions;
	std::vector<int> variables;
	std::vector<Port> ports;
	int steps;
};

#endif

