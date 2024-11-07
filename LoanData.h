//
// Created by datav on 11/7/2024.
//

#ifndef LOANDATA_H
#define LOANDATA_H

class LoanData
{
private:
    double Bal;
    double n;
    double i;
    double A;

public:
    LoanData(double p, double years, double inter);
    void MakePayment(double a);
    void PrintAmortizationSchedule();
    void PrintPayOffTimeReport();

};

#endif //LOANDATA_H
