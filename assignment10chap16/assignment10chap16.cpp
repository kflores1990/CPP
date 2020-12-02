/***Kyle Flores assignment 10 chapter 16
This program demonstrates algorithms from the Standard Library. 
content requirements is 
---four modifying sequence algorithms-----fill, generate unique, reverse
---six sorting and related algorithms-----sort, min, max, binary_search, includes, set_difference
---two numerical algorithms---------------accumulate, partial_sum
---four function objects------------------greater, less, multiplies, modulus
resimblence of assignment 08 - user populates containers 
output before and after algorithm results
***/

#include <iostream>
#include "modAlgos.h"

using namespace std;

void introduction();
void menu();


int main()
{
	introduction();
	bool again = false;
	int menuOptionInt;
	
	modAlgos mods;

	while (!again) {
		menu();

		cout << "\nSelect an option:  ";
		cin >> menuOptionInt;
		switch (menuOptionInt)
		{

			default:
				cout << "\nInvalid option";
				break;
			case 0:
				cout << "\nQuitting the program\n\n";
				again = false;
				break;

			case 1:
				mods.fillAlgo();
				break;

			case 2:
				mods.generateAlgoMinMax();
				break;

			case 3:
				mods.uniqueReverseSortAlgo();
				break;

			case 4:
				mods.searchAlgos();
				break;

			case 5:
				mods.funcAlgos();
				break;
		}
		again = menuOptionInt == 0 ? true : false;
	}

}


void introduction() {
	cout << "\nKyle Flores assignment 10 chapter 16 "
		"\nThis program demonstrates algorithms from the Standard Library."
		"\ncontent requirements is four modifying sequence algorithms"
		"\nsix sorting and related algorithms"
		"\ntwo numerical algorithms"
		"\nfour function objects"
		"\nresimblence of assignment 08 - user populates containers"
		"\noutput before and after algorithm results\n\n\n";
}
void menu() {
	cout << "\nMenu options:"
		"\n0: Terminates program."
		"\n1: Fill."
		"\n2: Generate,  min & max."
		"\n3: Unique, reverse, sort, partial_sum, accumulate, less & greater function object."
		"\n4: Search, binary_search, includes, set_difference."
		"\n5: Multiplies and Modulus function objects.";
}