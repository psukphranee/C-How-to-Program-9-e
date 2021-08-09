#include <iostream>
using namespace std;

int squareByValue(int);
void squareByReference(int &);

int main(){
  int x = 2;
  int z = 4;

  cout << "x = " << x << " before squareByValue\n";
  cout << "Value returned by squareByValue: " << squareByValue(x) << endl;
  cout << "x = " << x << " after squareByValue\n" << endl;

  cout << "z = " << z << " before squareByReference\n";
  squareByReference(z);
  cout << "z = " << z << " after squareByReference\n";
}

int squareByValue(int input){
  return input*input;
}

void squareByReference(int &input){
  input *= input;
}
