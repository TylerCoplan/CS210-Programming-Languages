/*
 * Pelican.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#include "Pelican.h"

Pelican::Pelican() {
	// TODO Auto-generated constructor stub

}

Pelican::~Pelican() {

}

//print record function
void Pelican::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "| Oviparous      ";
	cout << "| Pelican        | " << setw(15) << left << Oviparous::GetNumberOfEggs();
	cout << "| 0              |" << endl;
}

string Pelican::CheckSubType(){
	return "Pelican";
}
