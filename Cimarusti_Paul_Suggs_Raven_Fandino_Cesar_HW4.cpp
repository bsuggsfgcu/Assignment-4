// Coder/Developer: Paul Cimarusti, Cesar Fandino, & Raven Suggs
// Class:           COP 2006-80599, Fall 2024
// Date:            November 7, 2024
// Description:     C++ Program to generate an amortization table based on given parameters
// Log:             November 7, 2024, Created project file and code
// Sources:         (https://www.geeksforgeeks.org/setw-function-in-cpp-with-examples/?ref=gcse_outind, https://en.cppreference.com/w/cpp/io/manip/left), lines 30, 49, 60, 62, to create and format the tables in LoanData.cpp
#include <iostream>
#include "LoanData.h"
int main()
{
    LoanData data(12000, 5, 8);
    data.MakePayment(500);
    data.MakePayment(1000);
    data.PrintAmortizationSchedule();
    return 0;
}
