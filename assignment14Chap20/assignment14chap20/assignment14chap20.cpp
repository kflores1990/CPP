/*
Kyle Flores assignment 14 chap 20
Rendition of assignment 13 chap 19 with added features of a 
	linear search
		selection sort
			merge sort
				binary search
*/

#include <iostream>
#include <ctime>
#include "List.h"
#include "ListNode.h"
#include <string>
using namespace std;
bool isInt(string val);


int main()
{

	string key = " ";
	int intConverter = 0;
	int choice = -1;
	List<int> intList;

	bool isRemoved = NULL; bool ValIsInt = true;
	while (choice != 0)
	{
		//menu of options to perform 
		cout << "Linked Lists" << endl;
		cout << "-----------------------" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Insert Front" << endl;//passed test
		cout << "2. Insert Back" << endl;//passed test
		cout << "3. Delete Front" << endl;//passed test
		cout << "4. Delete Back" << endl;//passed test
		cout << "5. Delete Index" << endl;//passed test
		cout << "6. Delete Value" << endl;//passed test
		cout << "7. Print list" << endl;//passed test
		cout << "8. Linear Search" << endl;//passed test
		cout << "9. Selection Sort" << endl;//passed test
		cout << "10. Merge Sort" << endl;//
		cout << "11. Binary Search" << endl;// passed test

		cout << "Enter Choice: ";
		cin >> choice;
		system("cls");




		switch (choice)
		{
		case 0:
			cout << "I can no longer serve you... good-bye. ";
			system("pause");
			system("cls");
			break;
		case 1:
			cout << "Insert Front" << endl;
			cout << "----------------" << endl;
			cin.ignore();
			try {
				getline(cin, key);


				ValIsInt = isInt(key);
				if (ValIsInt == true) {
					intConverter = stoi(key);
					intList.insertBegin(intConverter);
				}
				else { cout << "\nPlease enter an Int value instead.\n"; }


			}
			catch (exception e) {
				cout << "\ninvalid entry or no entry\n";

			}
			//system("pause");
			system("cls");
			break;

		case 2:
			try {
				cout << "Insert Back" << endl;
				cout << "------------------------" << endl;
				cin.ignore();
				getline(cin, key);
				ValIsInt = isInt(key);

				if (ValIsInt == true) {
					intConverter = stoi(key);
					intList.insertEnd(intConverter);
				}
				else { cout << "\nPlease enter an Int.\n"; }
			}
			catch (exception e) {
				cout << "\ninvalid entry or no entry\n";

			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "\nDelete Front" << endl;
			isRemoved = intList.removeFront();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "\nDelete Back" << endl;
			isRemoved = intList.removeBack();
			system("pause");
			system("cls");
			break;
		case 5:
			intList.removeIndex();
			system("pause");
			system("cls");
			break;
		case 6:
			try {
				cout << "\nInput a value: " << endl;
				cin.ignore();
				getline(cin, key);
				ValIsInt = isInt(key);
				if (ValIsInt == true) {
					intConverter = stoi(key);
					intList.removeValue(intConverter);
				}
				else { cout << "\nPlease enter an Int value instead.\n"; }
			}
			catch (exception e) {
				cout << "\ninvalid entry or no entry\n";

			}
			system("pause");
			system("cls");

			break;
		case 7:
			cout << "Print List" << endl;
			cout << "------------------------------" << endl;
			intList.print(); //prints contents of linked list
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "Linear Search" << endl;
			cout << "------------------------------" << endl;
			cout << "\nInput INT for search: "; 
			cin.ignore();
			getline(cin, key);
			ValIsInt = isInt(key);
			if (ValIsInt == true) {
				intConverter = stoi(key);
				intConverter = intList.LinearSearch(intConverter);
				if (intConverter >= 0) { cout << "\nIndex location: " << intConverter << " contains searched value\n"; }
				else { cout << "\nValue not found\n"; }
			}
			else { cout << "\nPlease enter an Int value instead.\n"; }
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "Selection Sort" << endl;
			cout << "------------------------------" << endl;
			isRemoved = intList.selectionSort();
			system("pause");
			system("cls");
			break;
		case 10:
			cout << "Merge Sort" << endl;
			cout << "------------------------------" << endl;
			cout << "\nList has " <<(intList.mergeSortList() == true ? "been " : "not been ") << "sorted. " << endl; 
			system("pause");
			system("cls");
			break;
		case 11:
			cout << "Binary Search" << endl;
			cout << "------------------------------" << endl;
			cout << "\nInsert INT for search: " << endl;
			cin.ignore();
			getline(cin, key);
			ValIsInt = isInt(key);

			if (ValIsInt == true) {
				intConverter = stoi(key);
				bool bSearch = intList.binarySearch(intConverter);
				cout << "\nValue is in list: " << boolalpha << bSearch << endl;
			}
			else { cout << "\nPlease Enter an INT value instead.\n"; }
			system("pause");
			system("cls");
			break;
		}
	}

}


bool isInt(string val) {
	for (size_t i = 0; i < val.length(); i++)
		if (isdigit(val[i]) == false)
			return false;
	return true;
}