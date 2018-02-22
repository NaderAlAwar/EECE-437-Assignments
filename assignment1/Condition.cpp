#include "Condition.h"

Condition::Condition() {

}

//Condition::~Condition() {
//
//}

Condition::Condition(bool(*func)(std::vector<int>)) {
	function = func;
}

Condition::Condition(const Condition &newCondition) {
	function = newCondition.function;
	variables = newCondition.variables;
}


bool Condition::isTrue() {
	return function(variables);
}

void Condition::updateVariables(std::vector<int> inputs) {
	variables = inputs;
}