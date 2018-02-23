// #include <iostream>
// #include "Port.h"
// #include "States.h"
// #include <string>
// #include <vector>
// #include "Condition.h"
// #include "Action.h"
// #include "Transition.h"
// #include "Transitions.h"
// #include "FSM.h"

// using namespace std;

// bool l10(vector<int> input) {
// 	return input[0] < 10;
// }

// bool e10(vector<int> input) {
// 	return input[0] == 10;
// }

// bool l5(vector<int> input) {
// 	return input[0] < 5;
// }

// bool e5(vector<int> input) {
// 	return input[0] == 5;
// }

// void iT(vector<int> &input) {
// 	input[0]++;
// }

// void rT(vector<int> &input) {
// 	input[0] = 0;
// }

int main() {

// 	string temp = "state 1";
// 	State test(temp);
// 	cout << test.getValue();
// 	test.setValue("state 1 updated");
// 	cout << test.getValue() << endl;
// 	vector<int> input{ 1, 5 };
// 	Condition lessThan10(l10);
// 	lessThan10.updateVariables(input);
// 	cout << "Condition less than 10 is " << (lessThan10.isTrue()?"true":"false")<< endl;
	
// 	cout << "Before applying action, input[0] is " << input[0] << endl;
// 	Action a5(iT);
// 	a5.updateVariables(input);
// 	a5.printVariables();
// 	a5.executeAction();
// 	a5.printVariables();

// 	State red("red");
// 	State green("green");
// 	Port go(true, "go");
// 	Transition test1(red, green, go, lessThan10, a5);
// 	test1.printMembers();
// 	cout << "attempting transition (1 if successful 0 if not) " << test1.attemptTransition() << endl;
// 	test1.disablePort();
// 	test1.printMembers();
// 	cout << "attempting transition (1 if successful 0 if not) " << test1.attemptTransition() << endl;

// 	Transition test2(green, red, go, l10, a5);	
// 	Transition test3(green, red, go, l10, a5);
// 	vector<Transition> group = test1 + test2 + test3;
// 	State yellow("yellow");
// 	States newgroup = red + yellow + green;
// 	vector<int> vars{ 1,2,3 };

// 	Condition equals10(e10);
// 	Action incrementT(iT);
// 	Condition lessThan5(l5);
// 	Condition equals5(e5);
// 	Action resetT(rT);
// 	Port increment(true, "increment");
// 	Port reset(true, "reset");

// 	Transition t1(red, red, increment, lessThan10, incrementT);
// 	Transition t2(red, green, reset, equals10, incrementT);
// 	Transition t3(green, green, increment, lessThan10, incrementT);
// 	Transition t4(green, yellow, reset, equals10, incrementT);
// 	Transition t5(yellow, yellow, increment, lessThan5, incrementT);
// 	Transition t6(yellow, red, reset, equals5, resetT);

// 	group = t1 + t2 + t3 + t4 + t5 + t6;

// 	FSM m(newgroup, red, group, vars);
// 	m.printPorts();
// 	m.printStates();
// 	m.run(1);
// 	m.reset(green);
// 	m.run(1);

// 	int a;
// 	cin >> a;
	return 0;
}