// Coder/Developer: Paul Cimarusti, Cesar Fandino, & Raven Suggs
// Class:           COP 2006-80599, Fall 2024
// Date:            November 7, 2024
// Description:     C++ Program to generate an amortization table based on given parameters
// Log:             November 7, 2024, Created project file
#include <iostream>
#include "LoanData.h"




int main()
{
    LoanData data(98500, 30, 6);
    data.PrintPayOffTimeReport(98500, 0.005);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
