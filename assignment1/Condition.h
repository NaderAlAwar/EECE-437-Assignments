#ifndef CONDITION_H
#define CONDITION_H
#include <vector>
class Condition {
public:

	/**
	 * @brief Constructor takes as input a function pointer
	 * @param[in]  func  Function pointer
	 */
	Condition(bool (*func)(std::vector<int>));

	/**
	 * @brief Copy constructor
	 * @param n An instance of condition
	 */
	Condition(const Condition &);

	/**
	 * @brief Function that evaluates condition
	 * @details Evaluates condition and returns the result of that evaluation.
	 * @return Boolean
	 */
	bool isTrue();

	/**
	 * ???????????????
	 * 
	 * Maybe the variables were not of type int? i.e. multiple data types
	 */
	void updateVariables(std::vector<int>);

private:
	bool(*function)(std::vector<int>);
	std::vector<int> variables;

};


#endif