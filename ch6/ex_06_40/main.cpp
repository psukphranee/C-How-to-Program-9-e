#include <iostream>
using namespace std;

unsigned long int factorial(unsigned long number){
  if(number <= 1){
    return 1;
  }else{
    cout << "\t" << number << "*";
    return factorial(number - 1);
  }
}

int main(){
  for (unsigned int i = 1; i <= 10; i++){
    cout << i << "! = " << factorial(i) << endl;
  }
}
