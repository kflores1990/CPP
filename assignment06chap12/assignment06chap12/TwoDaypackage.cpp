#include "TwoDaypackage.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

TwoDaypackage::TwoDaypackage(const string& senderName, const string& senderAddress, const string& senderCity, const string& senderState, const string& senderZip,
	const string& receiverName, const string& receiverAddress, const string& receiverCity, const string& receiverState, const string& receiverZip,
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

double TwoDaypackage::calculateCost() const {
	return twoDayFee + (weight * costPerOunce);

}

string TwoDaypackage::toString() const {
	ostringstream output;
	output << "\n\nSenders Name: " << senderName << fixed << setw(20) << "Senders Address: " << senderAddress << "\nSenders City: " << senderCity << fixed << setw(20) << "Senders State: " << senderState << "\nSenders Zip: "
		<< senderZip
		<< "\n\nReceivers Name: " << receiverName << fixed << setw(20) << "Receivers Address: " << receiverAddress << "\nReceivers City: " << receiverCity << fixed << setw(20) << "Receivers State: " << receiverState << fixed << setw(20) << "\nReceivers Zip: "
		<< receiverZip
		<< "\n\nWeight " << setprecision(2) << weight << "\nCost per Ounce: " << setprecision(2) << costPerOunce << "\nTwo Day Fee: " << twoDayFee << "\nTotal: "
		<< setprecision(2) << calculateCost();

	return output.str();
}

