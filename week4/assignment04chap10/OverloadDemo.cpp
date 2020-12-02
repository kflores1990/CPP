#include "OverloadDemo.h"
using namespace std;
OverloadDemo::OverloadDemo(int i = 0, double d = 0.0, string s = "")
	:intOne(i), doubleOne(d), stringOne(s){}
void OverloadDemo::setIntOne(int a) { intOne = a; }

int OverloadDemo::getIntOne() { return intOne; }
double OverloadDemo::getDoubleOne() {return doubleOne;}
string OverloadDemo::getStringOne() { return stringOne; }


OverloadDemo OverloadDemo::operator + (const OverloadDemo& rhs) {
	OverloadDemo p;
	p.stringOne = stringOne + ' ' +rhs.stringOne;
	return p;
}
OverloadDemo OverloadDemo::operator - (const OverloadDemo& rhs) {
	OverloadDemo p;
	p.doubleOne = doubleOne - rhs.doubleOne;
	return p;
}
OverloadDemo OverloadDemo::operator * (const OverloadDemo& rhs) {
	OverloadDemo p;
	p.intOne = intOne * rhs.intOne;
	return p;
}
OverloadDemo OverloadDemo::operator / (const OverloadDemo& rhs) {
	OverloadDemo p;
	p.doubleOne = doubleOne / rhs.doubleOne;
	return p;
}
OverloadDemo OverloadDemo::operator++ (int) {
	OverloadDemo p;
	p = ++intOne;
	return p;
}
OverloadDemo OverloadDemo::operator-- (int) {
	OverloadDemo p;

	p = --intOne;
	return p;
}

//switch statement 
void OverloadDemo::print(char a) {
	switch (a)
	{
	case '+':
		cout << "Using Operator + on a String Overload: " << stringOne << endl;
		break;
	case '-':
		cout << "Using Operator - Overload: " << doubleOne << endl;
		break;
	case '*':
		cout << "Using Operator * Overload: " << intOne << endl;
		break;
	case '/':
		cout << "Using Operator / Overload: " << doubleOne << endl;
		break;
	
	default:
		break;
	}
}
