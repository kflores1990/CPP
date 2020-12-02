/*Kyle Flores Adv C++ chapter 7 assignment 1*/

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>

using namespace std;

bool introduction();
bool introduction2();

//void whileQuest();

int main()
{
	cout << "Character & Dragon data entry:\n";
	int dNum; int xtracker = 0; int etracker = 0;
	bool another1 = false;
	another1 = introduction();
	string charNames, dNames, kName, kArmy;

	array<array<string, 20>, 20> part1;

	///////////////////part 1 only 2d array/////////////////
	for (int x = 0; x < 20; x++) {
		if (another1 == false) { break; }

		cout << "Enter the character name: ";
		cin >> charNames;
		part1[x][0] = charNames;
		cout << "How many dragons would you like to enter for the character? ";
		cin >> dNum;
		if (dNum > 19) {
			cout << "max dragons is 20 your dragon count has been assigned to this.";
			dNum = 19;
		}
		for (int y = 1; y <= dNum; y++) {
			cout << "Enter the name of dragon " << y << ": ";
			cin >> dNames;
			part1[x][y] = dNames;
		}
		another1 = introduction();
		xtracker = x;
	}
	for (auto const& row: part1) {
		for (auto const& element : row) {
			if (element != "") {
				cout << element << ' ';
			}
		}
		if (etracker < xtracker) {
			cout << endl;
			etracker++;
		}
	}
	
	//////////////////part 2  only vector///////////////////
	bool another2 = introduction2();
	vector<vector<string>> part2A;

	for (int x = 0; x > -1; x++) {
		if (another2 == false) { break; }
		vector<string> part2temp;
		for (int i = 0; i < 1; i++) {
			cout << "Enter the Kingdom name:";
			cin >> kName;
			cout << "Enter Army size: ";
			cin >> kArmy;
			part2temp.push_back(kName);
			part2temp.push_back(kArmy);
		}
		part2A.push_back(part2temp);
		another2 = introduction2();

	}
	for (int x = 0; x < part2A.size(); x++) {
		for (int y = 0; y < part2A.size(); y++) {
			cout <<"\n" << part2A[x][y] << ": ";
		}
		cout << endl;
	}

	cin.get();
	return 0;
}


bool introduction() {
	char ans = 'n';
	cout << "Would you like to enter a character ? (y / n): ";
	cin >> ans;

	return (ans == 'y') ? true : false;
}
bool introduction2() {
	char ans = 'n';
	cout << "\nWould you like to enter a Kingdom Name? (y / n): ";
	cin >> ans;

	return (ans == 'y') ? true : false;
}


