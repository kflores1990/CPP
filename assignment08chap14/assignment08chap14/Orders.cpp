#include "Orders.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;
string orderID, customerID, productID, quantity, orderTotal;

Orders::Orders(const string& oID, const string& cID, const string& pID, const string& quant, const string& oT)
	:orderID(oID), customerID(cID), productID(pID), quantity(quant), orderTotal(oT){}

void Orders::setOrderID(const string orderID) { this->orderID = orderID; }
void Orders::setCustomerID(const string customerID) { this->customerID = customerID; }
void Orders::setProductID(const string productID) { this->productID = productID; }
void Orders::setQuantity(const string quantity) { this->quantity = quantity; }
void Orders::setOrderTotal(const string orderTotal) { this->orderTotal = orderTotal; }

string Orders::getOrderID() { return orderID; }
string Orders::getCustomerID() { return customerID; }
string Orders::getProductID() { return productID; }
string Orders::getQuantity() { return quantity; }
string Orders::getOrderTotal() { return orderTotal; }

string Orders::toString() const {

	 
	ostringstream output;

	output << "Customer's ID: " << customerID << "\nOrder ID: " << orderID << "\nProduct ID: " << productID
		<< "\nQuantity: " << quantity << "\nOrder Total: " << orderTotal << endl << endl;

	return output.str();
}