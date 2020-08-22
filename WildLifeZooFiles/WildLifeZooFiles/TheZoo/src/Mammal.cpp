/*
 * Mammal.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#include "Mammal.h"

//define class constructor
Mammal::Mammal() {
	nurse = -1;
}

//define class destructor
Mammal::~Mammal() {
}

//define class accessor
int Mammal::GetNurse() {
	return nurse;
}

//define class mutator
void Mammal::SetNurse(int t_nurse) {
	nurse = t_nurse;
}

//define virtual print function
void Mammal::PrintRecord(){return;}

//virutal subtype checking function
string Mammal::CheckSubType() {return "MAMMAL";}


