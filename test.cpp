#include <iostream>
using namespace std;

int main(){
  int x = 3;
  int &x_alias = x;
  int *x_ptr = &x;

  cout << "x_alias: " << x_alias << endl
      << "&x_alias: " << &x_alias << endl
        << "x_ptr: " << x_ptr << endl;
}
