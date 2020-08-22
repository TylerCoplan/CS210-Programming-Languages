/*
 * Mammal.h
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"
class Mammal : public Animal{
public:
	//class constructor
	Mammal();

	//class destructor
	virtual ~Mammal();

	//class member accessor
	int GetNurse() override;

	//class member mutator
	void SetNurse(int t_nurse) override;

	//virtual print function
	virtual void PrintRecord();

	//virtual check subtype
	virtual string CheckSubType();

private:
	int nurse;
};

#endif /* MAMMAL_H_ */
