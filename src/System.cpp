#include "System.h"

System::System(const std::vector<Interaction> & interactions) {
	myInteractions = interactions;
}

bool System::execute() {					//select an interaction and execute it
	for (auto it = myInteractions.begin(); it != myInteractions.end(); it++) {
		std::cout<<"-1: checking if interaction enabled"<<std::endl;
		if (it->isEnabled())
			std::cout<<"0: executing interaction..."<<std::endl;
			return it->execute();
	}
	return false;
}