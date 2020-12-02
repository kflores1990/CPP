#include <iostream>
#include <iomanip>
using namespace std;
#pragma once

class CharInfo
{
private:
	string charName;

public: 
	CharInfo(string charName) {
		this->charName = charName;
	}

	
	string getCharInfo() {
		return charName;
	}
	
};

