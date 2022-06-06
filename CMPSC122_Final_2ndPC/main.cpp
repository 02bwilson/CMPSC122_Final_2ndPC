#include "Generation.h"
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	// Seeding my random for schedule generation 
	srand(time(NULL));

	// Creating pop_size generations of schedules 
	Generation();
	
	// Creating a new optimizer 
	Optimizer optimize;
	// Creating rules to be added to optmizer (did this so you can easily add/remove rules if you wanted to for some reason)
	Rule1 rule1; 
	Rule2 rule2; 
	optimize.addRule(rule1);
	optimize.addRule(rule2);




	return 0;
}