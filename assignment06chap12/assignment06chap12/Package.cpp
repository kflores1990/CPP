#include "Package.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>


Package::Package(const string& sN, const string& sA, const string& sC, const string& sS, const string& sZ, 
	const string& rN, const string& rA, const string& rC, const string& rS, const string& rZ,
	double oz, double cOz)
	: senderName(sN), senderAddress(sA), senderCity(sC), senderState(sS), senderZip(sZ),
	receiverName(rN), receiverAddress(rN), receiverCity(rC), receiverState(rS), receiverZip(rZ),
	weight(oz), costPerOunce(cOz) {

}

//-------------------SENDER---------------

void Package::setSenderName(const string senderName) { this->senderName = senderName; }
string Package::getSenderName() { return senderName; }

void Package::setSenderAddress(const string  address) { this->senderAddress = senderAddress; }
string Package::getSenderAddress() { return senderAddress; }

void Package::setSenderCity(const string  senderCity) { this->senderCity = senderCity; }
string Package::getSenderCity() { return senderCity; }

void Package::setSenderState(const string  senderState) { this->senderState = senderState; }
string Package::getSenderState() { return senderState; }

void Package::setSenderZip(const string  senderZip) { this->senderZip = senderZip; }
string Package::getSenderZip() { return senderZip; }

//------------------RECEIVER--------------
void Package::setReceiverName(const string  receiverName) { this->receiverName = receiverName; }
string Package::getReceiverName() { return receiverName; }

void Package::setReceiverAddress(const string  receiverAddress) { this->receiverAddress = receiverAddress; }
string Package::getReceiverAddress() { return receiverAddress; }

void Package::setReceiverCity(const string  receivercity) { this->receiverCity = receiverCity; }
string Package::getReceiverCity() { return receiverCity; }

void Package::setReceiverState(const string  receiverState) { this->receiverState = receiverState; }
string Package::getReceiverState() { return receiverState; }

void Package::setReceiverZip(const string  receiverZip) { this->receiverZip = receiverZip; }
string Package::getReceiverZip() { return receiverZip; }

//--------------END RECEIVER--------------
void Package::setWeight(double weight) { this->weight = weight; }
double Package::getWeight() { return weight; }
void Package::setCostPerOunce(double costPerOunce) { this->costPerOunce = costPerOunce; }
double Package::getCostPerOunce() { return costPerOunce; }


double Package::calculateCost() const{
	return weight * costPerOunce;
}

//set width and fortmat all sender information in rows and all receivers information in rows

string Package::toString() const {
	ostringstream output;

	output << "\n\nSenders Name: " << senderName << fixed << setw(20) << "Senders Address: " << senderAddress << "\nSenders City: " << senderCity << fixed << setw(20) << "Senders State: " << senderState << "\nSenders Zip: "
		<< senderZip
		<< "\n\nReceivers Name: " << receiverName << fixed << setw(20) << "Receivers Address: " << receiverAddress << "\nReceivers City: " << receiverCity << fixed << setw(20) << "Receivers State: " << receiverState << fixed << setw(20) << "\nReceivers Zip: "
		<< receiverZip
		<< "\n\nWeight " << setprecision(2) << weight << "\nCost per Ounce: " << setprecision(2) << costPerOunce << "\nTotal: " 
		<< setprecision(2) << calculateCost();
	return output.str();
}