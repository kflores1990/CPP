#pragma once
#include <iostream>
using namespace std;
class Products
{
private:
	std::string productID, description, price;


public:
	Products(const string&, const string&, const string&);

	void setProductID(const string);
	void setDescription(const string);
	void setPrice(const string);

	string getProductID();
	string getDescription();
	string getPrice();



	string toString() const;
};

