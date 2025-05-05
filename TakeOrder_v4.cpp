// TakeOrder v4
// Dena Paw
// 11-27-2023
//v2 created two-part menu, added order confirmation, added error checking for invalid user input, allowed user to order more than one item, counted number of items ordered
//v3 add the option to redo an order AND at least 2 functions.
//v4 print receipt that has: name of business, what was ordered, subtotal, tax, and total. 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// CONSTANT DECLARATIONS
// use constants for costs and tax rate because those are set amounts
// Prices for Thai Tea Sizes
const double PRICE_S = 1.00;
const double PRICE_M = 2.00;
const double PRICE_L = 3.00;
const double TAX_RATE = 0.10;

// use constants for columns widths - easy to change here if need adjusted
const int TOTAL_COL1 = 20;
const int TOTAL_COL2 = 1;
const int TOTAL_COL3 = 6;

// Maximumnumber of items that can be ordered
const int MAX_ITEMS = 10;

// FUNCTION declaration
void menu(); // Display MENU
void orderWhat(double& price, double& subtotal, string& size, string& thaitea); //Handle orders
void receiptP(double prices[], string items[], int item, double subtotal, double tax, double total); // Print receipt

// Main program ---------------------------------------------------------
int main()
{
    // Variable declarations
    double tax = 0; // amount of tax owed on item
    double total = 0;// grand total user ownes
    double subtotal = 0; // stores price of item ordered, based on item selection
    int order;//number of thai tea order want to order
    int itemCount = 0; //keep track of number of order
    int item = 0; //number of item order
    char ans; // order confirmation
    char receipt; // print receipt

    // Arrays to store item names and price
    string items[MAX_ITEMS]; //store item names of ordered
    double prices[MAX_ITEMS]; //store item prices of ordered

    // Arrays to store item names and price for receipt
    string itemNames[MAX_ITEMS]; //store item names
    double itemPrices[MAX_ITEMS]; //store item prices

    // Declare file stream variables for receipt
    ofstream fout("thaitea_receipt.txt");

    // Sets all numbers that print to the screen to 2 decimal places.
    cout << fixed << showpoint << setprecision(2);

    // Program title and description
    cout << "Welcome to Thai Tea Paw!" << endl << endl;
    cout << "Take a look at our menu below." << endl;
    cout << "We hope you enjoy!" << endl << endl;

    menu(); //Display menu details

    // Collect user input
    do {
        cout << "Number of Thai Tea drinks you would like to order (1, 2, 3, ...Max: 10): ";
        cin >> order;
        cout << endl;

        if (order > MAX_ITEMS) {
            cout << "Try again, you can only order up to " << MAX_ITEMS << " items. Please enter a valid number." << endl;
        }
    } while (order > MAX_ITEMS);

    // Outer loop 
    for (int i = 0; i < order; i++)
    {
        string thaitea; // Tea Type
        string size;//Drink size
        double price; 
        //to verify user choice if wrong, let user to redo
        do {
            
            item++;
            cout << "Order #" << item << endl;
            orderWhat(price, subtotal, size, thaitea); // Function to handle order
            cout << endl;

            // Inner loop
            do
            {
                // Verify user's order
                cout << "Item #" << item << " You ordered a " << size << " " << "Thai " << thaitea << " at a cost of $" << price << endl << endl;
                cout << "Is the order correct? Please enter 'Y' for yes or 'N' for no to redo: ";
                cin >> ans;// loop variable - if user says "yes" then continue, if uses says "no" will allow user to redo that order
                cout << "--------------------------------------------------------------------------" << endl << endl;

                if (ans == 'Y' || ans == 'y')
                {
                    break;
                }
                else if (ans == 'N' || ans == 'n')
                {
                    item--;
                    subtotal -= price;
                    break;
                }
                else // allow for invalid imput and redo
                {
                    cout << "Invalid input. Please try again." << endl << endl;
                    cin.clear(); // restores the input stream to a working state if in fail state
                    cin.ignore(100, '\n'); //  ignores any garbage in the input stream up to 100 characters or until a newline is reached
                }
            } while (true);
        } while (ans == 'N' || ans == 'n');

        // Populate itemNames and itemPrices arrays for receipt
        itemNames[itemCount] = size + " Thai " + thaitea;
        itemPrices[itemCount] = price;
        itemCount++;
    }
    // Calculate tax and final
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Show user their subtotal, tax, and total owed for all orders
    cout << endl;
    cout << setw(TOTAL_COL1) << left << "Number of items: " << setw(TOTAL_COL3) << left << item << endl;
    cout << setw(TOTAL_COL1) << left << "Subtotal: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << subtotal << endl;
    cout << setw(TOTAL_COL1) << left << "Tax: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << tax << endl;
    cout << setw(TOTAL_COL1) << left << "Total: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << total << endl << endl;

    // Asking user opinion for their receipt
    cout << "Would you like a Receipt? Please enter 'Y' for yes or 'N' for no: ";
    cin >> receipt;

    if (receipt == 'Y' || receipt == 'y')
    {
        cout << "Your receipt has been printed; the file name is thaitea_receipt.txt" << endl << endl;
        receiptP(itemPrices, itemNames, itemCount, subtotal, tax, total);
    }
    else if (receipt == 'N' || receipt == 'n')
    {
        cout << "Thank you! We hope you visit again soon!" << endl << endl;
    }
    else
    {
        cout << "Invalid input. Please try again." << endl << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    // Goodbye line
    cout << "Thank you! We hope you visit again soon!" << endl << endl;
    return 0;
}
// Function definitions ----------------------------
void menu() // Function to display MENU
{
    cout << "******************************************" << endl;
    cout << "*                - MENU -                *" << endl;
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << setw(TOTAL_COL1) << left << "|[Thai Tea options:]                     |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  1 - Hot tea                           |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  2 - Ice tea                           |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  3 - Bubble tea                        |" << endl;
    cout << setw(TOTAL_COL1) << left << "|   4 - Green tea                        |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  5 - Ice coffee                        |" << endl;
    cout << "|                                        |" << endl;
    cout << setw(TOTAL_COL1) << left << "|[Size:]" << setw(TOTAL_COL2) << left << "[Prices:]            |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  S - Small " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << PRICE_S << "             |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  M - Medium" << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << PRICE_M << "             |" << endl;
    cout << setw(TOTAL_COL1) << left << "|  L - Large " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << PRICE_L << "             |" << endl;
    cout << "==========================================" << endl;
    cout << "******************************************" << endl << endl;
}

void orderWhat(double& price, double& subtotal, string& size, string& thaitea)
{
    char thaitea_type;
    char size_type;

    //loop to sures valid data 
    // // Ask the user which size of Thai Tea they want to order
    do
    {
        cout << "Enter the type of Thai Tea you would like to order (1 - 5): ";
        cin >> thaitea_type;

        if (thaitea_type == '1')
            thaitea = "Hot Tea";
        else if (thaitea_type == '2')
            thaitea = "Ice Tea";
        else if (thaitea_type == '3')
            thaitea = "Bubble Tea";
        else if (thaitea_type == '4')
            thaitea = "Green Tea";
        else if (thaitea_type == '5')
            thaitea = "Ice Coffee";
        else // allow for invalid imput and redo
        {
            cout << "Invalid menu type option selection. Please try again." << endl << endl;
            cin.clear();// restores the input stream to a working state if in fail state
            cin.ignore(100, '\n'); //ignores any garbage in the input stream up to 100 characters or until a newline is reached
        }
    } while (thaitea_type != '1' && thaitea_type != '2' && thaitea_type != '3' && thaitea_type != '4' && thaitea_type != '5');

    cout << endl;

    // Ask the user what size of Thai Tea they want to order
    do
    {
        cout << "Which size of Thai Tea would you like to order (Enter S, M, or L): ";
        cin >> size_type;

        // Determine the price of the size
        if (size_type == 'S' || size_type == 's')
        {
            subtotal = subtotal + PRICE_S;
            price = PRICE_S;
            size = "Small";
        }
        else if (size_type == 'M' || size_type == 'm')
        {
            subtotal = subtotal + PRICE_M;
            price = PRICE_M;
            size = "Medium";
        }
        else if (size_type == 'L' || size_type == 'l') {
            subtotal = subtotal + PRICE_L;
            price = PRICE_L;
            size = "Large";
        }
        else
        {
            cout << "Invalid menu size selection. Please try again." << endl << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (size_type != 'S' && size_type != 's' && size_type != 'M' && size_type != 'm' && size_type != 'L' && size_type != 'l');
}

void receiptP(double prices[], string items[], int item, double subtotal, double tax, double total)
{
    // Declare file stream variables
    ofstream fout("thaitea_receipt.txt");

    // Output the receipt header
    fout << "         Thai Tea Receipt         " << endl;
    fout << "----------------------------------" << endl;
    fout << "Order" << endl;

     // Output each item and price
    for (int i = 0; i < item; i++)
    {
        fout << fixed << setprecision(2);
        fout << setw(2) << left << "#" << i + 1 << " " << setw(23) << left << items[i] << setw(1) << left << "$ " << setw(4) << right << prices[i] << endl;
    }

    // Output subtotal, tax, and total
    fout << "----------------------------------" << endl;
    fout << fixed << setprecision(2);
    fout << endl;
    fout << setw(TOTAL_COL1) << left << "Number of items: " << setw(TOTAL_COL3) << left << item << endl;
    fout << setw(TOTAL_COL1) << left << "Subtotal: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << subtotal << endl;
    fout << setw(TOTAL_COL1) << left << "Tax: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << tax << endl;
    fout << setw(TOTAL_COL1) << left << "Total: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << total << endl << endl;

    // Output Thank you messages and current date and time
    fout << "            Thank you!            " << endl;
    fout << "   We hope you visit again soon!  " << endl << endl;
    fout << "       " << __DATE__ << " " << __TIME__ << endl;

    // Close the file
    fout.close();
}