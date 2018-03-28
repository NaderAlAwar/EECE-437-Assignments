#include "System.h"
System::System() {

}

System::System(const std::vector<Interaction> & interactions) {
	myInteractions = interactions;
}

bool System::execute() {					//select an interaction and execute it

	for (std::vector<Interaction>::iterator it = myInteractions.begin(); it != myInteractions.end(); it++) {
		if (it->isEnabled())
			return it->execute();
	}
	return false;
}