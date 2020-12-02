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
	Package(const string&, const string&, const string&, const string&, const string&,
		const string&, const string&, const string&, const string&, const string&,
		double = 0.0, double = 0.0);
 	//----------SENDER--------

	void setSenderName(const string);
	string getSenderName();

	void setSenderAddress(const string);
	string getSenderAddress();

	void setSenderCity(const string);
	string getSenderCity();

	void setSenderState(const string);
	string getSenderState();

	void setSenderZip(const string);
	string getSenderZip();

	//----------RECEIVER--------
	void setReceiverName(const string);
	string getReceiverName();

	void setReceiverAddress(const string);
	string getReceiverAddress();

	void setReceiverCity(const string);
	string getReceiverCity();

	void setReceiverState(const string);
	string getReceiverState();

	void setReceiverZip(const string);
	string getReceiverZip();


	void setWeight(double);
	double getWeight();

	void setCostPerOunce(double);
	double getCostPerOunce();


	virtual double calculateCost() const;
	virtual string toString() const ;


};

;

