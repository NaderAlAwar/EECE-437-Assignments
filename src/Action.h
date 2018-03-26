#ifndef ACTION_H
#define ACTION_H
#include <vector>
class Action{
public:
	Action();
	//~Action();
	Action(void(*func)(std::vector<int> &));
	Action(const Action &);
	void printVariables();
	std::vector<int> executeAction();
	void updateVariables(std::vector<int>);			//this updates the variables in the Action object.
private:											//they then have to be copied back to the FSM
	void(*function)(std::vector<int> &);
	std::vector<int> variables;

};


#endif