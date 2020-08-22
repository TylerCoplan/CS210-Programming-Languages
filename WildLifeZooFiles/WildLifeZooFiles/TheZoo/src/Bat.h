/*
 * Bat.h
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"
#include <iomanip>
#include <iostream>

using namespace std;
class Bat : public Mammal{
public:
	Bat();
	~Bat();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();
};

#endif /* BAT_H_ */
