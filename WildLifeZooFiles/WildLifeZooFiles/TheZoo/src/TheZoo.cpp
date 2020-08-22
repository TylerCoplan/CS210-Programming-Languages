/*=================================================
 * Author: Tyler Coplan
 * Date: 8/14/2020 (first version completion date)
 *
 * About this program:
 * This program keeps a record of zoo animals and
 * their tracking information.  This program gives
 * the user the ability to load records from a file,
 * add records, delete records and save the file.
 * It also provides the ability to print the data
 * into a formatted table.
 *
 * About this project and what I learned:
 * I hit many roadblocks in this project, but it taught
 * me a lot.  Like never initialize a pointer without
 * pointing it to something.  I learned a ton about
 * polymorphism, such as base class pointers to
 * derived class objects and virtual functions.  I still
 * need to remember all of the C++ tools available such
 * as pass by reference.  All of my InputHandler class
 * functions could have used this but for whatever reason
 * I didn't even think of it until writing the main() input
 * handler.  I still hate the way I read from the file,
 * so I need to learn some better techniques for doing that.
 * Two problems I have are eof() does not trigger when Java
 * writes the file and the tracking number and name do not have
 * any whitespace between which makes for some manual parsing.
 * Overall, I worked hard on this and I am proud of what I
 * accomplished.  Is it perfect, no.  Is it great, probably not.
 * But it is a start, it taught me a lot and I am excited to build
 * on my knowledge in future courses.
 *
 * Reference:
 * And lastly, just a sort of macro reference to cplusplus.com
 * Using their web resources to find standard library headers and
 * functions helped me come up with a lot of the code you see here.
 * My solutions are mostly mashups of what I read from that website
 * so I did not think specific references were necessary, but that
 * is where I found the information for the standard library functions
 * I used.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <jni.h>
#include "SeaLion.h"
#include "Whale.h"
#include "Bat.h"
#include "Elephant.h"
#include "Goose.h"
#include "Crocodile.h"
#include "Pelican.h"
#include "InputHandler.h"

using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

//takes user input and creates a new animal* to derived class and adds to vector
void AddAnimal(vector<Animal*> &animalVector) {
	//local variables
	string name, trackNum, subType, numOfEggsStr, nurseStr;
	int numOfEggsInt = -1, nurseInt = -1; // need to instantiate to avoid random values
	stringstream ss;
	Animal* animalPtr;

	//prompt user / get input / validate input
	cout << "Enter the animal's name: " << endl;
	getline(cin, name);
	name = InputHandler::ValidateName(name);

	//******TRACK NUMBER***********
	//prompt user / get input / validate input
	cout << "Enter the animal's tracking number :" << endl;
	getline(cin, trackNum);

	// insert 0's to get to track number 6 character field length
	trackNum = InputHandler::ValidateTrackNum(trackNum);
	for (int i = 6 - trackNum.length(); i > 0; i--) {
		trackNum.insert(0, "0");
	}

	//check if tracking number already in use - if in use, get a new track number
	for (unsigned int i = 0; i < animalVector.size(); i++) {
		if (trackNum == animalVector.at(i)->GetTrackNum()) {
			cout << "Tracking number " << trackNum << " is already in use, please enter a different number." << endl;
			getline(cin, trackNum);
			trackNum = InputHandler::ValidateTrackNum(trackNum);
			i = 0; //restarts the loop to check against all tracking numbers again
		}
	}
	//**********END TRACK NUMBER CODE************

	//prompt user / get input / validate input
	cout << "Enter the animal's sub-type" << endl;
	cout <<	"(Goose, Pelican, Crocodile, Whale, SeaLion, Bat, Elephant): " << endl;
	getline(cin, subType);
	subType = InputHandler::ValidateSubType(subType);

	//check if Oviparous, if so, ask for number of eggs
	if (subType == "Goose" || subType == "Pelican" || subType == "Crocodile"){
		cout << "Enter the number of the animal's eggs :" << endl;
		getline(cin, numOfEggsStr);
		numOfEggsStr = InputHandler::ValidateNumOfEggs(numOfEggsStr);
		ss << numOfEggsStr; //parse string
		ss >> numOfEggsInt; //to int
	}

	//check if Mammal, if so ask if nursing
	else if (subType == "Bat" || subType == "Whale" || subType == "SeaLion" || subType == "Elephant"){
		cout << "Enter 1 if animal is nursing or 0 if not nursing:" << endl;
		getline(cin, nurseStr);
		nurseStr = InputHandler::ValidateNurse(nurseStr);
		ss << nurseStr; //parse string
		ss >> nurseInt; // to int
	}

	//SHOULD NEVER EXECUTE!!!!!! if my input handlers work properly
	else {
		cout << "Something went wrong, no animals were added.  Please try again" << endl;
	}

	//decision branches to point to object of correct subtype and sets type's private variable (eggs or nurse)
	if (subType == "Bat") {
		animalPtr = new Bat();
		animalPtr->SetNurse(nurseInt);
	}

	else if (subType == "Whale") {
		animalPtr = new Whale();
		animalPtr->SetNurse(nurseInt);
	}

	else if (subType == "SeaLion") {
		animalPtr = new SeaLion();
		animalPtr->SetNurse(nurseInt);
	}

	if (subType == "Elephant") {
		animalPtr = new Elephant();
		animalPtr->SetNurse(nurseInt);
	}

	else if (subType == "Goose") {
		animalPtr = new Goose();
		animalPtr->SetNumberOfEggs(numOfEggsInt);
	}

	else if (subType == "Pelican") {
		animalPtr = new Pelican();
		animalPtr->SetNumberOfEggs(numOfEggsInt);
	}

	else if (subType == "Crocodile") {
		animalPtr = new Crocodile();
		animalPtr->SetNumberOfEggs(numOfEggsInt);
	}

	//sets name and track number
	animalPtr->SetName(name);
	animalPtr->SetTrackNum(trackNum);

	//push to vector
	animalVector.push_back(animalPtr);
}

//finds an animal by searching for tracking number and confirms record deletion
void RemoveAnimal(vector<Animal*> &animalVector){
	string trackNum;
	string confirm;
	bool removed = false;
	bool found = false;

	//prompt user for track number / take input
	cout << "Please enter the animals 6 digit tracking number: " << endl;
	getline(cin, trackNum);
	trackNum = InputHandler::ValidateTrackNum(trackNum);

	//search vector for track number
	for(unsigned int i = 0; i < animalVector.size(); i++) {
		if (trackNum == animalVector.at(i)->GetTrackNum()) {
			//once found, display animal information and confirm user wants to remove
			found = true;
			cout << "Animal Name: " << animalVector.at(i)->GetName() << endl;
			cout << "Animal Tracking Number: " << animalVector.at(i)->GetTrackNum() << endl;
			cout << "Are you sure you want to delete this animal? Enter \"y\" or \"Y\" to delete: "<< endl;
			getline(cin, confirm);
			//if remove confirmed
			if (confirm == "y" || confirm == "Y") {
				delete animalVector.at(i); //destroy pointer
				animalVector.erase(animalVector.begin() + i);  //remove pointer from vector
				cout << "The animal has been successfully removed." << endl;
				removed = true;
				break;
			}
		}
	}

	//displays message if tracking number not found
	if (!found) {
		cout << "The tracking number " << trackNum << " was not found." << endl;
	}
	//displays message if no animals were deleted
	if (!removed) {
		cout << "No Animals were removed, returning to menu..." << endl;
	}
}

//loads data from the zoodata.txt file into a vector
/*
 * This function was much simpler, however for some reason the GenerateData
 * .txt file, which is created by Java, would not trigger the eof bit on the file variable
 * so I had to come up with this crazy method of reading the file after much trial and
 * error.
 */
void LoadDataFromFile(vector<Animal*> &animalVector){
	//local variables
	ifstream file;
	stringstream ss;
	string trackNum, name, type, subType, numOfEggs, nurse, fileText;
	int numOfEggsInt, nurseInt;

	//open text file
	file.open("zoodata.txt");
	//print error if open failure and return
	if(!file.is_open()) {
		cout << "Error opening zoodata.txt" << endl;
		return;
	}
	//print confirmation message if successful
	else{
		cout << "zoodata.txt opened successfully, loading data..." << endl;
	}

	/*
	 * Reading from this file is not optimal. For whatever reason, the GenerateData
	 * function would create a .txt file that would not set the eof flag and my while(!file.eof())
	 *  loop would run infinitely.  I am sure that there is a better way to do this but I am out
	 *  of ideas so this inefficient method of file to string, breaking into substrings and finding digits
	 *  for the nurse and eggs vars.  I tried char arrays, I tried a lot of things, this is what I got.
	 */
	//extract file to a string
	while (getline(file, fileText)){

		trackNum = fileText.substr(0, 6);
		name = fileText.substr(6, 15);
		type = fileText.substr(21, 15);
		subType = fileText.substr(36, 15);
		nurse = "";
		numOfEggs = "";

		//since nursing is last field and either 1 or 0, just get the last digit in the record
		for (int i = (fileText.length() - 1); i >= 50; i--) { //reverse iterate string
			//triggers when first digit found
			if (isdigit(fileText.at(i))) {   //last char digit should be 1 or 0 for nursing
				nurse = fileText.at(i);     // get nursing value
				fileText.pop_back();       // remove nursing value
				break;                     //break loop
			}
			//removes any whitespace chars until digit is found
			else {
				fileText.pop_back();     // removes chars going backwards until nurse value found
			}
		}

		//finds all chars in the nursing field, string will be reversed
		//i> 50 because 50 will be the last index of the sub-type field
		for (int i = (fileText.length() - 1); i > 50; i--) { //reverse iterate string
			if (isdigit(fileText.at(i))) {   //last char digit should be 1 or 0 for nursing
				numOfEggs += fileText.at(i);     // get nursing value
				fileText.pop_back();       // remove nursing value
			}
			else {
				fileText.pop_back();     // removes chars going backwards until nurse value found
			}
		}

		//reverse num of eggs string to original entry
		if (numOfEggs.length() > 1) {
			for(unsigned int i = 0; i < numOfEggs.length()/2; i++) {
				char temp;
				temp = numOfEggs[i];
				numOfEggs[i] = numOfEggs[numOfEggs.length() - i - 1];
				numOfEggs[numOfEggs.length() - i - 1] = temp;
			}
		}

		//parse strings to int
		nurseInt = stoi(nurse);
		numOfEggsInt = stoi(numOfEggs);

		//decision branches to point to object of correct subtype and sets type's private variable (eggs or nurse)
		//comparison requires 15 chars based on having to read the file that way, hence the spaces
		if (subType == "Bat            ") {
			Animal* animalPtr = new Bat();
			animalPtr->SetNurse(nurseInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "Whale          ") {
			Animal* animalPtr = new Whale();
			animalPtr->SetNurse(nurseInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "SeaLion        ") {
			Animal* animalPtr = new SeaLion();
			animalPtr->SetNurse(nurseInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "Elephant       ") {
			Animal* animalPtr = new Elephant();
			animalPtr->SetNurse(nurseInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "Goose          ") {
			Animal* animalPtr = new Goose();
			animalPtr->SetNumberOfEggs(numOfEggsInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "Pelican        ") {
			Animal* animalPtr = new Pelican();
			animalPtr->SetNumberOfEggs(numOfEggsInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}

		else if (subType == "Crocodile      ") {
			Animal* animalPtr = new Crocodile();
			animalPtr->SetNumberOfEggs(numOfEggsInt);
			animalPtr->SetName(name);
			animalPtr->SetTrackNum(trackNum);
			animalVector.push_back(animalPtr);
		}
	}
	cout << "Load Complete." << endl;
}

//saves the objects in the animalList vector to .txt file
void SaveDataToFile(vector<Animal*> animalList){
	//instantiate local input holder
	string input;

	//display warning and confirmation messages
	cout << "Saving data erases the old file and cannot be reverted." << endl;
	cout << "Are you sure you want to save? Enter 'y' or 'Y' to confirm:" << endl;
	cin >> input;

	if (input != "y" && input != "Y") {
		cout << "Data was NOT saved, returning to menu..." << endl;
		return;
	}

	cout << "Saving updated data.." << endl;

	//open file
	ofstream file;
	file.open("zoodata.txt");

	if (!file.is_open()) {
		cout << "Error opening file. Returning to menu..." << endl;
		return;
	}

	//declare an iterator and field length constants
	unsigned int j;
	//const int TRACK_NUM_CHARS = 6;
	const int NAME_CHARS = 15;	//
	//loop of decision branches to write each record
	for (unsigned int i = 0; i < animalList.size(); i++) {

		//write track num
//UNCOMMENT CONST TOO		for (j = 0; j < (TRACK_NUM_CHARS - animalList.at(i)->GetTrackNum().length()); j++) {
//			file << '0';  //writes 0's to begining of track num which is formatted as 6
//		}
		file << animalList.at(i)->GetTrackNum();

		//write name
		file << animalList.at(i)->GetName();
		for (j = 0; j < (NAME_CHARS - animalList.at(i)->GetName().length()); j++){
			file << ' ';   //writes spaces to get to formatted length of 15
		}

		if (animalList.at(i)->CheckSubType() == "Bat") {
			//write type, subtype and number of eggs, get nurse and write new line
			file << "Mammal         Bat            0 ";
			file << animalList.at(i)->GetNurse();
			file << '\n';
		}

		if (animalList.at(i)->CheckSubType() == "Elephant") {
			//write type, subtype and number of eggs, get nurse and write new line
			file << "Mammal         Elephant       0 ";
			file << animalList.at(i)->GetNurse();
			file << '\n';
		}

		if (animalList.at(i)->CheckSubType() == "SeaLion") {
			//write type, subtype and number of eggs, get nurse and write new line
			file << "Mammal         SeaLion        0 ";
			file << animalList.at(i)->GetNurse();
			file << '\n';
		}

		if (animalList.at(i)->CheckSubType() == "Whale") {
			//write type, subtype and number of eggs, get nurse and write new line
			file << "Mammal         Whale          0 ";
			file << animalList.at(i)->GetNurse();
			file << '\n';
		}

		if (animalList.at(i)->CheckSubType() == "Crocodile") {
			//write type and subtype, get number of eggs and write, write nursring and new line
			file << "Oviparous      Crocodile      ";
			file << animalList.at(i)->GetNumberOfEggs();
			file << " 0\n";
		}

		if (animalList.at(i)->CheckSubType() == "Goose") {
			//write type and subtype, get number of eggs and write, write nursring and new line
			file << "Oviparous      Goose          ";
			file << animalList.at(i)->GetNumberOfEggs();
			file << " 0\n";
		}

		if (animalList.at(i)->CheckSubType() == "Pelican") {
			//write type and subtype, get number of eggs and write, write nursring and new line
			file << "Oviparous      Pelican        ";
			file << animalList.at(i)->GetNumberOfEggs();
			file << " 0\n";
		}
	}
	cout << "Save Complete. Returning to menu..." << endl;
	getline(cin, input); //input for some reason sticks around, this should get rid of it
}

void DisplayMenu(){

	cout << "|==========================|" << endl;
	cout << "| Zoo Animal Database Menu |" << endl;
	cout << "|==========================|" << endl;
	cout << "| 1. Load Animal Data      |" << endl;
	cout << "| 2. Generate Data         |" << endl;
	cout << "| 3. Display Animal Data   |" << endl;
	cout << "| 4. Add Record            |" << endl;
	cout << "| 5. Delete Record         |" << endl;
	cout << "| 6. Save Animal Data      |" << endl;
	cout << "|                          |" << endl;
	cout << "| Enter Menu Option Number |" << endl;
	cout << "| Enter X to exit          |" << endl;
	cout << "|==========================|" << endl;
}

//takes a vector of animal pointers and prints record from subtype class function
void DisplayData(vector<Animal*> animals) {
	//print table header
	cout << setw(102) << setfill('-') << "" << endl;  //top border
	cout << "|" << setw(51) << setfill(' ')<< right << "Zoo Animal Data" << setw(51) << right << "|" << endl;  //table title

	//print table column names
	cout << setw(102) << setfill('-') << "" << endl; // create row border
	cout <<"| Tracking Number| Name           | Type           | Sub-type       | Eggs           | Nursing        |" << endl; //column headers
	cout << setw(102) << setfill('-') << "" << endl; // create row border                   sorry for the long line

	//print records
	for (unsigned int i = 0; i < animals.size(); i++) {
		animals.at(i)->PrintRecord(); //prints record - called from each subtype class
		cout << setw(102) << setfill('-') << "" << endl; //row border
	}
}

int main(){
	//GenerateData();
	//main variables
	string input = "";
	vector<Animal*> animalList;
	while (input != "X") {
		DisplayMenu();
		getline(cin, input);
		InputHandler::ValidateMainInput(input);

		if (input == "1") {
			LoadDataFromFile(animalList);
		}

		else if(input == "2") {
			GenerateData();
		}

		else if(input == "3") {
			DisplayData(animalList);
		}

		else if(input == "4") {
			AddAnimal(animalList);
		}

		else if (input == "5") {
			RemoveAnimal(animalList);
		}

		else if(input == "6") {
			SaveDataToFile(animalList);
		}
	}

	cout << "Program terminated.  Thank you for choosing Chada Tech!";
	return 0;
}

/*  ****TEST DISPLAY DATA***
	vector<Animal*> test;
	LoadDataFromFile(test);
	DisplayData(test);

}
*/

/* *****TEST SUBTYPE PRINT RECORD FUNCTIONS*******
	Animal* test1 = new Bat();
	test1->SetName("Batty");
	test1->SetTrackNum("22");
	test1->SetNurse(1);
	test1->PrintRecord();

	Animal* test2 = new Crocodile();
	test2->SetName("Crocy");
	test2->SetTrackNum("942");
	test2->SetNumberOfEggs(8);
	test2->PrintRecord();

	Animal* test3 = new Whale();
	test3->SetName("Hartford");
	test3->SetTrackNum("21");
	test3->SetNurse(0);
	test3->PrintRecord();

	Animal* test4 = new SeaLion();
	test4->SetName("Whiskers");
	test4->SetTrackNum("42");
	test4->SetNurse(1);
	test4->PrintRecord();

	Animal* test5 = new Pelican();
	test5->SetName("Beakers");
	test5->SetTrackNum("88");
	test5->SetNumberOfEggs(0);
	test5->PrintRecord();

	Animal* test6 = new Goose();
	test6->SetName("Honker");
	test6->SetTrackNum("86");
	test6->SetNumberOfEggs(16);
	test6->PrintRecord();
	return 0;
}
*/

/*****TEST LOAD DATA FROM FILE******
	vector<Animal*> animalList;
	LoadDataFromFile(animalList);
	cout << "Size: " << animalList.size() << endl;
	DisplayData(animalList);
	for(unsigned int i = 0; i < animalList.size(); i++){

		cout << animalList.at(i)->GetName() << endl;
		cout << animalList.at(i)->GetTrackNum() << endl;
		cout << animalList.at(i)->GetNumberOfEggs() << endl;
		cout << animalList.at(i)->GetNurse() << endl;
	}
}
*/
/******TEST ADD AND REMOVE ANIMAL FUNCTIONS*****
	vector<Animal*> animalList;
	AddAnimal(animalList);
	AddAnimal(animalList);
	AddAnimal(animalList);
	AddAnimal(animalList);
	AddAnimal(animalList);
	AddAnimal(animalList);
	SaveDataToFile(animalList);

	for (unsigned int i = 0; i < animalList.size(); i++) {
		cout << "Animal " << i + 1 << endl;
		cout << animalList.at(i)->GetName() << endl;
		cout << animalList.at(i)->GetTrackNum() << endl;
		cout << animalList.at(i)->GetNurse() << endl;
		cout << animalList.at(i)->GetNumberOfEggs() << endl;
	}

	RemoveAnimal(animalList);

	for (unsigned int i = 0; i < animalList.size(); i++) {
		cout << "Animal " << i + 1 << endl;
		cout << animalList.at(i)->GetName() << endl;
		cout << animalList.at(i)->GetTrackNum() << endl;
		cout << animalList.at(i)->GetNurse() << endl;
		cout << animalList.at(i)->GetNumberOfEggs() << endl;
	}

	RemoveAnimal(animalList);
	return 0;
}

*/

/*******TEST INPUT HANDLER FUNCTIONS**********
	string test = "123456789012345678";
	InputHandler::ValidateName(test);
	cout << "ValidateName test completet" << endl;
	InputHandler::ValidateTrackNum(test);
	cout << "ValidateTrackNum test completet" << endl;
	InputHandler::ValidateType(test);
	cout << "ValidateType test completet" << endl;
	InputHandler::ValidateSubType(test);
	cout << "ValidateSybType test completet" << endl;
	InputHandler::ValidateNumOfEggs(test);
	cout << "ValidateNumOfEggs test completet" << endl;
	InputHandler::ValidateNurse(test);
	cout << "ValidateNurse test completet" << endl;

	return 0;
}

*/

/******TESTING FOR Mammal SUB CLASSES******
	SeaLion* test;
	test = new SeaLion;
	cout << test->GetName() << endl;
	cout << test->GetTrackNum() << endl;
	cout << test->GetNurse() << endl;
	test->SetTrackNum(123456);
	test->SetName("testy");
	test->SetNurse(6);
	cout << test->GetName() << endl;
	cout << test->GetTrackNum() << endl;
	cout << test->GetNurse() << endl;
	delete test;
	return 0;
}
*/

/********TESTING FOR Oviparous SUB CLASSES*****
	Pelican* test;
	test = new Pelican;
	cout << test->GetName() << endl;
	cout << test->GetTrackNum() << endl;
	cout << test->GetNumberOfEggs() << endl;
	test->SetTrackNum(123456);
	test->SetName("testyGoo");
	test->SetNumberOfEggs(6);
	cout << test->GetName() << endl;
	cout << test->GetTrackNum() << endl;
	cout << test->GetNumberOfEggs() << endl;
	delete test;
	return 0;
}
*/
