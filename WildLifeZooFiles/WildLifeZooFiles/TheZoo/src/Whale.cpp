/*
 * Whale.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#include "Whale.h"

Whale::Whale() {
}
Whale::~Whale() {

}

//print record function
void Whale::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "|";
	cout << " Mammal         | Whale          | 0              | ";
	cout << setw(15) << left << Mammal::GetNurse() << "|" << endl;
}

string Whale::CheckSubType(){
	return "Whale";
}
