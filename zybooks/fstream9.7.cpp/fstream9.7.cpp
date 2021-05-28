// 9.7 Lab: CerealAnalysis
// This lab reads from a text file called cereal.txt.

// Here is a part of the text file:

//  name calories fiber sugars rating
//  All-Bran 70 9 5 59.42
//  Almond-Delight 110 1 8 34.38
//  Apple-Cinnamon-Cheerios 110 1 10 29.51
//  Apple-Jacks 110 1 14 33.17
//  Basic-4 130 2 8 37.04
//  Bran-Chex 90 4 6 49.12
// It has multiple functions to perform the different tasks. The goal is to open the file, read from it, and perform some tasks. For the sake of simplicity we will assume that the values listed in the text file are for 1 serving of each cereal.

// Our tasks for this lab are:

// 1) Open the file and check to make sure it opens.  If it does not, the program exits.
// 2) Compare the calories of one cereal to another and find the one that has the least amount of calories per serving.
// 3) Compare the calories of one cereal to another and find the one that has the most sugar content per serving.
// 4) This program does not store any data into arrays.  We read the data and  find the cereal that has the most sugar and the least calories per serving using loops.
// 5) I have written the first 2 functions for you, you will need to fill in the last function that finds the cereal with the most amount of sugar.  Refer to the function leastCalories().  That should help you figure it out!
// Your output should look like this:

// Puffed-Rice has the least amount of calories: 50
// Golden-Crisp has the most amount of sugar: 15

//headers and global constants
//Sources: https://www.kaggle.com/rtatman/fun-beginner-friendly-datasets
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//function prototypes
bool openFile(string fileName, ifstream & inFile);
void leastCalories(ifstream & inFile, string &calName, int &leastCal);
void mostSugar(ifstream & inFile, string &sugarName, int &mostSugar);

//main()
int main()
{
	//variables
	ifstream inFile;
	string itemName, fileName;
	int itemValue = 0;
	//user input for filename
	cout << "Enter file name:";
	getline(cin, fileName);
	//call function to open file
	if (!openFile(fileName, inFile))
	{
		cout << "File did not open. Program terminating!!" << endl;
		return 0;
	}
	//call function to return by reference least calories item name and value
	leastCalories(inFile, itemName, itemValue);
	cout << itemName << " has the least amount of calories: " << itemValue << endl;
	//call function to return by reference most sugar's item name and value
	mostSugar(inFile, itemName, itemValue);
	cout << itemName << " has the most amount of sugar: " << itemValue << endl;
	//end
	return 0;
}

//open file function
bool openFile(string fileName, ifstream& inFile)
{
	inFile.open(fileName);
	if (!inFile)
	{
		return false;
	}
	return true;
}

//finds the cereal with the least calories and returns its name and the value
void leastCalories(ifstream &inFile, string &calName, int &leastCal)
{
	string cerealName;
	int calories = 0, fiber = 0, sugars = 0, discard = 0;
	double rating = 0;
	inFile.ignore(200, '\n');
	inFile >> cerealName >> calories >> fiber >> sugars >> rating;
	leastCal = calories;
	while (!inFile.eof())
	{
		if (leastCal > calories)
		{
			leastCal = calories;
			calName = cerealName;
		}
		inFile >> cerealName >> calories >> fiber >> sugars >> rating;
	}
	//rewinds the file back to the beginning.
	inFile.clear();
	inFile.seekg(0);
}

//finds the cereal with the most sugar content and returns its name and the value
void mostSugar(ifstream &inFile, string &sugarName, int &mostSugar)
{
	string cerealName;
	int calories = 0, fiber = 0, sugars = 0, discard = 0;
	double rating = 0;
	inFile.ignore(200, '\n');
	inFile >> cerealName >> calories >> fiber >> sugars >> rating;
	mostSugar = sugars;
	while (!inFile.eof())
	{
		if (mostSugar < sugars)
		{
			mostSugar = sugars;
			sugarName = cerealName;
		}
		inFile >> cerealName >> calories >> fiber >> sugars >> rating;
	}
	//rewinds the file back to the beginning.
	inFile.clear();
	inFile.seekg(0);
	
}