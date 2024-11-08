//
// Created by datav on 11/7/2024.
//
#include "LoanData.h"

#include <iomanip>
#include <iostream>
#include <valarray>

LoanData::LoanData(double p, double years, double inter)
{
    //Number of months (years / 12)
    LoanData::n = years * 12;
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
    int tableSpacing = 20;
    std::cout << std::left << std::fixed << std::setprecision(2) << std::setw(tableSpacing) << "Beginning Bal." << std::setw(tableSpacing) << "Interest paid" << std::setw(tableSpacing) << "Principle paid" << std::setw(tableSpacing) << "Ending Bal." << std::endl;
    while(balance > 0)
    {
        if((i+1) * balance > A)
        {
            payment = A;
        }
        else
        {
            payment = (i + 1) * balance;
        }
        const double iP = i * balance;
        double principlePaid = payment - iP;
        const double endingBalance = (i + 1) * balance - payment;
        //std::cout << balance << " " << iP << " " << principlePaid << " " << endingBalance << " " << std::endl;
        std::cout << "$" << std::setw(tableSpacing) << balance << "$" << std::setw(tableSpacing) << iP << "$" << std::setw(tableSpacing) << principlePaid << "$" << std::setw(tableSpacing) << endingBalance << std::endl;
        balance = endingBalance;
    }
}

void LoanData::PrintPayOffTimeReport(double p, double i)
{
    for(int month = 6; month < 360; month++)
    {
        double payment = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
        std::cout << month << " " << payment << std::endl;
    }
}

