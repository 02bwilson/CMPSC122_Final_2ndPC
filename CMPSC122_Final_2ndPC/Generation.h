#ifndef GENERATION_H
#define GENERATION_H
#include "Schedule.h"
#include "Rule.h"
class Generation {
private:
	const int pop_size = 100;
	Schedule* schedules[100];
	const int elite = 20;
	const int iterations = 500;
	const int stable = 3;
public:
	Generation();
	int getPopSize();
	int getElite();

	
	
};

class Rule1 : public Rule {
	int getFitness(Schedule schedule);
};

class Rule2 : public Rule {
	int getFitness(Schedule schedule);
};

class Rule3 : public Rule {
	int getFitness(Schedule schedule);
};

class Rule4 : public Rule {
	int getFitness(Schedule schedule);
};

class Rule5 : public Rule {
	int getFitness(Schedule schedule);
};


class Optimizer {
private: 
	int rc = 0;
	Rule** rules = new Rule*;
public: 
	void addRule(Rule1 rule);
	void addRule(Rule2 rule);
	void addRule(Rule3 rule);
	void addRule(Rule4 rule);
	void addRule(Rule5 rule);
	void optimize(Generation gener);
};




#endif