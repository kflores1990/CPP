#pragma once
#include "Package.h"

class TwoDaypackage : public Package
{
private:
    double twoDayFee;

public:
    TwoDaypackage(string&, string&, string&, string&, string&,
        string&, string&, string&, string&, string&,
        double = 0.0, double = 0.0, double = 0.0);
    
    void setTwoDayFee(double);
    double getTwoDayFee();

    double calculateCost() override;
    string toString();
};


