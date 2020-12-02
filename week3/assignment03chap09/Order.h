#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Order
{
private:
	int orderNum, custID;
	string orderCreationTime;

	vector<Order> productNums;
	static unsigned int orderCount;

public:
	Order(int&, int&, string&);
	~Order();
	string getOrderCreationTime();
	int getOrderNum  ();
	int getCustID();

	void setProductNums(Order);
	vector<Order> getProductNums();
	static unsigned int getOrderCount();
	string toString() const;

};


