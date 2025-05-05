// Dena Paw
// TakeOrder v1 program, dev 9/25/23 - menu structure, ability to order 1 item, calculate tax and total, terminate program if invalid menu selection

#include <iostream>
#include <iomanip>

using namespace std;

// CONSTANT DECLARATIONS

// use constants for costs and tax rate because those are set amounts
const double PRICE_S = 1.00;
const double PRICE_M = 2.00;
const double PRICE_L = 3.00;
const double TAX_RATE = .10;

// use constants for columns widths - easy to change here if need adjusted.
const int MENU_COL1 = 30;  // for menu items
const int MENU_COL2 = 1;   // for dollar sign
const int MENU_COL3 = 5;   // right-align numbers with decimals

const int TOTAL_COL1 = 15; // for menu items
const int TOTAL_COL2 = 1;  // for dollar sign
const int TOTAL_COL3 = 6;  // right- align numbers with decimals

int main()
{
    // Variable declarations - 
    char size;             // menu size selection
    double subtotal = 0;   // stores price of item ordered, based on item selection
    double tax = 0;        // amouunt of tax owed on item
    double total = 0;      // grand total user ownes

    // Sets all nubers that print to screen to 2 decimal places.
    cout << fixed << showpoint << setprecision(2);

    // Program title and description
    cout << "Welcome to Thai Tea Paw!" << endl << endl;
    cout << "Take a look at our menu below." << endl;
    cout << "We hope you enjoy!" << endl << endl;

    // Collect user input
    cout << "******************************************" << endl;

    cout << setw(MENU_COL1) << left << "Menu options: " << setw(7) << right << "Prices:" << endl;
    cout << setw(MENU_COL1) << left << "  S - Small Thai Tea" << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_S << endl;
    cout << setw(MENU_COL1) << left << "  M - Medium Thai Tea" << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_M << endl;
    cout << setw(MENU_COL1) << left << "  L - Large Thai Tea" << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_L << endl;

    cout << "******************************************" << endl << endl;

    // Ask user which size coffee they want
    cout << "Which size of Thai Tea would you like to order (Enter S, M, or L): ";
    cin >> size;

    // Menu structure
    if (size == 'S' || size == 's')
        subtotal = PRICE_S;
    else if (size == 'M' || size == 'm')
        subtotal = PRICE_M;
    else if (size == 'L' || size == 'l')
        subtotal = PRICE_L;
    else // allow for invalid imput
    {
        cout << "You have made an invalid selection. program terminating." << endl;
        return 1; // ends program early due to an error
    }

    // Calculate tax and final amount owned
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Show user their subtotal, tax, and total owed for all orders
    cout << endl;
    cout << setw(TOTAL_COL1) << left << "Subtotal: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << subtotal << endl;
    cout << setw(TOTAL_COL1) << left << "Tax: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << tax << endl;
    cout << setw(TOTAL_COL1) << left << "Total: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << total << endl << endl;

    // Goodbye line
    cout << "Thank you! We hope you visit again soon!" << endl << endl;

    return 0;
}