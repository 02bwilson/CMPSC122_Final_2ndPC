#include "Section.h"

using namespace std;

Section::Section() {

}

int Section::getDay(int pos) {
	return day[pos];
}
int Section::getStart(int pos) {
	return start[pos];
}
void Section::setDay(int pos, int value) {
	day[pos] = value;
}
void Section::setStart(int pos, int value) {
	start[pos] = value;
}
void Section::setIdentifier(string idn) {
	identifer = idn;
}
void Section::setLastName(string ln) {
	lastName = ln;
}