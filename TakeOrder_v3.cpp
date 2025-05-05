// TakeOrder v3
// Dena Paw
// 11-5-2023
//v2 created two-part menu, added order confirmation, added error checking for invalid user input, allowed user to order more than one item, counted number of items ordered
//v3 add the option to redo an order AND at least 2 functions.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// CONSTANT DECLARATIONS

// use constants for costs and tax rate because those are set amounts
const double PRICE_S = 1.00;
const double PRICE_M = 2.00;
const double PRICE_L = 3.00;
const double TAX_RATE = .10;

// use constants for columns widths - easy to change here if need adjusted.
const int MENU_COL1 = 25;  // for menu items
const int MENU_COL2 = 1;   // for dollar sign
const int MENU_COL3 = 5;   // right-align numbers with decimals

const int TOTAL_COL1 = 15; // for menu items
const int TOTAL_COL2 = 1;  // for dollar sign
const int TOTAL_COL3 = 6;  // right- align numbers with decimals

// FUNCTION declaration
void menu();
void orderWhat(double &price, double &subtotal, string &size, string &thaitea);
// Main program ---------------------------------------------------------
int main()
{
 // Variable declarations 
  double tax = 0; // amount of tax owed on item
  double total = 0;// grand total user ownes
  double subtotal = 0; // stores price of item ordered, based on item selection
  int order;//number of thai tea order want to order
  int item = 0; //keep track of number of order
  char ans; // order confirmation


  // Sets all nubers that print to screen to 2 decimal places.
  cout << fixed << showpoint << setprecision(2);

  // Program title and description
  cout << "Welcome to Thai Tea Paw!" << endl << endl;
  cout << "Take a look at our menu below." << endl;
  cout << "We hope you enjoy!" << endl << endl;

  menu(); //menu detail
  
  // Collect user input
    cout << "Number of Thai Tea drink you would like to order (1, 2, 3,......): ";
    cin >> order;
    cout << endl;

    //Outer loop
    for (int i = 0; i < order; i++) 
    {        
        string thaitea;
        string size;
        double price;
        do
        {
         item++;
         cout << "Order #" << item << endl;
         orderWhat(price, subtotal, size, thaitea); //Function to handle order
         cout << endl;

            //Inner loop
            do
            {
                // Verify user's order
                cout << "Item #" << item << " You orderd a " << size << " " << "Thai " << thaitea << " " << "at a cost of $" << price << " " << endl << endl;
                cout << "Is the order correct? Please enter 'Y' for yes or 'N' for no to redo: ";
                cin >> ans; // loop variable - if user says "yes" then continue, if uses says "no" will allow user to redo that order
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
              } while (true); //Inner loop end            
         } while (ans == 'N' || ans == 'n'); 
     }//Outer loop end

     // Calculate tax and final amount owned
     tax = subtotal * TAX_RATE;
     total = subtotal + tax;

     // Show user their subtotal, tax, and total owed for all orders
     cout << endl;
     cout << setw(TOTAL_COL1) << left << "Number of items: " << setw(TOTAL_COL3) << left << item << endl;
     cout << setw(TOTAL_COL1) << left << "Subtotal: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << subtotal << endl;
     cout << setw(TOTAL_COL1) << left << "Tax: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << tax << endl;
     cout << setw(TOTAL_COL1) << left << "Total: " << setw(TOTAL_COL2) << left << "$ " << setw(TOTAL_COL3) << right << total << endl << endl;
  
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
    cout << setw(MENU_COL1) << left << "|[Thai Tea options:]                     |" << endl;
    cout << setw(MENU_COL1) << left << "|  1 - Hot tea                           |" << endl;
    cout << setw(MENU_COL1) << left << "|  2 - Ice tea                           |" << endl;
    cout << setw(MENU_COL1) << left << "|  3 - Bubble tea                        |" << endl;
    cout << setw(MENU_COL1) << left << "|  4 - Green tea                         |" << endl;
    cout << setw(MENU_COL1) << left << "|  5 - Ice coffee                        |" << endl;
    cout << "|                                        |" << endl;
    cout << setw(MENU_COL1) << left << "|[Size:]" << setw(MENU_COL2) << left << "[Prices:]       |" << endl;
    cout << setw(MENU_COL1) << left << "|  S - Small " << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_S << "         |" << endl;
    cout << setw(MENU_COL1) << left << "|  M - Medium" << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_M << "         |" << endl;
    cout << setw(MENU_COL1) << left << "|  L - Large " << setw(MENU_COL2) << left << "$ " << setw(MENU_COL3) << right << PRICE_L << "         |" << endl;
    cout << "|                                        |" << endl;
    cout << "==========================================" << endl;
    cout << "******************************************" << endl << endl;
}

void orderWhat(double &price, double &subtotal, string &size, string &thaitea) //Function to handle order
{
    char thaitea_type;
    char size_type;

    // Ask user which size of Thai Tea the want to order
    do 
    {
        cout << "Enter the type of Thai Tea would you like to order ( 1 - 5): ";
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
            thaitea = "Ice coffee";
        else // allow for invalid imput and redo
        {
            cout << "Invalid menu type option selection. Please try again." << endl << endl;
            cin.clear(); // restores the input stream to a working state if in fail state
            cin.ignore(100, '\n'); //  ignores any garbage in the input stream up to 100 characters or until a newline is reached
        }
    } while (thaitea_type != '1' && thaitea_type != '2' && thaitea_type != '3' && thaitea_type != '4' && thaitea_type != '5');

    cout << endl;

    //Ask user what the size of Thai Tea they want want to order
    do 
    {
        cout << "Which size of Thai Tea would you like to order (Enter S, M, or L): ";
        cin >> size_type;

        //determine price of the size
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
        else // allow for invalid imput and redo
        {
            cout << "Invalid menu size selection. Please try again." << endl << endl;
            cin.clear(); // restores the input stream to a working state if in fail state
            cin.ignore(100, '\n'); //  ignores any garbage in the input stream up to 100 characters or until a newline is reached
        }
    } while (size_type != 'S' && size_type != 's' && size_type != 'M' && size_type != 'm' && size_type != 'L' && size_type != 'l');
}
     