#include <iostream>
#include <sstream>
#include "Customer.h"
using namespace std;


unsigned int Customer::customerCount{0};
unsigned int Customer::getCustomerCount() { return customerCount; };

Customer::Customer(int& cID, string& fName, string& addy, string& cCT)
	:custID(cID), name(fName), address(addy), customerCreationTime(cCT){
}

Customer::~Customer() {--customerCount;}

string Customer::getName()  { return name; }
string  Customer::getAddress() { return address; }
string  Customer::getCustomerCreationTime() {return customerCreationTime;}
int  Customer::getCustID() {return custID;}

void Customer::setOrderNums(Customer a) {
	orderNums.push_back(a);
}
vector<Customer>  Customer::getOrderNums() { return orderNums; };

string Customer::toString() const {
	ostringstream output;
	output << custID << " " << name << "\n" << address << "\n" << customerCreationTime;
	return output.str();
}
/*
recevies orders from orders and updates orderNums vector with customers ordered orders
sends cID to orders to track created order
*/