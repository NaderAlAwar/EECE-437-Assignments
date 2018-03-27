#include "Condition.h"

Condition::Condition() {
	
}

Condition::Condition(bool(*func)(std::vector<int>), std::vector<int> &vars) {
	function = func;
	variables = vars;
}	

 Condition::Condition(const Condition &newCondition) {
 	function = newCondition.function;
	variables = newCondition.variables;
 }


bool Condition::isTrue() {
	return function(variables);
}
