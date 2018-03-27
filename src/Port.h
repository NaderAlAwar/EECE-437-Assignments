#ifndef PORT_H
#define PORT_H

#include <string>

class Port
{
public:
	Port();								//true by default
	Port(bool status, std::string input);
	Port(const Port &);
	//~Port();
	bool isEnabled();					//returns enabled
	// void enable();
	// void disable();
	std::string getValue();

	// if isEnabled executes FSM
	bool execute();
	 
private:
	bool enabled;
	std::string value;
};


#endif // !PORT_H
