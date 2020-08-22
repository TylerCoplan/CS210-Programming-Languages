/*
 * Whale.h
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#ifndef WHALE_H_
#define WHALE_H_

#include "Mammal.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Whale : public Mammal{
public:
	Whale();
	~Whale();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();

};

#endif /* WHALE_H_ */
