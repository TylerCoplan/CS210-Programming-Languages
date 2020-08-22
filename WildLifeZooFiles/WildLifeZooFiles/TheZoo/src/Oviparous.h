/*
 * Oviparous.h
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

class Oviparous : public Animal{
public:
	//declare class constructor
	Oviparous();

	//declare class destructor
	virtual ~Oviparous();

	//declare class accessors
	int GetNumberOfEggs() override;

	//declare class mutator
	void SetNumberOfEggs(int t_numberOfEggs) override;

	//virtual print declaration
	virtual void PrintRecord();

	//virtual check subtype
	virtual string CheckSubType();
private:
	int numberOfEggs;
};

#endif /* OVIPAROUS_H_ */
