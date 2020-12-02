//Kyle Flores assignment04 chapter 10 
/*
This program demonstrates the ability to overload operators. 
Class overload Demo contains 3 variables  getters/setters for each
+,-,*,/,prefix and postfix for increment and decrement 
*/

#include <iostream>
#include <vector>
#include <array>
#include "OverloadDemo.h"
using namespace std;
int main()
{
	cout << "Operator overload demo using the +, -, *, /" << endl;

	char arr[] = { '+', '-', '*', '/'};
	OverloadDemo p1(2, 4.4, "the quick"), p2(12, 6.9, "brown fox");
	vector<OverloadDemo> t1;


	t1.push_back(p1 + p2);	t1.push_back(p1 - p2);
	OverloadDemo p3 = p1;
	OverloadDemo p4 = p3;

	cout << endl << "P3 prior to increment operator: " << p3.getIntOne();
	cout << endl << "P4 prior to decrement operator:  " << p4.getIntOne();

	t1.push_back(p1 * p2);	t1.push_back(p1 / p2);
	t1.push_back(p3++); t1.push_back(p4--);

	cout << endl << "P3 prior to increment operator:  " << t1[4].getIntOne();
	cout << endl << "P4 prior to decrement operator:  " << t1[5].getIntOne() << endl;
		
	for (int i = 0; i < 4; i++) {
		t1[i].print(arr[i]);
	}
	
}