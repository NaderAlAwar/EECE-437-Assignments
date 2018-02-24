#include "FSM.h"

FSM::FSM(const States & new_states, const State & start_state, const Transitions & new_transitions, const std::vector<int> & new_variables) {
	
	states = new States(new_states);
	initial_state = start_state;
	transitions = new_transitions;
	variables = new_variables;	

	for (std::vector<Transition>::iterator it = transitions.transitions.begin(); it != transitions.transitions.end(); it++) {
		it->update_action_variables(new_variables);
		it->update_condition_variables(new_variables);
	}

	current_state = initial_state;
	steps = 0;
}

void FSM::print_ports() {
	std::cout << "The Ports are:" << std::endl;
	for (std::vector<Transition>::iterator it = transitions.transitions.begin(); it != transitions.transitions.end(); ++it) {
		std::cout << "Port " << it->get_port() << " is ";
		if (it->is_port_enabled())
			std::cout << "enabled" << std::endl;
		else
			std::cout << "disabled" << std::endl;
	}
		
}

void FSM::print_states() {
	std::cout << "The states are: " << std::endl;
	for (std::vector<State>::iterator it = states->states.begin(); it != states->states.end(); ++it) {
		std::cout << it->get_value() << std::endl;
	}
}

void FSM::run(int time, bool t = false) {
	bool found = false;
	while (steps <= time) {		
		for (std::vector<Transition>::iterator it = transitions.transitions.begin(); it != transitions.transitions.end(); ++it) {		//check start state of each transition
			
			if (it->get_start_state().get_value().compare(current_state.get_value()) == 0) {				//if current state is equal to start state of this transition
			
				it->get_condition()->update_variables(variables);
				
				if (it->attempt_transition() == true) {						//if the transition succeeds
					
					it->get_action()->update_variables(variables);
					
					for (int i = 0; i < variables.size(); i++)
						std::cout << variables[i] << " ";
			
					std::cout << std::endl;
			
					if(t) std::cout << "Moved from " << current_state.get_value() << " to " << it->get_end_state().get_value() << std::endl;
			
					variables = it->get_action()->execute_action();			//new variables after executing the action
			
					it->get_action()->update_variables(variables);
			
					current_state = it->get_end_state();						//new current state					
					
					for (int i = 0; i < variables.size(); i++)
						std::cout << variables[i] << " ";
			
					std::cout << std::endl << std::endl;
					
					found = true;
					break;													//stop looking for transition
				}
			}
		}
		for (std::vector<Transition>::iterator it = transitions.transitions.begin(); it != transitions.transitions.end(); ++it) {	//update each condition
			it->get_condition()->update_variables(variables);													//every transition
		}

		if (found == false) {
			std::cout << "No more transitions possible" << std::endl;
			break;
		}
		found = false;
		steps++;
	}
	std::cout << "Finished" << std::endl;
	steps = 0;
}

void FSM::draw_FSM(){
	run(1, true);
}

void FSM::reset(const State& n) {
	initial_state = n;
	current_state = n;
}

