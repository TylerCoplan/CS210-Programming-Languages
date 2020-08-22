/*
 * Elephant.h
 *
 *  Created on: Aug 16, 2020
 *      Author: 1763930_snhu
 */

#ifndef ELEPHANT_H_
#define ELEPHANT_H_

#include "Mammal.h"
#include <iomanip>
#include <iostream>

class Elephant : public Mammal{
public:
	Elephant();
	virtual ~Elephant();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();

};

#endif /* ELEPHANT_H_ */
