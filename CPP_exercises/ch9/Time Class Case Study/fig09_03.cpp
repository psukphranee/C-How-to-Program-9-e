#include "Time.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
  Time myTime;

  cout << "The initial universal time is ";
  myTime.printUniversal();
  cout << "The initial standard time is ";
  myTime.printStandard();

  myTime.setTime(13, 27, 06);

  cout << "\nThe universal after setTime is ";
  myTime.printUniversal();
  cout << "The standard after setTime is ";
  myTime.printStandard();
  cout << endl;
  
  try{
    myTime.setTime(99, 99, 99);
  }
  catch(invalid_argument &e)
  {
    cerr << "Exception: " << e.what() << endl;
  }

  cout << "\nAfter attempting invalid settings:"
    << "\nUniversal time: ";

  myTime.printUniversal();

  cout << "Standard time: ";

  myTime.printStandard();

}
