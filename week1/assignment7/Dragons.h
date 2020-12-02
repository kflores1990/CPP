#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
#pragma once

class Dragons
{
private:
	int dVal;
	

public: 
	Dragons(int dVal) {
		this->dVal = dVal;
		dragArray(dVal);
	}

	int getdVal() {
		return dVal;
	}

	void dragArray(int aLen) {
		string dNam;
		string *dArr = new string [aLen];
		for (int x = 0; x < aLen; x++) {
			cout << "Name of Dragon " << x + 1 << ": ";
			cin >> dNam;
			dArr[x] = dNam;
		}
		
		
	}


};

