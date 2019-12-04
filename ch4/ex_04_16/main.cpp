#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    double hours_worked{0};
    double hourly_rate{0};

    cout << "Enter hours worked (-1 to end): ";
    cin >> hours_worked;

    while(static_cast<int>(hours_worked) != -1){
        cout << "Enter hourly rate of the employee ($00.00): ";
        cin >> hourly_rate;

        double salary{0};
        if (hours_worked <= 40)
            salary += hours_worked * hourly_rate;
        else{
            double remainder = hours_worked - 40;
            salary += (40*hourly_rate) + (1.5*hourly_rate*remainder);
        }

        cout << setprecision(2) << fixed;
        cout << "Salary is $" << salary << endl;
        cout <<  "\nEnter hours worked (-1 to end): ";
        cin >> hours_worked;
    }



}
