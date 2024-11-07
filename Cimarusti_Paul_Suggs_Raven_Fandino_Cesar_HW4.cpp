// Coder/Developer: Paul Cimarusti, Cesar Fandino, & Raven Suggs
// Class:           COP 2006-80599, Fall 2024
// Date:            November 7, 2024
// Description:     C++ Program to generate an amortization table based on given parameters
// Log:             November 7, 2024, Created project file
#include <iostream>
#include <valarray>

class LoanData
{
private:
    double Bal;
    double n;
    double i;
    double A;

public:
    LoanData(double p, double years, double inter)
    {
        //Number of months (years / 12)
        n = years / 12;
        //Interest rate (made into decimal and monthly)
        i = inter / 100 / 12;
        //Compute monthly payment using formula
        A = p*((i*std::pow(i+1, n))/(std::pow(i+1, n) - 1));
        //Saving balance
        Bal = p;
    }
    void MakePayment(double a)
    {

    }
    void PrintAmortizationSchedule()
    {

    }
    void PrintPayOffTimeReport()
    {

    }

};


int main()
{
    LoanData(100000, 30, 6);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
