//This program has a list of integers and your job is to fill in the function to insert a number at the given position
//You do not need to check for a valid position, meaning the value of pos in the insert function will be within the capacity 
//and size of the array.

#include <iostream>
using namespace std;

void insertItem(int list[], int& count, int val, int pos);

int main() {
	const int NUM_VALS = 10;
	int list[NUM_VALS] = { 7, 12, 34, 15, 9, 10, 3, 0, 0, 0};
	int i = 0, count = 7;
	cout << "List before inserts: " << endl;
	for (i = 0; i < count; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
	insertItem(list, count, 3, 0);
	insertItem(list, count, 4, 1);
	cout << "List after 2 inserts: " << endl;
	for (i = 0; i < count; i++)
	{
		cout << list[i] << " ";
	}
   
	return 0;
}

void insertItem(int list[], int& count, int val, int pos)
{
    for (int i = count - 1; i > pos; i--) {
        list[i] = list[i -1];
    }
    list[pos] = val;
}