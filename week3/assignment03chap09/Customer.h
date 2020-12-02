#pragma once
#include <string>
#include <vector>
using namespace std;
class Customer
{

private: 
	string name, address, customerCreationTime;
	int custID;
	vector<Customer> orderNums;
	static unsigned int customerCount;
public:
	Customer(int&, string&, string&, string&);
	~Customer();
	string getName();
	string getAddress();
	string getCustomerCreationTime();
	int getCustID();

	void setOrderNums(Customer);
	vector<Customer> getOrderNums();
	static unsigned int getCustomerCount();
	string toString() const;
};
