#include <iostream>
#include <cmath>
using namespace std;

int main(){
    unsigned int power_counter{0};
    unsigned int binary_number{0};
    unsigned int copy_number{0};
    unsigned int running_sum{0};

    cout << "Enter a binary number: ";
    cin >> binary_number;

    copy_number = binary_number;

    while(copy_number > 0){
        unsigned int current_digit{0};

        current_digit = copy_number - ((copy_number / 10 ) * 10);
        running_sum += current_digit * pow(2,power_counter);

        power_counter++;

        copy_number /= 10;
    }

    cout << "Decimal: " << running_sum << endl;

}
