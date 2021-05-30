#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <array>

//*** CONSTANTS ***//

using namespace std;

//*** PROTOTYPES ***//
bool openFile(ifstream& inFile, char fileName[] = "hate-groups-2020.csv");
void listOrgs(ifstream& inFile, char orgTable[], int orgCount[], char userState[]);

//*** MAIN CODE ***//
int main() {

//*** VARIABLES *** //
ifstream inFile;
char userState[30] = "Oregon"; // change to user input for final //
char orgTable[1000][51], IdeologyTable[1000][51];
int orgCount[1000][51], ideologyCount[1000][51];

//*** FUNCTION CALLS ***//
if (!openFile(inFile)) {
    cout << "File failed to open" << endl;
    return 0;
}
else
    cout << "you opened the file, now what?" << endl;




    return 0;
}

//*** FUNCTION DEFINITIONS ***//
bool openFile(ifstream& inFile, char fileName[] = "hate-groups-2020.csv") {
	inFile.open(fileName);
	if (!inFile.is_open())
	{
		return false;
	}
	return true;
}

void listOrgs(ifstream& inFile, char orgTable[], int orgCount[], char userState[]) {
	int tempCount;
    char tempOrg[51];
    char tempIdeology[51];
    int countRows = 1;
    char state[31];
    bool matched = false;
    // Skip header
    inFile.ignore(300, '\n');
    // Search for the first match of userState, save first organization
    // to orgTable[]    
    do {
        inFile.ignore(100, ',');
        inFile.ignore(100, ',');
        inFile >> state >> tempOrg >> tempIdeology;
        inFile.ignore(100, ',');
        inFile.ignore(100, ',');
    } while (strcmp(state, userState) != 0);
    orgTable[0] = tempOrg;
    orgCount[0] = 1;
    while (!inFile.eof()) {
        // Find next matching state
        do {
            inFile.ignore(100, ',');
            inFile.ignore(100, ',');
            inFile >> state >> tempOrg >> tempIdeology;
            inFile.ignore(100, ',');
            inFile.ignore(100, ',');
        } while (strcmp(userState, state) != 0);
        for (int i = 0; i < countRows; i++) {
            if (strcmp(tempOrg, orgTable[i]) == 0) {
                orgCount[i]++;
                cout << "matched organization" << endl;
                matched = true;
                break;
            }
        }
        if (!matched) {
            orgTable[countRows] = tempOrg;
            orgCount[countRows] = 1;
            countRows++;
            cout << "adding new organization" << endl;
            matched = false;
        }
    }
}