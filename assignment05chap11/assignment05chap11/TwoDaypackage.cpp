#include "TwoDaypackage.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

TwoDaypackage::TwoDaypackage(string& senderName, string& senderAddress, string& senderCity, string& senderState, string& senderZip,
	string& receiverName, string& receiverAddress, string& receiverCity, string& receiverState, string& receiverZip,
	double weight, double costPerOunce, double tDF)
	: Package(senderName, senderAddress, senderCity, senderState, senderZip,
		receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
		weight, costPerOunce) {

	setTwoDayFee(tDF);

}
void TwoDaypackage::setTwoDayFee(double TwoDayFee) {
	this->twoDayFee = TwoDayFee;
}

double TwoDaypackage::getTwoDayFee() {
	return twoDayFee;
}

double TwoDaypackage::calculateCost() {
	return twoDayFee+(weight * costPerOunce);

}

string TwoDaypackage::toString() {
	ostringstream output;
	output << "\n\nSenders Name: " << senderName << fixed << setw(20) << "Senders Address: " << senderAddress << "\nSenders City: " << senderCity << fixed << setw(20) << "Senders State: " << senderState << "\nSenders Zip: "
		<< senderZip
		<< "\n\nReceivers Name: " << receiverName << fixed << setw(20) << "Receivers Address: " << receiverAddress << "\nReceivers City: " << receiverCity << fixed << setw(20) << "Receivers State: " << receiverState << fixed << setw(20) << "\nReceivers Zip: "
		<< receiverZip
		<< "\n\nWeight " << setprecision(2) << weight << "\nCost per Ounce: " << setprecision(2) << costPerOunce << "\nTwo Day Fee: " << twoDayFee << "\nTotal: "
		<< setprecision(2) << TwoDaypackage::calculateCost();
	return output.str();
}

