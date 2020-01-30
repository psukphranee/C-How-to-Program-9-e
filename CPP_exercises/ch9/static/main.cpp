#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
  cout << "Number of employees before instantiation of any objects is " << Employee::getCount() << endl;

  {
    Employee e1("Susan", "Baker");
    Employee e2("Robert", "Jones");

    cout << "Number of employees after objects are instantiated is "
      << Employee::getCount() << endl;

    cout << "\n\nEmployee 1: "
           << e1.getFirst() << " " << e1.getLast()
           << "\nEmployee 2: "
           << e2.getFirst() << " " << e2.getLast() << "\n\n";
  } // end nested scope in main

     // no objects exist, so call static member function getCount again
     // using the class name and the binary scope resolution operator
  cout << "\nNumber of employees after objects are deleted is "
        << Employee::getCount() << endl;
}
