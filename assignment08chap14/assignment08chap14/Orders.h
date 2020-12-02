#pragma once
#include <iostream>
using namespace std;
class Orders
{
private:
	string orderID, customerID, productID, quantity, orderTotal;

public:
	Orders(const string&, const string&, const string&, const string&, const string&);

	void setOrderID(const string);
	void setCustomerID(const string);
	void setProductID(const string);
	void setQuantity(const string);
	void setOrderTotal(const string);

	string getOrderID();
	string getCustomerID();
	string getProductID();
	string getQuantity();
	string getOrderTotal();

	string toString() const;
};

