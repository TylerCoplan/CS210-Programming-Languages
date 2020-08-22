/*
 * SeaLion.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#include "SeaLion.h"

SeaLion::SeaLion() {
}

SeaLion::~SeaLion() {
}

//print record function
void SeaLion::PrintRecord(){
		cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
		cout << setw(15) << setfill(' ') << left << Animal::GetName() << "|";
		cout << " Mammal         | SeaLion        | 0              | ";
		cout << setw(15) << left << Mammal::GetNurse() << "|" << endl;
	}

string SeaLion::CheckSubType(){
	return "SeaLion";
}
