/*
 * Crocodile.h
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"
#include <iomanip>
#include <iostream>

using namespace std;


class Crocodile : public Oviparous{
public:
	Crocodile();
	~Crocodile();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();
};

#endif /* CROCODILE_H_ */
