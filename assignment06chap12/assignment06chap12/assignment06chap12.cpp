/*
Kyle Flores assignment 6 regarding chapter 12
This program demonstrates polymorphism using 3 classes Package, TwoDayPackage, and OvernightPackage
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
double costPerOunceTest(double);


using namespace std;
int main()
{
	string senderName, senderAddress, senderCity, senderState, senderZip;
	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

	char addAnother = ' ';
	char shippingOption = NULL;

	double weight, costPerOunce, twoDayFee, overnightFee;
	
	vector<Package*> allPackages;


	introduction();
	
	for (int x = 1; x != 0; x++) {
		cout << "Senders Name: ";
		getline(cin, senderName);
		cout << "Senders Address: ";
		getline(cin, senderAddress);
		cout << "Senders City: ";
		getline(cin, senderCity);
		cout << "Senders State: ";
		getline(cin, senderState);
		cout << "Senders zip: ";
		getline(cin, senderZip);
		
		cout << "Receivers Name: ";
		getline(cin, receiverName);
		cout << "Receivers Address: ";
		getline(cin, receiverAddress);
		cout << "Receivers City: ";
		getline(cin, receiverCity);
		cout << "Receivers State: ";
		getline(cin, receiverState);
		cout << "Receivers zip: ";
		getline(cin, receiverZip);


		cout << "Enter weight: ";
		cin >> weight;
		weight = weightTest(weight);
		cout << "Enter Cost Per Ounce: ";
		cin >> costPerOunce;
		costPerOunce = costPerOunceTest(costPerOunce);
		cout << "Please select shipping rate\n'o' for overnight rate\n't' for twoday rate\n'r' for regular mail.\n ";
		cin >> shippingOption;


	
	
		switch (shippingOption) {
		case('t'): {
			cout << "Two day fee amount: ";
			cin >> twoDayFee;

			allPackages.push_back(new TwoDaypackage{ senderName, senderAddress, senderCity, senderState, senderZip,
				receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
				weight, costPerOunce, twoDayFee });
			break;
		}
		case('o'): {
			cout << "Overnight fee amount: ";
			cin >> overnightFee;


			allPackages.push_back(new OvernightPackage{ senderName, senderAddress, senderCity, senderState, senderZip,
				receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
				weight, costPerOunce, overnightFee });

			break;
		}
		default:
			allPackages.push_back(new Package{ senderName, senderAddress, senderCity, senderState, senderZip ,  
				receiverName,receiverAddress,receiverCity, receiverState, receiverZip, 
				weight, costPerOunce });
			break;

		}

		cout << "Would you like to add another (y/n): ";
		cin >> addAnother;
		cin.ignore();
		if (addAnother == 'n') { break; }
	}



	for (auto&& ap : allPackages) {
		cout << ap->toString();
	}

}

void introduction() {
	cout << "This program demonstrates polymorphism with 3 " << endl
		<< "classes two of which inherit from the main class " << endl;
}

double weightTest(double oz) {
	if (oz > 0) { return oz; }
	while (oz <= 0) {
		cout << "\nenter weight above 0: \n";
		cin >> oz;
		if (oz > 0) {
			return oz;
		}
	}
}
double costPerOunceTest(double cPoz) {
	if (cPoz > 0) { return cPoz; }
	while (cPoz <= 0) {
		cout << "\nenter cost above 0: \n";
		cin >> cPoz;
		if (cPoz > 0) {
			return cPoz;
		}
	}
}