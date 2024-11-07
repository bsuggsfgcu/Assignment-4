//
// Created by datav on 11/7/2024.
//

#ifndef LOANDATA_H
#define LOANDATA_H

class LoanData
{
private:
    //Amount left of loan
    double Bal;
    //Number of months left to pay
    double n;
    //Monthly interest rate
    double i;
    //Monthly payment
    double A;

public:
    LoanData(double p, double years, double inter);
    void MakePayment(double pay);
    void PrintAmortizationSchedule();
    void PrintPayOffTimeReport(double p, double i);
    void SpitOutData();

};

#endif //LOANDATA_H
