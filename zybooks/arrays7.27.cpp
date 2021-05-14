// Implement the for loop in the function delItem to remove a value in a certain index by shifting the values from the last element in the array.



//This program has a list of integers and your job is to fill in the function to remove a number at the given position
#include <iostream>
using namespace std;

void delItem(int list[], int& count, int delIndex);

int main() {
	const int NUM_VALS = 10;
	int list[NUM_VALS] = { 7, 12, 34, 15, 9, 10, 3, 0, 0, 0};
	int i = 0, count = 7;
	cout << "List before remove: " << endl;
	for (i = 0; i < count; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
	delItem(list, count, 3);
	delItem(list, count, 4);
	cout << "List after 2 removes: " << endl;
	for (i = 0; i < count; i++)
	{
		cout << list[i] << " ";
	}

	return 0;
}

void delItem(int list[], int& count, int delIndex)
{
    for (int i = delIndex; i < count - 1; i++) {
        list[i] = list[i + 1];
        list[i + 1] = 0;
    }
    count -= 1;
}