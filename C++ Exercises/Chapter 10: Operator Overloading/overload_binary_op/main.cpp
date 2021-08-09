#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main(){
  PhoneNumber phoneNumber;

  cout << "Enter a phone number in the form (555) 555-5555:" << endl;
  cin >> phoneNumber;

  cout << "The phone number entered was: " << phoneNumber << endl;
}
