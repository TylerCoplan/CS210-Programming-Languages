/*
 * Elephant.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: 1763930_snhu
 */

#include "Elephant.h"

Elephant::Elephant() {
	// TODO Auto-generated constructor stub

}

Elephant::~Elephant() {
	// TODO Auto-generated destructor stub
}


//print record function
void Elephant::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "|";
	cout << " Mammal         | Elephant       | 0              | ";
	cout << setw(15) << left << Mammal::GetNurse() << "|" << endl;
}

string Elephant::CheckSubType(){
	return "Elephant";
}
