#include <iostream>
#include <cmath>
using namespace std;

unsigned int gcd(unsigned int x, unsigned int y){
  unsigned int max = x > y ? x : y;
  unsigned int min = x < max ? x : y;

  if(x == 0 || y == 0){
    return max;
  }
  else{
    return gcd(min, max % min);
  }
}

int main()
{
  unsigned int one = 0;
  unsigned int two = 0;

  cout << "Enter a number for x and y: ";
  cin >> one >> two;

  cout << "The GCD of " << one << " and " << two << " is " << gcd(one,two) << endl;
}
