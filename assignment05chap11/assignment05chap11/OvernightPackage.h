#pragma once
#include "Package.h"
class OvernightPackage :
    public Package
{
private:
    double overnightRate;

public:
    OvernightPackage(string&, string&, string&, string&, string&,
        string&, string&, string&, string&, string&,
        double = 0.0, double = 0.0, double = 0.0);


    void setOvernightRate(double);
    double getOvernightRate();

    double calculateCost() override;
    string  toString() override;


};

