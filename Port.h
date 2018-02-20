#ifndef PORT_H
#define PORT_H

class Port
{
public:
	Port();								//true by default
	Port(bool status);	
	Port(const Port &);
	~Port();
	bool isEnabled();					//returns enabled
	void enable();
	void disable();
	 
private:
	bool enabled;
};

Port::Port()
{
	enabled = true;
}

Port::~Port()
{
}

Port::Port(bool status) {
	enabled = status;
}

Port::Port(const Port &newPort) {
	enabled = newPort.enabled;
}

bool Port::isEnabled() {
	return enabled;
}

void Port::enable() {
	enabled = true;
}

void Port::disable() {
	enabled = false;
}
#endif // !PORT_H
