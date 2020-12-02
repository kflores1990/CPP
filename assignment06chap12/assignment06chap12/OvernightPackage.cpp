#include "OvernightPackage.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
//	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

OvernightPackage::OvernightPackage(const string& senderName, const string& senderAddress, const string& senderCity, const string& senderState, const string& senderZip,
	const string& receiverName, const string& receiverAddress, const string& receiverCity, const string& receiverState, const string& receiverZip,
	double weight, double costPerOunce, double onR)
	: Package(senderName, senderAddress, senderCity, senderState, senderZip,
		receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
		weight, costPerOunce) {
	setOvernightRate(onR);
}


void OvernightPackage::setOvernightRate(double overnightRate) {
	this->overnightRate = overnightRate;
}
double OvernightPackage::getOvernightRate() {
	return overnightRate;
}
double OvernightPackage::calculateCost() const{
	return overnightRate * weight * costPerOunce;
}

string  OvernightPackage::toString() const {
	ostringstream output;

	output << "\n\nSenders Name: " << senderName << fixed << setw(20) << "Senders Address: " << senderName << "\nSenders City: " << senderCity << fixed << setw(20) << "Senders State: " << senderState << "\nSenders Zip: "
		<< senderZip
		<< "\n\nReceivers Name: " << receiverName << fixed << setw(20) << "Receivers Address: " << receiverName << "\nReceivers City: " << receiverCity << fixed << setw(20) << "Receivers State: " << receiverState << fixed << setw(20) << "\nReceivers Zip: "
		<< receiverZip
		<< "\n\nWeight " << setprecision(2) << weight << "\nCost per Ounce: " << setprecision(2) << costPerOunce <<"\nOvernight Rate: " << overnightRate<< " per ounce" <<"\nTotal: "
		<< setprecision(2) << calculateCost();
	return output.str();
}

