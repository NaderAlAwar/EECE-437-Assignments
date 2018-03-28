#include <iostream>
#include "Port.h"
#include "State.h"
#include <string>
#include <vector>
#include "Condition.h"
#include "Action.h"
#include "Transition.h"
#include "Transitions.h"
#include "States.h"
#include "FSM.h"
#include "Interaction.h"
#include "System.h"

using namespace std;

bool l10(vector<int> input) {
	return input[0] < 10;
}

bool e10(vector<int> input) {
	return input[0] == 10;
}

bool l5(vector<int> input) {
	return input[0] < 5;
}

bool e5(vector<int> input) {
	return input[0] == 5;
}

void iT(vector<int> &input) {
	input[0]++;
}

void rT(vector<int> &input) {
	input[0] = 0;
}

void interactionAction(vector<int> &input) {
	input[0] = 32;
}

int main() {
	string temp = "lol";
	State test(temp);
	cout << test.getValue();
	test.setValue("nice");
	cout << test.getValue() << endl;
	vector<int> input{ 1 };

	Condition lessThan10(l10, input);
	cout << "condition less than 10" << lessThan10.isTrue() << endl;
	
	cout << "before action " << input[0] << endl;
	Action a5(iT);
	a5.updateVariables(input);
	a5.printVariables();
	a5.executeAction();
	a5.printVariables();

	State red("red");
	State green("green");
	Port go(true, "go");
	Transition test1(red, green, &go, lessThan10, a5);
	
	Transition test2(green, red, &go, lessThan10, a5);	
	Transition test3(green, red, &go, lessThan10, a5);
	vector<Transition> group = test1 + test2 + test3;
	State yellow("yellow");
	vector<State> newgroup = red + yellow + green;
	vector<int> vars{ 1,2,3 };

	Condition equals10(e10, vars);
	Action incrementT(iT);
	Condition lessThan5(l5, vars);
	Condition equals5(e5, vars);
	Action resetT(rT);
	Port increment(true, "increment");
	Port reset(true, "reset");

	Transition t1(red, red, &increment, lessThan10, incrementT);
	Transition t2(red, green, &reset, equals10, incrementT);
	Transition t3(green, green, &increment, lessThan10, incrementT);
	Transition t4(green, yellow, &reset, equals10, incrementT);
	Transition t5(yellow, yellow, &increment, lessThan5, incrementT);
	Transition t6(yellow, red, &reset, equals5, resetT);

	group = t1 + t2 + t3 + t4 + t5 + t6;

	std::vector<Port> ports = {increment, reset};

	FSM m(newgroup, red, group, vars);
	m.printStates();
	m.run(1);
	m.reset(green);
	m.run(1);

	Condition testing1(l10, input);
	Condition testing2(testing1);
	cout << "condition testing1:" << testing1.isTrue() << endl;
	cout << "condition testing2:" << testing2.isTrue() << endl;
	int a;

	cout << "************************************************" << endl;
	cout << "********** NOW TESTING SYSTEM ******************" << endl;

	vector<int> newFSMvars{ 4, 5, 6 };
	Condition intCondition(l10, newFSMvars);
	Action intAction(interactionAction);
	State yellowState("yellow");
	State blueState("blue");
	Transition ytob(yellowState, blueState, &increment, lessThan10, incrementT);
	Transition btoy(blueState, yellowState, &increment, lessThan10, incrementT);
	vector<Transition> newTransitions = ytob + btoy;
	vector<State> newStates = yellowState + blueState;

	FSM n(newStates, yellowState, newTransitions, newFSMvars);


	Port newp1(true, "for fsm m");
	Port newp2(true, "for fsm n");

	vector<Port> interactionPorts;
	interactionPorts.push_back(newp1);										
	interactionPorts.push_back(newp2);
	interactionPorts.at(0).setFSM(&m);
	interactionPorts.at(1).setFSM(&n);

	vector<int> intVars{ 7,8,9 };
	Interaction I1(&interactionPorts, &intCondition, &intAction, intVars);

	vector<Interaction> interactions;
	interactions.push_back(I1);
	System s1(interactions);

	s1.execute();

	

	cin >> a;
	return 0;
}