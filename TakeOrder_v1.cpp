// TakeOrder_v1.cpp
// Dena Paw
// 9-22-23

#include <iostream>
#include <iomanip>

using namespace std;

// Constants 
const int COL1 = 30;
const int COL2 = 1;
const int COL3 = 5;
const int COL1_ = 15;
const double PRICE_S = 1.00;
const double PRICE_M = 2.00;
const double PRICE_L = 3.00;
const double TAX = .1;


int main()
{
    // Variable declarations - 
    char choice;
    double subtotal, total, tax;
    // Program title and description
    cout << "Welcome to Thai Tea Paw!" << endl << endl;
    cout << "Take a look at our menu below." << endl;
    cout << "We hope you enjoy!" << endl << endl;


    // Collect user input
    cout << "******************************************" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << setw(COL1) << left << "Menu options: " << setw(7) << right << "Prices:" << endl;
    cout << setw(COL1) << left << "  S - Small Thai Tea" << setw(COL2) << left << "$ " << setw(COL3) << right << PRICE_S << endl;
    cout << setw(COL1) << left << "  M - Medium Thai Tea" << setw(COL2) << left << "$ " << setw(COL3) << right << PRICE_M << endl;
    cout << setw(COL1) << left << "  L - Large Thai Tea" << setw(COL2) << left << "$ " << setw(COL3) << right << PRICE_L << endl;
    cout << "******************************************" << endl << endl;
    cout << "Which size of Thai Tea would you like to order (Enter S, M, or L): ";
    cin >> choice;
    cout << endl;

    // Menu structure

    if (choice == 'S'||choice == 's')
    {  
        //do calculations for Size S price
        subtotal = PRICE_S;
        tax = subtotal * TAX;
        total = subtotal * TAX;

        //have output here for Size S price
        cout << setw(COL1_) << left << "Subtotal: " << setw(COL2) << left << "$ " << setw(COL3) << right << subtotal << endl;
        cout << setw(COL1_) << left <<  "Tax: " << setw(COL2) << left << "$ " << setw(COL3) << right << tax << endl;
        cout << setw(COL1_) << left << "Total: " << setw(COL2) << left << "$ " << setw(COL3) << right << total << endl << endl;
    }

    else if (choice == 'M'||choice == 'm')
    {
        //do calculations for Size M price
        subtotal = PRICE_M;
        tax = subtotal * TAX;
        total = subtotal + tax;

        //have output here for Size M price
        cout << setw(COL1_) << left << "Subtotal: " << setw(COL2) << left << "$ " << setw(COL3) << right << subtotal << endl;
        cout << setw(COL1_) << left << "Tax: " << setw(COL2) << left << "$ " << setw(COL3) << right << tax << endl;
        cout << setw(COL1_) << left << "Total: " << setw(COL2) << left << "$ " << setw(COL3) << right << total << endl << endl;
    }

    else if (choice == 'L'||choice == 'l')
    {
        //do calculations for Size L price
        subtotal = PRICE_L;
        tax = subtotal * TAX;
        total = subtotal + tax;

        //have output here for Size L price
        cout << setw(COL1_) << left << "Su5btotal: " << setw(COL2) << left << "$ " << setw(COL3) << right << subtotal << endl;
        cout << setw(COL1_) << left << "Tax: " << setw(COL2) << left << "$ " << setw(COL3) << right << tax << endl;
        cout << setw(COL1_) << left << "Total: " << setw(COL2) << left << "$ " << setw(COL3) << right << total << endl << endl;
    }
    else
    {
        cout << "Input error; program terminating." << endl;
        return 1; // sends message to operating system telling it that the program ended early because there was an issue
    }

    cout << "Thank you! We hope you visit again soon!." << endl << endl;


    return 0;
}