#include <iostream>
#include "State.h"

using namespace std;

int main(){

	State red = State("red");
	State green = State("green");

	States x = (red + green);

	cout<<"States: State 0:"<<x.states[0].get_value()<<endl;

	return 0;
}