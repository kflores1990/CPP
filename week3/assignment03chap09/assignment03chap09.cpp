//Kyle Flores assignment 03 chapter 9
#include "Order.h"
#include "Product.h"
#include "Customer.h"

#include <string>
#include <iostream>
#include <ctime>
#include <typeinfo>
using namespace std;

vector<Product> productEntry();
vector<Product> productTracker(Product);

vector<Customer> customerEntry();
vector<Order> orderEntry();

string captureTime();

void reports(vector<Customer>);
void reports(vector<Product>);
void reports(vector<Order>);


int main()
{

	vector<Customer> c1;
	vector<Order> o1;
	vector<Product> p1;

	c1 = customerEntry();
	o1 = orderEntry();
	p1 = productEntry();
	
	reports(c1);
	reports(o1);
	reports(p1);
}

//whiles are repetive ---improve functionality
 vector<Product> productEntry(){
	bool addAnother = true;
	char addVal = 'y';
	int pNum;
	string pName, pDesc, pCreationTime;
	vector<Product> p1;
	
	while (addAnother) {
		cout << "Enter Product Number: ";
		cin >> pNum;
		cin.ignore();
		cout << "Enter Product Name: ";
		getline(cin, pName);
		cout << "Enter Product Description: ";
		getline(cin, pDesc);
		pCreationTime = captureTime();



		Product prod{ pNum, pName, pDesc, pCreationTime };

		p1 = productTracker(prod);
		cout << "Add another (y/n)";
		cin >> addVal;
		addAnother = addVal == 'y' ? true : false;
		if (addAnother == false) { return p1; }
	}///////////////end while///////////////////////

}
 vector<Product> productTracker(Product a) {
	 static vector <Product> allProducts;
	 allProducts.push_back(a);


	 return allProducts;
 }
 
vector<Customer> customerEntry() {
	vector <Customer> custs;
	bool addAnother = true;
	char addVal = 'y';
	int cNum;
	Customer c1();
	string cName, address, cCreationTime;
	while (addAnother) {
		cout << "Enter Customer Number: ";
		cin >> cNum;
		cin.ignore();
		cout << "Enter Customer Full Name: ";
		getline(cin, cName);
		cout << "Enter Customers Address: ";
		getline(cin, address);
		cCreationTime = captureTime();



		Customer cust{ cNum, cName, address, cCreationTime };
		cust.setOrderNums(cust);
		custs.push_back(cust);

		cout << "Add another (y/n)";
		cin >> addVal;
		addAnother = addVal == 'y' ? true : false;
		if (addAnother == false) { return custs; }
	}///////////////end while///////////////////////
}
vector<Order> orderEntry(){
	bool addAnother = true;
	char addVal = 'y';
	int oNum, oID;
	string oCreationTime;


	while (addAnother) {
		cout << "Enter Order Number: ";
		cin >> oNum;
		cin.ignore();
		cout << "Enter Customer ID number: ";
		cin >> oID;

		oCreationTime = captureTime();

		Order orders{ oNum, oID, oCreationTime };
		orders.setProductNums(orders);
		
		cout << "Add another (y/n)";
		cin >> addVal;
		addAnother = addVal == 'y' ? true : false;
		if (addAnother == false) { return orders.getProductNums(); }

	}///////////////end while///////////////////////

}

string captureTime() {
	time_t result = time(NULL);
	char cArr[26];
	ctime_s(cArr, sizeof cArr, &result);
	string timeStr = "";
	for (auto&& c : cArr) { timeStr = timeStr + c; }
	return timeStr;
}



void reports(vector<Customer> c1){
	cout << "Customer count: " << c1.size();
	for (auto&& c : c1) { cout << c.toString(); }

}
void reports(vector<Product> p1) {
	cout << endl<< "Product count: " << p1.size() << endl;

	for (auto&& p : p1) { cout << p.toString(); }
}
void reports(vector<Order> o1) {
	cout << "Order count: " << o1.size();

	for (auto&& o : o1) { cout << o.toString(); }
}