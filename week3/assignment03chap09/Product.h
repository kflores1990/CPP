#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Product
{
private:
    int productNum;
    string productName, productDescription, productCreationTime;
    static unsigned  int productCount;

public:
    Product(int&, string&, string&, string&);
    ~Product();
    int getProductNum();
    string getProductName();
    string getProductDescription();
    string getProductCreationTime();
    static unsigned int getProductCount();
    string toString() const;

};

