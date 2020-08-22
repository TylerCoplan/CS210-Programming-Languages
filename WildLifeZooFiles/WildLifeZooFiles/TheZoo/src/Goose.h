/*
 * Goose.h
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Goose : public Oviparous{
public:
	Goose();
	~Goose();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();
};

#endif /* GOOSE_H_ */
