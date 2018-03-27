#ifndef SYSTEM_H
#define SYSTEM_H

#include "Interaction.h"
#include "FSM.h"

class System{
public:
	System(const std::vector<Interaction> &);
	System();
	void run(int);											//run the system for a number of time steps
	bool execute();
private:
	std::vector<Interaction> myInteractions;


};



#endif