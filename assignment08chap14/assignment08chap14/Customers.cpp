#include "Customers.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

Customers::Customers(const string& cID, const string& FName, const string& Lname, const string& stA, const string& cty, const string& st, const string& zp)
	: customerID(cID), firstName(FName), lastName(Lname), streetAddress(stA), city(cty), state(st), zip(zp) {

}

void Customers::setCustomerID(const string customerID) { this->customerID = customerID; }
void Customers::setFirstName(const string firstName) { this->firstName = firstName; }
void Customers::setLastName(const string lastName) { this->lastName = lastName; }
void Customers::setStreetAddress(const string streetAddress) { this->streetAddress = streetAddress; }
void Customers::setCity(const string city) { this->city = city; }
void Customers::setState(const string state) { this->state = state; }
void Customers::setZip(const string zip) { this->zip = zip; }

string Customers::getCustomerID() { return customerID; }
string Customers::getFirstName() { return firstName; }
string Customers::getLastName() { return lastName; }
string Customers::getStreetAddress() { return streetAddress; }
string Customers::getCity() { return city; }
string Customers::getState() { return state; }
string Customers::getZip() { return zip; }


string Customers::toString() const {
	ostringstream output;

	output << "Customer ID: " << customerID << "\nCustomer's Name: " << firstName << " " << lastName
		<< "\nAddress: " << streetAddress << "\nCity: " << city << "\nState: " << state << "\nZip: " << zip << endl << endl;

	return output.str();
}

string Customers::uniqueCities() const {
	ostringstream output;

	output << city;
	return output.str();
}

string Customers::uniqueStates() const {
	ostringstream output;

	output  << state;
	return output.str();
}