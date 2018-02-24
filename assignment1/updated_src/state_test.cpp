#include <iostream>
#include "State.h"

using namespace std;

int main(){

	State red = State("red");
	State green = State("green");

	States x = (red + green);

	cout<<x.states[1].get_value()<<endl;

	x.print_states();

	return 0;
}