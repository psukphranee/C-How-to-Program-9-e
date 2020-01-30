#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

unsigned int Employee::employeeCount = 0;

unsigned int Employee::getCount()
{
  return employeeCount;
}

Employee::Employee(const string &first, const string &last)
  : firstName(first), lastName(last)
{
  cout << "Employee constructor for " << firstName << " " << lastName << " called." << endl;
  ++employeeCount;
}


Employee::~Employee()
{
  cout << "~Employee() called for " << firstName << " " << lastName << endl;
  --employeeCount;
}

string Employee::getFirst() const
{
  return firstName;
}

string Employee::getLast() const
{
  return lastName;
}
