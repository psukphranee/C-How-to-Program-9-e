#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double rate2{1.02};
    double rate3{1.03};
    double rate4{1.04};
    double rate5{1.05};

    double initial{1000000000};
    int counter = 1;
    double initial_cp = initial;

    cout << setw(5) << "Month" << setw(21) << "2%" << setw(21) << "3%" << setw(21) << "4%" << setw(21) << "5%" << endl;
    cout << fixed << setprecision(0);

    while(initial_cp < 2500000000){

        //initial_cp = initial*pow(rate2, counter);
        cout << setw(5) << counter << setw(21) << initial*pow(rate2, counter) << setw(21) << initial*pow(rate3, counter) << setw(21) << initial*pow(rate4, counter)
         << setw(21) << initial*pow(rate5, counter) << endl;

         initial_cp = initial*pow(rate2, ++counter);
    }
}
