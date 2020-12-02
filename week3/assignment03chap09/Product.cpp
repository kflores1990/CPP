#include<iostream>
#include <sstream>
#include "Product.h"
using namespace std;


unsigned int Product::productCount{ 0 };
unsigned int Product::getProductCount() { return productCount; };

Product::Product(int& pNum, string& pName, string& pDesc, string& pCT)
	:productNum(pNum), productName(pName), productDescription(pDesc), productCreationTime(pCT) {
	++productCount;
}

Product::~Product(){--productCount;}

int Product::getProductNum() { return productNum; }
string Product::getProductName() { return productName; }
string Product::getProductDescription() { return productDescription; }
string Product::getProductCreationTime() { return productCreationTime; }

string Product::toString() const {
	ostringstream output;
	output << productNum << " " << productName << "\n" << productDescription << "\n" << productCreationTime;
	return output.str();
}
