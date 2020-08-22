/*
 * Goose.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#include "Goose.h"

Goose::Goose() {
	// TODO Auto-generated constructor stub

}

Goose::~Goose() {

}

//print record function
void Goose::PrintRecord(){
	cout << "| " << setw(6) << setfill('0') << right << Animal::GetTrackNum() << "         | ";
	cout << setw(15) << setfill(' ') << left << Animal::GetName() << "| Oviparous      ";
	cout << "| Goose          | " << setw(15) << left << Oviparous::GetNumberOfEggs();
	cout << "| 0              |" << endl;
}

string Goose::CheckSubType(){
	return "Goose";
}
