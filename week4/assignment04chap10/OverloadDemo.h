#pragma once
#include <string>
#include <iostream>
using namespace std;
class OverloadDemo
{
private:
	int intOne;
	double doubleOne; 
	string stringOne;
public:
	
	OverloadDemo(int, double, string);

	void setIntOne(int);
	int getIntOne();
	double getDoubleOne();
	string getStringOne();

	OverloadDemo operator + (const OverloadDemo& rhs);
	OverloadDemo operator - (const OverloadDemo& rhs);
	OverloadDemo operator * (const OverloadDemo& rhs);
	OverloadDemo operator / (const OverloadDemo& rhs);
	OverloadDemo operator++(int);
	OverloadDemo operator--(int);


	void print(char);
};

