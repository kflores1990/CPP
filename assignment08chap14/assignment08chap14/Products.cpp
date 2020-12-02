#include "Products.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

Products::Products(const string& prodID, const string& desc, const string& pr)
	:productID(prodID), description(desc), price(pr){}


void Products::setProductID(const string productID) { this->productID = productID; }
void Products::setDescription(const string description) { this->description = description; }
void Products::setPrice(const string price) { this->price = price; }

string Products::getProductID() { return productID; }
string Products::getDescription() { return description; }
string Products::getPrice() { return price; }



string Products::toString() const {
	ostringstream output;

	output << "Product ID: " << productID << "\nDescription: " << description 
		<< "\nPrice: " << price << endl << endl;

	return output.str();
}