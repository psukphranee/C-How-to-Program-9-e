#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int input{0};
    int digit1{0};
    int digit2{0};
    int digit3{0};
    int digit4{0};
    int temp{0};
    int output{0};

    cout << "Enter a 4-digit message: ";
    cin >> input;

    digit1 = (input / pow(10,1)) * pow(10,1);
    digit2 = (input / pow(10,2)) * pow(10,2);
    digit3 = (input / pow(10,3)) * pow(10,3);
    digit4 = (input / pow(10,4)) * pow(10,4);

    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 7) % 10;
    digit3 = (digit3 + 7) % 10;
    digit4 = (digit4 + 7) % 10;

    temp = digit1;
    digit1 = digit3;
    digit3 = temp;

    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    output = digit1 * pow(10,0) + digit2 * pow(10,1) + digit3 * pow(10,2) + digit4 * pow(10,3);

    cout << "Encoded message: " << output << endl;
}
