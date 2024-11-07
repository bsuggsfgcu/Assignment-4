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
    LoanData::i = (inter / 100) / 12;
    //Compute monthly payment using formula
    LoanData::A = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
    //Balance left on loan
    Bal = p;
}

void LoanData::MakePayment(double payment)
{
    LoanData::Bal = (i + 1) * LoanData::Bal - payment;
}

void LoanData::PrintAmortizationSchedule()
{
    double beginningBalance = LoanData::Bal;
    double payment;
    double interestPaid;
    double principlePaid;
    double endingBalance;

    while(beginningBalance > 0)
    {
        // Calculate Payment
        if((i+1) * beginningBalance > A) // If the expected payment is more than what is left to pay
            payment = A;
        else
            payment = (i + 1) * beginningBalance;

        interestPaid = i * beginningBalance;
        principlePaid = payment - i * beginningBalance;
        endingBalance = (i + 1) * beginningBalance - payment;


        if (endingBalance < 0.01)
        {
            endingBalance = 0;
        }
        std::cout << "-----------------------------------------------------------------------------------------------\n"
                << "Beginning Balance: " << beginningBalance << '\t'
                << "Interest Paid: " << interestPaid << '\t'
                << "Payment: " << payment << '\t'

                << "Principle Paid: " << principlePaid << '\t'

                << "Ending Balance: " << endingBalance << '\t'
                << "\n\n";

        if (endingBalance == 0)
        {
            break;
        }
        beginningBalance = endingBalance;

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
