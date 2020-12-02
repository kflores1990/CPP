#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class Customers
{
private:
	string customerID, firstName, lastName, streetAddress, city, state, zip;

public:

	Customers(const string&, const string&, const string&, const string&, const string&, const string&, const string&);

	void setCustomerID(const string);
	void setFirstName(const string);
	void setLastName(const string);
	void setStreetAddress(const string);
	void setCity(const string);
	void setState(const string);
	void setZip(const string);

	string getCustomerID();
	string getFirstName();
	string getLastName();
	string getStreetAddress();
	string getCity();
	string getState();
	string getZip();


	string toString() const;
	string uniqueCities() const;
	string uniqueStates() const;

};

