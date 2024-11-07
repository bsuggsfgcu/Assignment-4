//
// Created by datav on 11/7/2024.
//

#include "LoanData.h"
#include <valarray>

LoanData::LoanData(double p, double years, double inter)
{
    //Number of months (years / 12)
    LoanData::n = years / 12;
    //Interest rate (made into decimal and monthly)
    LoanData::i = inter / 100 / 12;
    //Compute monthly payment using formula
    LoanData::A = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
    //Saving balance
    Bal = p;
}

LoanData::