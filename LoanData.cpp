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
    //Setting up table header
    std::cout << std::left << std::fixed << std::setprecision(2) << std::setw(tableSpacing+1) << "Beginning Bal." << std::setw(tableSpacing + 1) << "Interest paid" << std::setw(tableSpacing + 1) << "Principle paid" << std::setw(tableSpacing + 1) << "Ending Bal." << std::endl;
    while(balance > 0)
    {
        if((i+1) * balance > A)
        {
            payment = A;
        }
        else
        {
            //If monthly payment is larger than the amount left to pay, then pay what is left instead of full payment
            payment = (i + 1) * balance;
        }
        //interest paid
        const double iP = i * balance;
        //principle paid
        double principlePaid = payment - iP;
        //ending balance after monthly payment
        const double endingBalance = (i + 1) * balance - payment;
        //std::cout << balance << " " << iP << " " << principlePaid << " " << endingBalance << " " << std::endl;
        //Code to create data table
        std::cout << "$" << std::setw(tableSpacing) << balance << "$" << std::setw(tableSpacing) << iP << "$" << std::setw(tableSpacing) << principlePaid << "$" << std::setw(tableSpacing) << endingBalance << std::endl;
        balance = endingBalance;
    }
}

void LoanData::PrintPayOffTimeReport(double p, double i)
{
    std::cout << std::left << std::fixed << std::setprecision(2) << std::setw(20) << "Amount of months" << std::setw(21) << "Monthly payment" << std::endl;
    for(int month = 6; month < 360; month++)
    {
        double payment = p*((i*std::pow(i+1, month))/(std::pow(i+1, month) - 1));
        //std::cout << month << " " << payment << std::endl;
        std::cout << std::setw(20) << month << "$" << std::setw(20) << payment << std::endl;
    }
}

