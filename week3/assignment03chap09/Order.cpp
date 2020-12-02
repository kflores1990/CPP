#include <iostream>
#include <sstream>
#include "Order.h"
using namespace std;

unsigned int Order::orderCount{ 0 };
unsigned int Order::getOrderCount() { return orderCount; };

Order::Order( int& oNum, int& cID, string& oCT)
	:orderNum(oNum), custID(cID), orderCreationTime(oCT){
	++orderCount;
}

Order::~Order() {--orderCount;}

string Order::getOrderCreationTime() { return orderCreationTime; }
int Order::getOrderNum() { return orderNum; }
int Order::getCustID() { return custID; }

void Order::setProductNums(Order a) { productNums.push_back(a); }
vector<Order> Order::getProductNums() { 	
	return productNums; 
}

string Order::toString() const {
	ostringstream output;
	output << orderNum << " " << custID << "\n" << orderCreationTime;
	return output.str();
}
