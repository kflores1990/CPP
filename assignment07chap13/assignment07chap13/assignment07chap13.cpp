// assignment07chap13.cpp 
/*Kyle Flores project 7 chapter 13 advanced C++. 
This assignment demonstrates the purpose of streams and overloaded stream operators. 
begining with code fig 10.3, 10.4, 10.5 modify the code as follows
phoneNumber calss should include the following member data:
Private:
char phone[15]; holds entire phone number plus \O
char areaCode[4];//holds area plus \O
char exchange[4];holds....
char line[5]holds....

*/
#include <iostream>
#include <iomanip>
#include "PhoneNumber.h"
using namespace std;
void introduction();

int main()
{
	introduction();
	string str;
	PhoneNumber phone;

	bool again = false;
	char cRepeat = 'y';

	while (cRepeat == 'y') {

		cout << "\nEnter a phone number in the format: (888) 555-1234:";

		cin >> skipws >> phone;


		if (cin.fail() == false) {

			cout << "The phone number entered was:" << endl;
			cout << phone;

		}
		 
		else {
			cout << "\nIncorrect phone number input. " << '\n';
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


		cout << "\nRepeat (y/n): ";
		cin >> cRepeat;
		
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	cout << "\n\n<ENTER> to exit: ";
	cin.get();
}


void introduction() {
	cout << "Kyle Flores project 7 chapter 13 advanced C++.This assignment demonstrates the purpose of streams and overloaded stream operators.";

}