/*
 * Animal.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: Tyler Coplan
 */

#include "Animal.h"

//define constructor
Animal::Animal() {
	name = new char[15];
	trackNum = new char[6];
}

//define desttructor
Animal::~Animal() {
}

//define class accessors
string Animal::GetName() {
	return name;
}

string Animal::GetTrackNum() {
	return trackNum;
}


//define class mutators
void Animal::SetName(string t_name){
	name = t_name;
}

void Animal::SetTrackNum(string t_trackNum) {
	trackNum = t_trackNum;
}

//virtual functions mutators
void Animal::SetNumberOfEggs(int t_numOfEggs){return;}
void Animal::SetNurse(int t_nurse){return;}

//virtual functions accessors
int Animal::GetNumberOfEggs(){return -1;}
int Animal::GetNurse(){return -1;}

//virtual print function
void Animal::PrintRecord(){return;}

//virutal subtype checking function
string Animal::CheckSubType() {return "ANIMAL";}
