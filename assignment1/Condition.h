#ifndef CONDITION_H
#define CONDITION_H
#include <vector>
class Condition {
public:
	Condition();
	//~Condition();
	Condition(bool(*func)(std::vector<int>));
	Condition(const Condition &);
	bool isTrue();
	void updateVariables(std::vector<int>);
private:
	bool(*function)(std::vector<int>);
	std::vector<int> variables;

};


#endif