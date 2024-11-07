// Coder/Developer: Paul Cimarusti, Cesar Fandino, & Raven Suggs
// Class:           COP 2006-80599, Fall 2024
// Date:            November 7, 2024
// Description:     C++ Program to generate an amortization table based on given parameters
// Log:             November 7, 2024, Created project file
//                  November 7, 2024,

#include "LoanData.h"

int main()
{
    LoanData data(100000, 30, 5);
    data.PrintAmortizationSchedule();
    return 0;
}
