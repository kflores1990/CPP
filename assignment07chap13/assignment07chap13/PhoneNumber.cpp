#include "PhoneNumber.h"
#include<iomanip>
using namespace std;




ostream& operator<<(ostream& output, const PhoneNumber& number) {


	output << "\nArea Code:";
	output.write(number.areaCode, 4);
	output << "\n";
	output << "\nExchange:";

	output.write(number.exchange, 4);
	output << "\n";

	output << "\nLine:";
	output.write(number.line, 5);
	output << "\n";

	output << "\nThe phone you entered was: ";

	output.write(number.phone, 15);

	return output;
}

istream& operator>>(istream& input, PhoneNumber& number) {
	char rightP, leftP, dash;

	input >> setw(1) >> leftP;
	if (leftP != '(') {
		input.setstate(ios::failbit);
		return input;
	}

	input >> skipws >> setw(4) >> number.areaCode;
	if (number.areaCode[0] == '0' || number.areaCode[0] == '1') {
		input.setstate(ios::failbit);
		return input;
	}


	input >> setw(1) >> rightP;
	if (rightP != ')') {
		input.setstate(ios::failbit);

		return input;
	}
	input >> setw(4) >> number.exchange;

	if (number.exchange[0] == '0' || number.exchange[0] == '1') {
		input.setstate(ios::failbit);
		return input;
	}



	input >> setw(1) >> dash;
	if (dash != '-') {
		input.setstate(ios::failbit);
		return input;
	}


	input >> setw(5) >> number.line;

	number.phone[0] = leftP;
	for (int x = 0; x <= 3; x++) {
		number.phone[x + 1] = number.areaCode[x];
	}
	number.phone[4] = ')';
	number.phone[5] = ' ';
	for (int x = 0; x <= 3; x++) {
		number.phone[x + 6] = number.exchange[x];
	}
	number.phone[9] = '-';
	for (int x = 0; x <= 4; x++) {
		number.phone[x + 10] = number.line[x];
	}

	if(input.peek() != '\n'){
		input.setstate(ios::failbit);
		return input;
	}


	return input; 
}
