#include <vector>

class Condition {

public:

	Condition();
	//~Condition();
	Condition(bool(*func)(std::vector<int>));
	Condition(const Condition &);

	bool is_true();
	void update_variables(std::vector<int>);

private:

	bool(*function)(std::vector<int>);
	
	std::vector<int> variables;

};