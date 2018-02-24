#include "Condition.h"

Condition::Condition() {}

Condition::Condition(bool(*func)(std::vector<int>)) {function = func;}

Condition::Condition(const Condition &newCondition) {
	function = newCondition.function;
	variables = newCondition.variables;
}


bool Condition::is_true() {return function(variables);}

void Condition::update_variables(std::vector<int> inputs) {variables = inputs;}