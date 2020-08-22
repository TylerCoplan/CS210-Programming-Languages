/*
 * Bat.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#include "Bat.h"

//constructor
Bat::Bat() {
}

//destructor
Bat::~Bat() {
}

//print record function
void Bat::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "|";
	cout << " Mammal         | Bat            | 0              | ";
	cout << setw(15) << left << Mammal::GetNurse() << "|" << endl;
}

string Bat::CheckSubType(){
	return "Bat";
}
