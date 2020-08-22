/*
 * SeaLion.h
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#ifndef SEALION_H_
#define SEALION_H_

#include "Mammal.h"
#include <iomanip>
#include <iostream>

using namespace std;

class SeaLion : public Mammal{
public:
	SeaLion();
	~SeaLion();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();

};

#endif /* SEALION_H_ */
