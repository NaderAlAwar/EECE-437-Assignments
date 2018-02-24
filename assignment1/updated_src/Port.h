#ifndef PORT_H
#define PORT_H

#include <string>

class Port{

public:
	Port();
	Port(bool, std::string );
	Port(const Port &);

	bool is_enabled();
	void enable();
	void disable();
	std::string get_value();

private:
	bool enabled;
	std::string value;

};

#endif