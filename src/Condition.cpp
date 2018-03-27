#include "Condition.h"

Condition::Condition(bool(*func)(std::vector<int>), std::vector<int> &vars) {
	function = func;
	variables = vars;
}	

//TODO: change copy constructor
// Condition::Condition(const Condition &newCondition) {
// 	function = newCondition.function;
// }


bool Condition::isTrue() {
	return function(variables);
}
