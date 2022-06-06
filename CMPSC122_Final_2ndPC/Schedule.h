#ifndef  SCHEDULE_H
#define SCHEDULE_H

#include "Section.h"

using namespace std;

class Schedule {

public:
	struct node {
		Section* section = new Section();
		node* next;
	};
	Schedule();
	void printSch();
	
	node* getNode();

	void incFitness(int value);

	void randomize();
private:
	int fitness = 0;
	node* head = nullptr;

	
};





#endif 
