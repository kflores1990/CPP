/*
Assignment 15 chapter 21 by Kyle Flores 
this assignment demonstrates various string operations and processes.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string text1, text2, text3, concat1, concat2;
	concat1 = "the quick brown";
	concat2 = "jumps over the lazy";

	cout << "\nEnter a string: ";
	getline(cin, text1);//assign1
	text2 = text1;//assign2
	text3.assign(text1);//assign3

	cout << "\nText 1: " << text1 << "\nText 2 via txt2 = txt1: " << text2 << "\nText 3 via .assign(txt1): " << text3 << endl;
	cout << "Premade concat1 prior concat: " << concat1 << "\nPremade concat2 prior concat: " << concat2 << endl;

	concat1 = { concat1 + ' ' + text1 };
	concat2 += ' '+ text2;
	cout << "Premade concat1 post concat: " << concat1 << "\nPremade concat2 post concat: " << concat2 << endl;
	
	cout << "\nChoose which part of concat 1 to compare with concat 2\nInput two ints from size: 0 to " << concat1.size() << " for comparison values." << endl;
	int x, y;
	cin >> x >> y;
	string compare1, compare2;
	compare1.append(concat1, x, y);

	cout << "\nChoose which part of concat 2 to compare with concat 1\nInput two ints from size: 0 to " << concat2.size() << " for comparison values." << endl;
	cin >> x >> y;
	compare2.append(concat2, x, y);
	cout << "\nComparing the values: " << compare1 << " and " << compare2 << endl;
	cout << "The comparison is "<<  (compare1 == compare2 ? " the same" : " not the same") << endl;

	cout << endl;
	string::const_iterator iterator1{ text1.begin() };
	while (iterator1 != text1.end()) {
		cout << *iterator1;
		++iterator1;
	}
	cout << endl;

	string::reverse_iterator iterator2{ text2.rbegin() };
	while (iterator2 != text2.rend()) {
		cout << *iterator2;
		++iterator2;
	}
	cout << endl;
	ostringstream outputString;
	outputString << "Demo with ouput string stream (text1/2/3):  " << text1 << ' ' << text2 << ' ' << text3 << ' ' << endl;
	cout <<"Uses the "<< outputString.str();
	
	cout << "\nTest the istringstream, input a string with 3 words: ";
	
	cin.ignore();
	
	string userInput;
	getline(cin, userInput);
	istringstream inputString{ userInput };
	string s1, s2, s3;
	inputString >> s1 >> s2 >> s3;
	cout << s1 << ' ' << s2 << ' ' << s3;

	cout << "\nReading the statements file" << endl;
	ifstream statementsFile("statements.txt");
	while (getline(statementsFile, s1)) {
		cout << s1 << endl;
	}
	statementsFile.close();
	system("pause");
}



