
#include "Schedule.h"
#include <fstream>
#include <iostream>

using namespace std; 

void Schedule::randomize() {
	node* nodePtr = head;
	
	while (nodePtr->next) {
		// 8 posibilites, 1 = mwf 2 = t/th 3 = mw, 4 = m 5 = t 6 = w 7= th 8 = f
		int day = rand() % 8 + 1;

		// Switch case so assign the days from the random day(s) generated
		switch (day) {
		case 1: {
			int start = rand() % 24 + 1;
			if (start == 12) start += 1;
			nodePtr->section->setDay(0, 1);
			nodePtr->section->setDay(1, 3);
			nodePtr->section->setDay(2, 5);
			nodePtr->section->setStart(0, start);
			start = rand() % 24 + 1;
			nodePtr->section->setStart(1, start);
			start = rand() % 24 + 1;
			nodePtr->section->setStart(2, start);
		}
			break;
		case 2: {
			int random = rand() % 5;
			int startTimes[] = {8,10,1,3,5,7 };

			nodePtr->section->setDay(0 ,2);
			nodePtr->section->setDay(1,4);
			nodePtr->section->setStart(0, startTimes[random]);
			random = rand() % 5;
			nodePtr->section->setStart(1, startTimes[random]);
		}
			break;
		case 3: {
			int random = rand() % 5;
			int startTimes[] = { 8,10,1,3,5,7 };

			nodePtr->section->setDay(0, 2);
			nodePtr->section->setDay(1, 4);
			nodePtr->section->setStart(0, startTimes[random]);
			random = rand() % 5;
			nodePtr->section->setStart(1, startTimes[random]);
		}
			  break;
		case 4: 
		case 5:
		case 6: 
		case 7:
		case 8:
			nodePtr->section->setDay(0, (day % 5) + 1);
			nodePtr->section->setStart(0, rand() % 24 + 1);
			if (nodePtr->section->getStart(0) == 12) nodePtr->section->setStart(0, nodePtr->section->getStart(0) + 1);
			if (nodePtr->section->getStart(0) == 11) nodePtr->section->setStart(0, nodePtr->section->getStart(0) - 2);
			if (nodePtr->section->getStart(0) == 10) nodePtr->section->setStart(0, nodePtr->section->getStart(0) - 1);
			break;

			
		}

		nodePtr = nodePtr->next;





	}
	
	




}

void Schedule::incFitness(int value) {
	fitness += value;
}

Schedule::Schedule() {
	// This just initlizes the linked list by reading in the classes
	fstream file;
	file.open("ClassList.txt");
	if (!file.is_open()) {
		cout << "Error opening file";
	}
	
	while (!file.eof()) {

		node* newNode = new node;
		string temp;
		file >> temp;
		newNode->section->setIdentifier(temp);
		file >> temp;
		newNode->section->setLastName(temp);

		newNode->next = nullptr;

		node* nodePtr = head;
		
		if (!head) {
			head = newNode;
		}

		else {
			
			while (nodePtr->next) {
				nodePtr = nodePtr->next;
			}
		
			nodePtr->next = newNode;
		}
		
		
	}
	
}

Schedule::node* Schedule::getNode() {
	return head;
}

void Schedule::printSch() {

	// Used this mainly for testing, but also used to print best schedule generated 
	cout << endl << endl;
	node* nodePtr = head;
	while (nodePtr->next) {
		cout << nodePtr->section->getDay(0) << " ";
		nodePtr = nodePtr->next;
	}
}



/*
int Schedule::fitness() {
	int fitness = 0;
	node* nodePtr = head;
	node* compNode = head;
	// 40 in this loop is the # of classes in my list, can be changed to a variabele if the class size changes 
	while (nodePtr->next) {
		if (nodePtr->section->day[4] != -1) {
			int hoursonDay = 0;
			while (compNode->next) {
				if (compNode != nodePtr) {


					//////////////////////////////////////// Expressions for fitness ////////////////////////////////////////

					// Checking if the cur node and comparison node have the same instructor
					if (nodePtr->section->lastName == compNode->section->lastName) {
						if (nodePtr->section->start[0] >= 6 && (compNode->section->day[0] = nodePtr->section->day[0] + 1))

							// Checks how many hours the teacher teaches per day, increments a counter that is used at end of loop
							if (nodePtr->section->day[0] == compNode->section->day[0] ||
								nodePtr->section->day[1] == compNode->section->day[0] ||
								nodePtr->section->day[2] == compNode->section->day[0] ||
								nodePtr->section->day[3] == compNode->section->day[0] ||
								nodePtr->section->day[1] == compNode->section->day[0]
								) {
								if (nodePtr->section->day[1] == NULL) {
									hoursonDay += 1;
								}


							}

						//If instuctor teaches at same time add lots of pts!
						if (nodePtr->section->start[0] == compNode->section->start[0]) {
							if (nodePtr->section->day[0] == compNode->section->day[0])
							
						}

					}
					// Adds 100 pts for every hour an instructor teaches more then 9, have to have to if statement so it doesnt subtract lots of points if they dont teach over 9
					if (hoursonDay > 9) {
						fitness += 100 * (hoursonDay - 9);
					}
				}
				compNode = compNode->next;
			}
		}


		nodePtr = nodePtr->next;
	}
	return fitness;
}
*/