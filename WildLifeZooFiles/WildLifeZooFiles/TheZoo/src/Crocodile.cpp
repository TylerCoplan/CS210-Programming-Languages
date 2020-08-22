/*
 * Crocodile.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#include "Crocodile.h"

Crocodile::Crocodile() {

}

Crocodile::~Crocodile() {
}

//print record function
void Crocodile  ::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "| Oviparous      ";
	cout << "| Crocodile      | " << setw(15) << left << Oviparous::GetNumberOfEggs();
	cout << "| 0              |" << endl;
}

string Crocodile::CheckSubType(){
	return "Crocodile";
}
