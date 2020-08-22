/*
 * InputHandler.h
 *
 *  Created on: Aug 12, 2020
 *      Author: Tyler Coplan
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <string>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <istream>

using namespace std;
class InputHandler {
public:
	static string ValidateTrackNum(string t_trackNum);
	static string ValidateName(string t_name);
	static string ValidateType(string t_type);
	static string ValidateSubType(string t_subtType);
	static string ValidateNumOfEggs(string t_numOfEggs);
	static string ValidateNurse(string t_nurse);
	static void ValidateMainInput(string &t_input);
};

#endif /* INPUTHANDLER_H_ */
