/*
Kyle Flores assignment 08 chapter 14 demonstrates i/o operations of files. 
It allows you to search through a customer (premade) master txt file that contains
deliminated variables by a %. Additionally two further text files 
(products and orders) are created, added, and manipulated. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

#include "Customers.h"
#include "Products.h"
#include "Orders.h"

using namespace std;

void introduction();
void menuOptions();

vector<Customers*> returnCustomerFile();
vector<Orders*> returnOrderFile();
vector<Products*> returnProductFile();

void printCities(vector<Customers*>);
void printStates(vector<Customers*>);
void printAllRecords(vector < Customers*>);
void RecordsInSpecCity(vector<Customers*>);
void RecordsInSpecState(vector<Customers*>);

void inputOrders();
void writeOrders(vector<Orders*>);
void readOrders(vector<Orders*>);
void readOrdersCID(vector<Orders*>);
void readOrdersZip(vector<Customers*>, vector<Orders*>);

void inputProducts();
void writeProducts(vector<Products*>);
void readProducts();

//----------------MAIN-----------------//
int main()
{
	introduction();

	vector<Customers*> mainCustomerVec;
	vector<Orders*> mainOrdersVec;
	vector<Products*> mainProductsVec;

	mainCustomerVec = returnCustomerFile();
	mainOrdersVec = returnOrderFile();
	mainProductsVec = returnProductFile();

	char again = 'y';
	int option = 0;
	while (again == 'y') {
		menuOptions();
		cin >> option;

		switch (option)
		{
		case 1:
			printCities(mainCustomerVec);
			break;
		case 2:
			printStates(mainCustomerVec);
			break;
		case 3:
			cin.ignore();
			RecordsInSpecCity(mainCustomerVec);
			break;
		case 4:
			RecordsInSpecState(mainCustomerVec);
			break;
		case 5:
			readOrdersCID(mainOrdersVec);
			break;

		case 6:
			readOrdersZip(mainCustomerVec, mainOrdersVec);
			break;
		case 7:
			cin.ignore();
			inputProducts();
			mainProductsVec.clear();
			mainProductsVec = returnProductFile();
			break;
		case 8:
			cin.ignore();
			inputOrders();
			mainOrdersVec.clear();
			mainOrdersVec = returnOrderFile();
			break;
		}
		cout << "Another menu option(y/n): ";
		cin >> again;
	}
}





//----------------------INTRO/MENU---------------------------//
void introduction() {
	cout << "Kyle Flores assignment 08 chapter 14 demonstrates i / o operations of files."
		"\nIt allows you to search through a customer(premade) master txt file that contains"
		"\ndeliminated variables by a % .Additionally two further text files"
		"\n(products and orders) are created, added, and manipulated.\n";
}
void menuOptions() {
	cout << "Which option would you like: ";
	cout << "\nOption 1:::List of cities in CustomerMaster.txt::: ";
	cout << "\nOption 2:::List of states in CustomerMaster.txt::: ";
	cout << "\nOption 3:::All customer records in a city:::";
	cout << "\nOption 4:::All cusomer records in a state";
	cout << "\nOption 5:::All orders associated with a customer by CustomerID";
	cout << "\nOption 6:::All orders associated with a customer by ZipCode";
	cout << "\nOption 7:::Add products to the Products";
	cout << "\nOption 8:::Add orders to the Orders\n";
}



//----------------------READ FILE FUNCTIONS--------------------//

vector<Customers*> returnCustomerFile() {
	vector<Customers*> CustomerVec;
	string str, temp_CID, temp_FN, temp_LN, temp_ADDRESS, temp_CITY, temp_ST, temp_ZIP;
	ifstream CustomerFile("CustomerMaster.txt");
	if (CustomerFile.is_open()) {
		while (getline(CustomerFile, str)) {
			stringstream ss(str);
			getline(ss, temp_CID, '%');
			getline(ss, temp_FN, '%');
			getline(ss, temp_LN, '%');
			getline(ss, temp_ADDRESS, '%');
			getline(ss, temp_CITY, '%');
			getline(ss, temp_ST, '%');
			getline(ss, temp_ZIP, '%');
			CustomerVec.push_back(new Customers{ temp_CID, temp_FN, temp_LN, temp_ADDRESS, temp_CITY, temp_ST, temp_ZIP });
		}
	}
	else {
		cout << "The file did not open properly, please check the location";
	}
	CustomerFile.close();
	return CustomerVec;
}
vector<Orders*> returnOrderFile() {
	
	vector<Orders*> OrderVec;
	
	string str, temp_orderID, temp_customerID, temp_productID, temp_quantity, temp_orderTotal;

	ifstream OrderIn("Orders.txt");
	
	
	if (OrderIn.is_open()) {
		while (getline(OrderIn, str)) {
			stringstream ss(str);
			getline(ss, temp_customerID, '%');
			getline(ss, temp_orderID, '%');
			getline(ss, temp_productID, '%');
			getline(ss, temp_quantity, '%');
			getline(ss, temp_orderTotal, '%');

			OrderVec.push_back(new Orders{ temp_orderID, temp_customerID, temp_productID, temp_quantity, temp_orderTotal });
		}
	}
	else {
		cout << "The file did not open properly, please check the location";
	}
	OrderIn.close();
	return OrderVec;
}
vector<Products*> returnProductFile() {
	vector<Products*> ProductVec;
	
	string str, temp_productID, temp_description, temp_price;
	
	ifstream ProductIn("Products.txt");
	
	if (ProductIn.is_open()) {
		while (getline(ProductIn, str)) {
			stringstream ss(str);
			getline(ss, temp_productID, '%');
			getline(ss, temp_description, '%');
			getline(ss, temp_price, '%');

			ProductVec.push_back(new Products{ temp_productID, temp_description, temp_price });
		}
	}
	else {
		cout << "The file did not open properly, please check the location";
	}
	ProductIn.close();
	return ProductVec;
}

//----------------------CUSTOMER FUNCTIONS--------------------//

void printCities(vector<Customers*>  customersVec) {
	vector<string> uniqueCities;
	for (int x = 0; x <= customersVec.size() - 1; x++) {
		string temp_CITY = customersVec[x]->getCity();
		if (find(uniqueCities.begin(), uniqueCities.end(), temp_CITY) != uniqueCities.end()) {
		}
		else {
			uniqueCities.push_back(temp_CITY);
		}
	}

	sort(uniqueCities.begin(), uniqueCities.end());
	for (auto&& uc : uniqueCities) {
		cout << uc << endl;
	}
}
void printStates(vector<Customers*> customersVec) {
	vector<string> uniqueStates;
	for (int x = 0; x <= customersVec.size() - 1; x++) {
		string temp_ST = customersVec[x]->getState();
		if (find(uniqueStates.begin(), uniqueStates.end(), temp_ST) != uniqueStates.end()) {
		}
		else {
			uniqueStates.push_back(temp_ST);
		}
	}

	sort(uniqueStates.begin(), uniqueStates.end());
	for (auto&& us : uniqueStates) {
		cout << us << endl;
	}
}
void printAllRecords(vector<Customers*> customersVec) {
	for (auto&& cv : customersVec) {
		cout << cv->toString();
	}
}
void RecordsInSpecCity(vector<Customers*> customersVec) {
	string inCity;
	cout << "\nWhat city do you want records from: ";
	getline(cin, inCity);
	cout << "\nLooking for customers in the city of: " << inCity << endl;
	vector<string> recordInCity;
	for (int x = 0; x <= customersVec.size() - 1; x++) {
		string recordsCity = customersVec[x]->getCity();
		if (recordsCity.compare(inCity) == 0) {
			cout << customersVec[x]->toString();

		}
	}
}
void RecordsInSpecState(vector<Customers*> customersVec) {
	string inState;
	cout << "\nWhat State do you want records from: ";
	cin >> inState;
	cout << "\nLooking for: " << inState << " records\n";

	vector<string> recordInSate;
	for (int x = 0; x <= customersVec.size() - 1; x++) {
		string recordsSate = customersVec[x]->getState();
		if (recordsSate.compare(inState) == 0) {
			cout << customersVec[x]->toString();

		}
	}
}


//----------------------ORDERS FUNCTIONS--------------------//
void inputOrders() {
	string temp_orderID, temp_customerID, temp_productID, temp_quantity, temp_orderTotal;
	vector<Orders*> inputOrdersVec;
	char again = 'y';
	while (again == 'y') {
		cout << "Order ID: ";
		cin >> temp_orderID;

		cout << "Customer ID: ";
		cin >> temp_customerID;

		cout << "Product ID: ";
		cin >> temp_productID;

		cout << "Quantity: ";
		cin >> temp_quantity;

		cout << "Order Total: ";
		cin >> temp_orderTotal;

		inputOrdersVec.push_back(new Orders{ temp_orderID, temp_customerID, temp_productID, temp_quantity, temp_orderTotal });
		cout << "Add another (y/n): ";
		cin >> again;
	}
	//write orders
	writeOrders(inputOrdersVec);
}
void readOrders(vector<Orders*> OrdersVec) {

	
	for (auto&& Ov : OrdersVec) {
		cout << Ov->toString();
	}




}
void writeOrders(vector<Orders*> writeOrders) {
	ofstream productsFile("Orders.txt", fstream::app);
	for (auto&& wP : writeOrders) {
		productsFile << wP->getCustomerID()  << '%' << wP->getOrderID()   << '%' << wP->getOrderTotal()<< '%'<< wP->getProductID()<<'%'<<wP->getQuantity() << endl;
	}
}
void readOrdersCID(vector<Orders*> ordersVec) {
	string cID;
	cout << "\nWhat Customer ID do you want to see the orders from: ";
	cin >> cID;
	cout << "\nLooking for customer ID number: " << cID << " order records\n";
	
	
	for (int x = 0; x <= ordersVec.size() - 1; x++) {
		string ordersRecords = ordersVec[x]->getCustomerID();
		if (ordersRecords.compare(cID) == 0) {
			cout << ordersVec[x]->toString();
		}
	}
}
void readOrdersZip(vector<Customers*> customersVec, vector<Orders*> ordersVec) {
	string zip;
	cout << "\nWhat Customer ZIP do you want to see the orders from: ";
	cin >> zip;
	cout << "\nLooking for orders in zip code: " << zip << endl;
	vector<string> customersInZip;

	for (int x = 0; x <= customersVec.size() - 1; x++) {
		string zipRecords = customersVec[x]->getZip();
		if (zipRecords.compare(zip) == 0) {
			customersInZip.push_back(customersVec[x]->getCustomerID());
		}
	}
	
	for (int x = 0; x <= customersInZip.size()-1; x++) {
		for (int y = 0; y <= ordersVec.size() - 1; y++) {
			if (customersInZip[x].compare(ordersVec[y]->getCustomerID()) == 0) {
				cout << ordersVec[y]->toString();
			}
		}
	}
}

//----------------------PRODUCTS FUNCTIONS--------------------//
void inputProducts() {
	string temp_productID, temp_description, temp_price;
	
	vector<Products*> inputProductsVec;
	char again = 'y';
	while (again == 'y') {
		cout << "Product ID: ";
		cin >> temp_productID;
		cin.ignore();
		cout << "Product Description: ";
		getline(cin, temp_description);
		cout << "Price: ";
		cin >> temp_price;

		inputProductsVec.push_back(new Products{ temp_productID, temp_description, temp_price });
		cout << "Add another (y/n): ";
		cin >> again;
	}
	//write products
	writeProducts(inputProductsVec);
}
void writeProducts(vector<Products*> writeProducts) {
	ofstream productsFile("Products.txt", fstream::app);
	for (auto&& wP : writeProducts) {
		productsFile << wP->getProductID() << '%' << wP->getDescription() << '%' << wP->getPrice() << endl;
	}
}
void readProducts() {

	string str, temp_PID, temp_Desc, temp_Price;
	ifstream masterTxtIn("Products.txt");
	vector<Products*> readProdVec;
	if (masterTxtIn.is_open()) {
		while (getline(masterTxtIn, str)) {
			stringstream ss(str);
			getline(ss, temp_PID, '%');
			getline(ss, temp_Desc, '%');
			getline(ss, temp_Price, '%');

			readProdVec.push_back(new Products{ temp_PID, temp_Desc, temp_Price });
		}
	}
	for (auto&& rpv : readProdVec) {
		cout << rpv->toString();
	}




}