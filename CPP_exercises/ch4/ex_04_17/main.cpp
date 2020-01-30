#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned int counter = 1;
    double number{0};
    double largest{0};

    while(counter <= 10){
        cout << "Enter a number: ";
        cin >> number;

        if(number > largest)
            largest = number;
        counter++;
    }

    cout << "The largest number is: " << largest << endl;
}
