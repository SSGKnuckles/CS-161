//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 06 Starter file.
//Date:         05/14/2021
//Description:  Using starter file for Assignment 6. It builds a list
//              using the random number generator. It has a print function to
//              print the list.  You need to complete the insertNum() function
//              and evenCount()
//Input:        No input
//Output:       List of numbers
//Sources:      'a06.cpp starter file' by GD Iyer
//***********************************************************

#include <iostream>
#include <ctime>

using namespace std;

//constants and function prototypes
const int CAP = 20;
void buildList(int[], int &count);
void printList(int[], int count);

//your function to implement
/*This function  insert a new number after the first odd number in the array such that the new number is one more than the odd number.*/
void insertNum(int list[], int &count);

//This function counts the number of even numbers in your array and returns it.
int evenCount(int list[], int count);

//main.   DO NOT CHANGE THIS
int main()
{
	//DO NOT CHANGE MAIN
	int list[CAP], count = 0, even = 0;
	buildList(list, count);
	cout << "Original List!" << endl;
	printList(list, count);
	insertNum(list, count);
	cout << "List after inserts!" << endl;
	printList(list, count);
  even = evenCount(list, count);
  cout << "Count of even numbers = " << even << endl;
	return 0;
}

//function to build list.  DO NOT CHANGE THIS
//Takes the array and an int by reference.
void buildList(int list[], int &count)
{
	srand(time(NULL));
	count = 10;
	for (int i = 0; i < count; i++)
	{
		list[i] = rand() % 100;
	}
}

//function to print list.  DO NOT CHANGE THIS
//Takes the array by reference and an int by value.
void printList(int list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << list[i] << endl;
	}
}

void insertNum(int list[], int &count) {
    int pos = 0;
    for (int i = 0; i < count; i++) {
        if (list[i] % 2 == 1)
            pos = i;
            break;                
    }
    for (int j = count - 1; j > pos; j++) {
        list[j] = list[j - 1];
    }
    list[pos + 1] += 1;
    count++;
}

int evenCount(int list[], int count) {
    int evenNums = 0;
    for (int i = 0; i < count; i++) {
        if (list[i] % 2 == 0)
            evenNums++;
    }
    return evenNums;
}