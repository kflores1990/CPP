#pragma once
#include<iostream>
using namespace std;
class Package
{
protected:
	string senderName, senderAddress, senderCity, senderState, senderZip;
	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

	double weight, costPerOunce;
public:
	Package(string&, string&, string&, string&, string&, 
		string&, string&, string&, string&, string&,
		double = 0.0, double = 0.0);

	//----------SENDER--------

	void setSenderName(string);
	string getSenderName();

	void setSenderAddress(string);
	string getSenderAddress();

	void setSenderCity(string);
	string getSenderCity();

	void setSenderState(string);
	string getSenderState();

	void setSenderZip(string);
	string getSenderZip();

	//----------RECEIVER--------
	void setReceiverName(string);
	string getReceiverName();

	void setReceiverAddress(string);
	string getReceiverAddress();

	void setReceiverCity(string);
	string getReceiverCity();

	void setReceiverState(string);
	string getReceiverState();

	void setReceiverZip(string);
	string getReceiverZip();


	void setWeight(double);
	double getWeight();

	void setCostPerOunce(double);
	double getCostPerOunce();


	virtual double calculateCost();
	virtual string toString();
		

};

