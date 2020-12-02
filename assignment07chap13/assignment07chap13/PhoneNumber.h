
#pragma once
#include <iostream>
#include<string>
class PhoneNumber
{
private:
	//std::string areaCode;
	//std::string exchange;
	//std::string line;
	char phone[30];
	char areaCode[4];
	char exchange[4];
	char line[5];
public:

	friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);

	friend std::istream& operator>>(std::istream&, PhoneNumber&);
};

