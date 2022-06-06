#ifndef SECTION_H
#define SECTION_H

#include <string>

using namespace std;

class Section {
private:
	int day[4];
	int start[3];
	string identifer;
	string lastName; 
public: 
	Section();
	int getDay(int pos);
	int getStart(int pos);
	string getIdentifier;
	string getLastName;
	void setDay(int pos, int value);
	void setStart(int pos, int value);
	void setIdentifier(string idn);
	void setLastName(string ln);
};






#endif 