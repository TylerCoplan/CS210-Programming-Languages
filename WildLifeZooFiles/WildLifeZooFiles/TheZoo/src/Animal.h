/*
 * Animal.h
 *
 *  Created on: Aug 11, 2020
 *      Author: Tyler Coplan
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

using namespace std;

class Animal {
public:
	//class constructor
	Animal();

	//class destructor
	virtual ~Animal();

	//class accessors
	string GetName();
	string GetTrackNum();
	Animal* GetNextAnimalPtr();

	//class mutators
	void SetName(string t_name);
	void SetTrackNum(string t_name);
	void SetNextAnimalPtr(Animal* t_nextAnimalPtr);

	//virtual functions mutators
	virtual void SetNumberOfEggs(int t_numOfEggs);
	virtual void SetNurse(int t_nurse);

	//virtual functions accessors
	virtual int GetNumberOfEggs();
	virtual int GetNurse();

	//virtual print record
	virtual void PrintRecord();

	//virtual check subtype
	virtual string CheckSubType();

private:
	string name;
	string trackNum;
};

#endif /* ANIMAL_H_ */
