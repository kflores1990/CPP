#include "OvernightPackage.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
//	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

OvernightPackage::OvernightPackage(string& senderName, string& senderAddress, string& senderCity, string& senderState, string& senderZip,
	string& receiverName, string& receiverAddress, string& receiverCity, string& receiverState, string& receiverZip,
	double weight, double costPerOunce, double onR )
	: Package (senderName, senderAddress, senderCity, senderState, senderZip,
	receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
	weight, costPerOunce) {
	setOvernightRate(onR);
}


void OvernightPackage::setOvernightRate(double overnightRate){
	this->overnightRate = overnightRate;
}
double OvernightPackage::getOvernightRate() {
	return overnightRate;
}
double OvernightPackage::calculateCost() {
	return overnightRate * weight * costPerOunce;
}

string  OvernightPackage::toString() {
	ostringstream output;

	output << "\n\nSenders Name: " << senderName << fixed << setw(20) << "Senders Address: " << senderAddress << "\nSenders City: " << senderCity << fixed << setw(20) << "Senders State: " << senderState << "\nSenders Zip: "
		<< senderZip
		<< "\n\nReceivers Name: " << receiverName << fixed << setw(20) << "Receivers Address: " << receiverAddress << "\nReceivers City: " << receiverCity << fixed << setw(20) << "Receivers State: " << receiverState << fixed << setw(20) << "\nReceivers Zip: "
		<< receiverZip
		<< "\n\nWeight " << setprecision(2) << weight << "\nCost per Ounce: " << setprecision(2) << costPerOunce << "\nTotal: "
		<< setprecision(2) << OvernightPackage::calculateCost();
	return output.str();
}

