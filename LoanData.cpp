//
// Created by datav on 11/7/2024.
//
#include "LoanData.h"

#include <iostream>
#include <valarray>

LoanData::LoanData(double p, double years, double inter)
{
    //Number of months (years / 12)
    LoanData::n = years / 12;
    //Interest rate (made into decimal and monthly)
    LoanData::i = inter / 100 / 12;
    //Compute monthly payment using formula
    LoanData::A = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
    //Balance left on loan
    Bal = p;
}

void LoanData::MakePayment(double pay)
{
    Bal = (i + 1) * Bal - pay;
}

void LoanData::PrintAmortizationSchedule()
{
    double balance = Bal;
    double payment;
    double interestPaid;
    double principlePaid;
    double endingBalance;
    while(balance > 0)
    {
        if((i+1) * balance > A)
        {
            payment = balance;
        }
        else
        {
            payment = (i + 1) * balance;
        }
    }
}

void LoanData::PrintPayOffTimeReport(double p, double i)
{
    for(int month = 6; month < 360; month++)
    {
        A = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
        std::cout << month << " " << A << std::endl;
    }
}
