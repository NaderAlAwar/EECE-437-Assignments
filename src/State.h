#ifndef STATE_H
#define STATE_H
#include <string>
#include <vector>
class State {						//overload + operator. Summing states up should return an object of clas States
public:
	State();
	//~State();
	State(std::string input);
	State(const State &);
	std::string getValue();
	void setValue(std::string input);
	std::vector<State> operator+(State rhs) {
		std::vector<State> answer{ *this,rhs };
		return answer;
	}
	friend std::vector<State> operator+(std::vector<State> lhs, State rhs) {
		lhs.push_back(rhs);
		return lhs;
	}
private:
	std::string value;
};




#endif // !STATE_H

