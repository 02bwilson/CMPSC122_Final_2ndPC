#include "Generation.h"
#include <iostream>
#include "Schedule.h"
using namespace std;

Generation::Generation(){
	for (int i = 0; i < pop_size; i++) {
		Schedule* curSch = new Schedule();
		curSch->randomize();
		schedules[i] = curSch;
		curSch->printSch();
	}



}


void Optimizer::addRule(Rule1 rule) {
	*rules[rc] = rule;
	rc++;
}

void Optimizer::addRule(Rule2 rule) {
	*rules[rc] = rule;
	rc++;
}

void Optimizer::addRule(Rule3 rule) {
	*rules[rc] = rule;
	rc++;
}

void Optimizer::addRule(Rule4 rule) {
	*rules[rc] = rule;
	rc++;
}

void Optimizer::addRule(Rule5 rule) {
	*rules[rc] = rule;
	rc++;
}


int Rule1::getFitness(Schedule schedule) {
	Schedule::node* nodePtr = schedule.getNode();
	Schedule::node* compNode = schedule.getNode();
	while (nodePtr->next) {
			int hoursonDay = 0;
			while (compNode->next) {
				if (compNode != nodePtr) {

				}

}

int Rule2::getFitness(Schedule schedule) {
	return 1;
}

int Generation::getPopSize() {
	return pop_size;
}

void Optimizer::optimize(Generation gener) {
	
}