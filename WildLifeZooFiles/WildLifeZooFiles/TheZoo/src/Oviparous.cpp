/*
 * Oviparous.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#include "Oviparous.h"

//define class constructor
Oviparous::Oviparous() {
	numberOfEggs = -1;
}

//define class destructor
Oviparous::~Oviparous(){
}

//define class accessor
int Oviparous::GetNumberOfEggs() {
	return numberOfEggs;
}

//define class mutator
void Oviparous::SetNumberOfEggs(int t_numberOfEggs) {
	numberOfEggs = t_numberOfEggs;
}

void Oviparous::PrintRecord() {return;}

//virutal subtype checking function
string Oviparous::CheckSubType() {return "OVIPAROUS";}
