#include <iostream>
#include "Port.h"
#include "State.h"
#include <string>
#include <vector>
#include "Condition.h"
#include "Action.h"
#include "Transition.h"

using namespace std;

bool lessThan10(vector<int> input) {
	return input[0] < 10;
}

void add5(vector<int> &input) {
	input[0] = input[0] + 5;
}

int main() {
	string temp = "lol";
	State test(temp);
	cout << test.getValue();
	test.setValue("nice");
	cout << test.getValue() << endl;
	vector<int> input{ 1 };
	Condition l10(lessThan10);
	l10.updateVariables(input);
	cout << "condition less than 10" << l10.isTrue() << endl;
	
	cout << "before action " << input[0] << endl;
	Action a5(add5);
	a5.updateVariables(input);
	a5.printVariables();
	a5.executeAction();
	a5.printVariables();

	State red("red");
	State green("green");
	Port go(true);
	Transition t1(red, green, go, l10, a5);
	t1.printMembers();
	cout << "attempting transition (1 if successful 0 if not) " << t1.attemptTransition() << endl;
	t1.disablePort();
	t1.printMembers();
	cout << "attempting transition (1 if successful 0 if not) " << t1.attemptTransition() << endl;
	return 0;
}