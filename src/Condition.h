#ifndef CONDITION_H
#define CONDITION_H
#include <vector>
class Condition {
public:
	Condition();
	//~Condition();
	Condition(bool(*func)(std::vector<int>), std::vector<int> &vars);

	//TODO: change copy constructor
	Condition(const Condition &);

	bool isTrue();


private:
	bool(*function)(std::vector<int>);
	std::vector<int> variables;

};


#endif