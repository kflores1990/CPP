/*
Kyle Flores assignment 5 regargding chapter 11 
This program demonstrates inheritance using 3 classes Package, TwoDayPackage, and OvernightPackage
class one provides a template for the remaining to classes and acts as a tiered system of delivery. 
TwoDayPackage and overnightPackage inherits from class "Package". 

*/

#include <iostream>
#include <sstream>
#include <vector>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDaypackage.h"

void introduction();
double weightTest(double);
double costTest(double);

using namespace std;
int main()
{
	introduction();

	string senderName, senderAddress, senderCity, senderState, senderZip;
	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

	vector<Package> packages;
	vector<OvernightPackage> overNightPackages;
	vector<TwoDaypackage> twoDaypackages;


	char packageType = NULL;
	char testAnother = ' ';

	bool addAnother = false;

	while (!addAnother) {

		double weight, costPerOunce, twoDayFee, overnightFee;

		cout << "What type of package would you like to send\n Regular mail (enter r)"
			"\nOvernight mail (enter o)"
			"\nTwo day mail (enter t)"
			"\nDefaults to regular mail: "
			"\nPlease select: ";
		cin >> packageType;
		cin.ignore();
		cin.clear();
		cout << "Senders Name: ";
		getline(cin, senderName);
		cout << "Senders Address: ";
		getline(cin, senderAddress);
		cout << "Senders City: ";
		getline(cin, senderCity);
		cout << "Senders State: ";
		getline(cin, senderState);
		cout << "Senders Zip: ";
		getline(cin, senderZip);


		cout << "Receivers Name: ";
		getline(cin, receiverName);
		cout << "Receivers Address: ";
		getline(cin, receiverAddress);
		cout << "Receivers City: ";
		getline(cin, receiverCity);
		cout << "Receivers State: ";
		getline(cin, receiverState);
		cout << "Receivers Zip: ";
		getline(cin, receiverZip);



		cout << "Weight: ";
		cin >> weight;
		weight = weightTest(weight);
		cout << "Cost per ounce: ";
		cin >> costPerOunce;
		costPerOunce = costTest(costPerOunce);

		switch (packageType) {
			case('t') : {
				cout << "Two day fee amount: ";
				cin >> twoDayFee;

				TwoDaypackage tDP(senderName, senderAddress, senderCity, senderState, senderZip,
					receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
					weight, costPerOunce, twoDayFee);
				twoDaypackages.push_back(tDP);

				break;
			}
			case('o'): {
				cout << "Overnight fee amount: ";
				cin >> overnightFee;


				OvernightPackage oNP(senderName, senderAddress, senderCity, senderState, senderZip,
					receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
					weight, costPerOunce, overnightFee);
				overNightPackages.push_back(oNP);
				break;
			}
			default: 
				Package p(senderName, senderAddress, senderCity, senderState, senderZip,
					receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
					weight, costPerOunce);
				
				packages.push_back(p);
				break;
			
		}
		cout << "Add another? ";
		cin >> testAnother;
		addAnother = (testAnother == 'y') ? false : true;
	}

	for (int x = 0; x < packages.size(); x++) {
		cout << packages[x].toString();
	}
	for (int x = 0; x < overNightPackages.size(); x++) {
		cout << overNightPackages[x].toString();
	}
	for (int x = 0; x < twoDaypackages.size(); x++) {
		cout << twoDaypackages[x].toString();
	}

}

void introduction() {
	cout << "This program demonstrates inheritance with 3 " << endl 
		 <<"classes two of which inherit from the main class " << endl;
}

double weightTest(double oz) {
	if (oz > 0) { return oz; }
	while (oz < 0) {
		cout << "\nEnter a higher weight than 0:\n";
		cin >> oz;
		if (oz > 0) { return oz; }
	}
}
double costTest(double cPoz) {
	if (cPoz > 0) { return cPoz; }
	while (cPoz < 0) {
		cout << "\nEnter a higher weight than 0:\n";
		cin >> cPoz;
		if (cPoz > 0) { return cPoz; }
	}
}