#pragma once
#include "Package.h"
class OvernightPackage :
    public Package
{
private:
    double overnightRate;

public:
    OvernightPackage(const string&, const string&, const string&, const string&, const string&,
        const string&, const string&, const string&, const string&, const string&,
        double = 0.0, double = 0.0, double = 0.0);


    void setOvernightRate(double);
    double getOvernightRate();

    double calculateCost() const override;
    string  toString() const override;


};

