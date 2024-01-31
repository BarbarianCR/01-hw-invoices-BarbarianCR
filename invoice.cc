/**
 *   @file: invoice.cc
 * @author: Braden Schneider
 *   @date: 1/31/24
 *  @brief: First homework project about an invoice.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    cout << "Enter a monitor type (s, v) followed by the quantity:" << endl;
    string monitor_type;
    int quantity;
    cin >> monitor_type >> quantity; //prompting and setting variables
    
    double const SAM_PRICE = 190.00;
    double const VIEW_PRICE = 170.00;
    double total; //setting variables for price calculations
    string yes_no;
    double discount;
    double subtotal;
    double tax;


    if (monitor_type == "s" || monitor_type == "v" || monitor_type == "V" || monitor_type == "S")
    {
        if (quantity > 0)
        {
            
            cout << "Do you live in Ohio (yes/no)?" << endl;
            cin >> yes_no;
            
            
            
            if (quantity >= 3) //discount
            {
                
                if (monitor_type == "s" || monitor_type == "S")
                {
                    discount = (SAM_PRICE * quantity * .05);
                    subtotal = (SAM_PRICE * quantity) - discount; // calculating discount price
                    if (yes_no == "yes") //if ohio
                    {
                        tax = subtotal * .07;
                        total = subtotal + tax; //final price with discount for 3 and tax for ohio and samsung
                    }
                    else if (yes_no == "no") //if not ohio
                    {
                        total = subtotal; //final price with discount no tax and not ohio
                        tax = 0.00;
                    }
                    else
                    {
                        cout << "Error: Must be yes or no";
                        return 0;
                    }
                }
                else if (monitor_type == "v" || monitor_type == "V") // viewsonic prices
                {
                    discount = (VIEW_PRICE * quantity * .05);
                    subtotal = (VIEW_PRICE * quantity) - discount; //calculating discount
                    if (yes_no == "yes") //if ohio
                    {
                        tax = subtotal * .07;
                        total = subtotal + tax; //final price with discount for 3 and tax for ohio and viewsonic
                    }
                    else if (yes_no == "no") //if not ohio
                    {
                        total = subtotal; //final price with discount no tax and not ohio
                        tax = 0.00;
                    }
                    else
                    {
                        cout << "Error: Must be yes or no";
                        return 0;
                    }
                }
                
            }
            else //non discount
            {
                if (monitor_type == "s" || monitor_type == "S") // samsung
                {
                    subtotal = SAM_PRICE * quantity;
                    
                    if (yes_no == "yes") //if ohio
                    {
                        tax = subtotal * .07;
                        total = subtotal + tax; //final price with discount for 3 and tax for ohio and samsung
                    }
                    else if (yes_no == "no") //if not ohio
                    {
                        total = subtotal; //final price with discount no tax and not ohio
                        tax = 0.00;
                    }
                }
                else if (monitor_type == "v" || monitor_type == "V")// viewsonic
                {
                    subtotal = VIEW_PRICE * quantity; // subtotal with no discount

                    if (yes_no == "yes") //if ohio
                    {
                        tax = subtotal * .07;
                        total = subtotal + tax; //final price with no discount and tax for ohio and viewsonic
                    }
                    else if (yes_no == "no") //if not ohio
                    {
                        total = subtotal; //final price with discount no tax and not ohio
                        tax = 0.00;
                    }


                }
                
            }
            

            

            
        }
        else
        {
            cout << "Error: Invalid number of monitors" << endl;
            return 0;
        }

    }
    else
    {
        cout << "Error: Invalid monitor type" << endl;
        return 0;

    }
    
    
    string brand; // defining the brand and price
    double price;
    if (monitor_type == "s" || monitor_type == "S")
    {
        brand = "Samsung";
        price = SAM_PRICE;

    }
    else
    {
        brand = "Viewsonic";
        price = VIEW_PRICE;
    }

    

    double pre_subtotal = price * quantity;

    cout << "Monitors Invoice" << endl; // output statements
    cout << "--------------------------" << endl;
    cout << "  Monitor brand: " << brand << endl;
    cout << "       Quantity: " << quantity << endl;
    cout << "          Price: $" << fixed << setprecision(2) << price << endl;
    cout << "  Ohio Resident: " << yes_no << endl;
    cout << "    Total Price: $" << pre_subtotal << fixed << setprecision(2) << endl;
    cout << "--------------------------" << endl;
    cout << "       Discount: $" << fixed << setprecision(2) << discount << endl;
    cout << "       Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "          Taxes: $" << fixed << setprecision(2) << tax << endl;
    cout << "==========================" << endl;
    cout << "          Total: $" << fixed << setprecision(2) << total << endl;
    cout << "--------------------------" << endl;
   



    return 0;
} /// main
