/*
 * Pelican.h
 *
 *  Created on: Aug 11, 2020
 *      Author: 1763930_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "Oviparous.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Pelican : public Oviparous {
public:
	Pelican();
	~Pelican();

	//print record
	void PrintRecord();

	//check subtype
	string CheckSubType();

};
//
#endif /* PELICAN_H_ */
