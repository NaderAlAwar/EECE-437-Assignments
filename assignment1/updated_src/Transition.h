#include "State.h"
#include "Port.h"
#include "Action.h"
#include "Condition.h"
#include <iostream>

/**
 * @brief Forward declaration of Transitions to use in Transition operator overloading
 */
class Transitions;

class Transition{
		
public:

	Transition();
	Transition(const State &, const State &, const Port &, const Condition &, const Action &);

	bool attempt_transition();
	
	void print_members();
	
	void disable_port();
	void enable_port();
	bool is_port_enabled();
	
	void update_condition_variables(std::vector<int>);
	void update_action_variables(std::vector<int>);

	State get_start_state();
	State get_end_state();

	Condition *get_condition();
	Action *get_action();

	std::string get_port();


};
