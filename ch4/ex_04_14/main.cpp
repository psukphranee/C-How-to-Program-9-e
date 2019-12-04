#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Initialize account number to zero
    //Initialize beginning balance to zero
    //Initialize new charges to zero
    //Initialize credits applied to zero
    int account_no{0};
    double beginning_bal{0};
    double new_charges{0};
    double credits_applied{0};
    double credit_limit{0};

    //Prompt the user for an account number
    //Input an account number
    cout << "Enter account number (or -1 to quit): ";
    cin >> account_no;

    /*
    While the user hasn't entered a sentinel value
        prompt the user for the beginning balance
        input the users beginning balance
        prompt the user for total charges
        input the total charges
        prompt the user for total credits
        input the total credits
        prompt the user for the credit limit
        input the credit limit

        calculate the new balance

        if the new balance is greater than the credit limit
            display account number
            display credit limit
            display new balance
            display "Credit Limit Exceeded."
        else
            displace the new balance

        Prompt the user for an account number
        Input an account number
     */
     while(account_no != -1)
     {
         cout << "Enter beginning balance: ";
         cin >> beginning_bal;
         cout << "Enter total charges: ";
         cin >> new_charges;
         cout << "Enter total credits: ";
         cin >> credits_applied;
         cout << "Enter credit limit: ";
         cin >> credit_limit;

         double new_balance{0};
         new_balance += beginning_bal + new_charges - credits_applied;

         if (new_balance > credit_limit)
         {
             cout << "Account:      " << account_no << endl;
             cout << setprecision(2) << fixed;
             cout << "Credit limit: " << credit_limit << "\nBalance:      "
                << new_balance << "\nCredit Limit Exceeded." << endl;
             cout << setprecision(0);
         }
         else
         {
             cout << setprecision(2) << fixed;
             cout << "New balance is " << new_balance << endl;
             cout << setprecision(0);
         }

         cout << "\nEnter account number (or -1 to quit): ";
         cin >> account_no;
     }

}
