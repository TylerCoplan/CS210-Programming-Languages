/*
 * InputHandler.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: 1763930_snhu
 */

#include "InputHandler.h"
using namespace std;

string InputHandler::ValidateTrackNum(string t_trackNum) {
	//boolean keeps track of successful input
	bool success;
	do {
		success = true;  //will switch to fail if error thrown

		try {
			//validate the number is within the 6 digit limit
			if (t_trackNum.length() > 6) {
				throw runtime_error("Too large, ");
			}
			//throw error if input is null
			if (t_trackNum.length() == 0) {
				throw runtime_error("No input found, ");
			}
			//validate that each char is a number
			for (unsigned int i = 0; i < t_trackNum.length(); i++) {
				if (isdigit(t_trackNum.at(i)) == 0) {
					throw runtime_error("Not a number, ");
				}
			}
		}
		//catches any errors and gets new input to test
		catch (runtime_error& e){
			cout << e.what() << "please enter a number between 0 and 999999";
			t_trackNum = "";
			success = false;
			getline(cin, t_trackNum);
		}
	} while (!success);
	return t_trackNum;
}

string InputHandler::ValidateName(string t_name) {
	bool success;

	do {
		success = true;  //will switch to false if fail

		//check if name is under or equal to 15 characters
		try {
			if (t_name.length() > 15) {
				throw runtime_error("Name is too long, ");
			}
			//throw error if no input found
			if (t_name.length() == 0) {
				throw runtime_error("No input found, ");
			}
		}
		//catch block prints error message, gets new input and sets boolean to false
		catch (runtime_error& e) {
			cout << e.what() << "please enter a name less than 15 letters: " << endl;
			t_name = "";
			success = false;
			getline(cin, t_name);
		}
	} while (!success);
	return t_name;
}

string InputHandler::ValidateType(string t_type) {
	bool success;
	do{
		success = true;  //will switch to false if fail
		try {
			//check if type is 15 characters or less
			if (t_type.length() > 15) {
				throw runtime_error("Type is too long, ");
			}
			//check if type is mammal or oviaparous
			if (!(t_type == "Mammal" || t_type == "Oviparous")) {
				throw runtime_error("Invalid animal type, ");
			}
		}
		//catch block prints error message, gets new input and sets boolean to false
		catch (runtime_error& e) {
			cout << e.what() << "please enter \"Mammal\" or \"Oviparous\": " << endl;
			t_type = "";
			success =  false;
			getline(cin, t_type);
		}
	} while (!success);
	return t_type;
}

string InputHandler::ValidateSubType(string t_subType) {
	bool success;
	do {
		success = true;
		try {
			//check if sub-type is within 15 character limit
			if (t_subType.length() > 15) {
				throw runtime_error("Sub-type is too long, ");
			}
			//check if sub-type matches valid sub-types
			if (!(t_subType == "Goose"   || t_subType == "Pelican" ||
				t_subType == "Crocodile" || t_subType == "Bat" ||
				t_subType == "Whale"     || t_subType == "SeaLion" ||
				t_subType == "Elephant")){
					throw runtime_error("Invalid animal sub-type, ");
			}
		}
		//catch block prints error message, gets new input and calls function again
		catch (runtime_error& e) {
			cout << e.what() << "please enter Goose, Pelican, Crocodile, Whale, Bat, SeaLion or Elephant: " << endl;
			success = false;
			t_subType = "";
			getline(cin, t_subType);
		}
	} while (!success);

	return t_subType;
}
string InputHandler::ValidateNumOfEggs(string t_numOfEggs) {
	bool success;
	do {
		success = true; //will switch if failure
		try {
			//see if number is too long
			if (t_numOfEggs.length() > 5) {
				throw runtime_error("Too many eggs, please enter a reasonable number of eggs: ");
			}

			//throw error if no input found
			if (t_numOfEggs.length() == 0) {
				throw runtime_error("No input found, please enter a number");

			}

			//see if each character is a digit
			for(unsigned int i = 0; i < t_numOfEggs.length(); i++) {
				if (!isdigit(t_numOfEggs.at(i))) {
					throw runtime_error("Not a number, please enter positive, whole number: ");
				}
			}
		}
		//catches any errors and takes new input and recalls the data handling function
		catch (runtime_error& e){
			cout << e.what() << endl;
			t_numOfEggs = "";
			success = false;
			getline(cin, t_numOfEggs);
		}
	} while (!success);

	return t_numOfEggs;
}

string InputHandler::ValidateNurse(string t_nurse) {
	bool success;
	do{
		success = true;
		try {
			//see if number is too long
			if (t_nurse.length() > 1) {
				throw runtime_error("Input too long, ");
			}

			if (t_nurse.length() == 0){
				throw runtime_error("No input found, ");
			}
			//see if string is 0 or 1
			if (!(t_nurse == "1" || t_nurse == "0")){
				throw runtime_error("");
			}
		}

		// display error message, get new input, call function again
		catch (runtime_error& e) {
			cout << e.what() << "please enter 1 or 0" << endl;
			success = false;
			t_nurse = "";
			getline(cin, t_nurse);
		}
	} while (!success);

	return t_nurse;
}

void InputHandler::ValidateMainInput(string &t_input) {
	while (t_input != "1" && t_input != "2" && t_input != "3" &&
		   t_input != "4" && t_input != "5" && t_input != "6" &&
		   t_input != "X") {
		cout << "Invalid input, please choose option 1-6 or X to exit:" << endl;
		getline(cin, t_input);
	}
}
