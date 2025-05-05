// TakeOrder v2
// Dena Paw
// 10-16-2023

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
const int MENU_COL1 = 20;  // for menu items
const int MENU_COL2 = 1;   // for dollar sign
const int MENU_COL3 = 5;   // right-align numbers with decimals

const int TOTAL_COL1 = 15; // for menu items
const int TOTAL_COL2 = 1;  // for dollar sign
const int TOTAL_COL3 = 6;  // right- align numbers with decimals

int main()
{
    // Variable declarations - 

    char type, size, thaitea_type, size_type, ans;  // menu size selection
    double subtotal = 0;   // stores price of item ordered, based on item selection
    double tax = 0;        // amouunt of tax owed on item
    double total = 0;      // grand total user ownes
    double item = 0;

    // Sets all nubers that print to screen to 2 decimal places.
    cout << fixed << showpoint << setprecision(2);

    // Program title and description
    cout << "Welcome to Thai Tea Paw!" << endl << endl;
    cout << "Take a look at our menu below." << endl;
    cout << "We hope you enjoy!" << endl << endl;

    do  // Collect user input
    {
        cout << "******************************************" << endl;
        cout << "                   MENU                   " << endl;
        cout << setw(MENU_COL1) << left << "Thai Tea options:" << endl;
        cout << setw(MENU_COL1) << left << "  1 - Hot tea" << endl;
        cout << setw(MENU_COL1) << left << "  2 - Ice tea" << endl;
        cout << setw(MENU_COL1) << left << "  3 - Bubble tea" << endl;
        cout << setw(MENU_COL1) << left << "  4 - Green tea" << endl;
        cout << setw(MENU_COL1) << left << "  5 - Ice coffee" << endl << endl;

        cout << setw(MENU_COL1) << left << "Prices:" << endl;
        cout << setw(MENU_COL1) << left << "  S - Small " << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_S << endl;
        cout << setw(MENU_COL1) << left << "  M - Medium " << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_M << endl;
        cout << setw(MENU_COL1) << left << "  L - Large " << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_L << endl;

        cout << "******************************************" << endl << endl;

        // Ask user which size coffee they want
        cout << "Enter the type of Thai Tea would you like to order ( 1 - 5): ";
        cin >> thaitea_type;
        cout << "Which size of Thai Tea would you like to order (Enter S, M, or L): ";
        cin >> size_type;

        // Menu structure
        
       
        if (size_type == 'S' || size_type == 's')
            subtotal = PRICE_S && cout << "small" << endl;
        else if (size_type == 'M' || size_type == 'm')
            subtotal = PRICE_M;
        else if (size_type == 'L' || size_type == 'l')
            subtotal = PRICE_L;
        else // allow for invalid imput
        {
            cout << "You have made an invalid selection. program terminating." << endl;
            return 1; // ends program early due to an error
        }
        total++;
            item++;

        cout << "Do you want to order another item? Please enter 'Y' for yes or 'N' for no: ";
        cin >> ans; // loop variable - if user says "yes" then repeat

        system("cls");    
    } while(ans == 'Y' || ans == 'y'); // ends outer loop

    // Verify user's order
    cout << "You orderd a " << item << size_type << " " << thaitea_type << " " << endl << endl;

    // Calculate tax and final amount owned 
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Show user their subtotal, tax, and total owed for all orders
    cout << endl;
    cout << setw(TOTAL_COL1) << left << "No of items: " << setw(TOTAL_COL3) << left << item << endl;
    cout << setw(TOTAL_COL1) << left << "Subtotal: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << subtotal << endl;
    cout << setw(TOTAL_COL1) << left << "Tax: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << tax << endl;
    cout << setw(TOTAL_COL1) << left << "Total: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << total << endl << endl;
    
    // Goodbye line
    cout << "Thank you! We hope you visit again soon!" << endl << endl;

    return 0;
}
