#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double sales{0};

    cout << "Enter sales in dollars (-1 to end): ";
    cin >> sales;

    while(static_cast<int>(sales) != -1){
        double salary{0};
        salary += 200 + (.09 * sales);

        cout << setprecision(2) << fixed;
        cout << "Salary is: $" << salary << endl;

        cout << "\nEnter Sales in dollars (-1 to end): ";
        cin >> sales;
    }
}
