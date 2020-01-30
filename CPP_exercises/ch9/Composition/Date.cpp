#include "Date.h"
#include <iostream>
#include <stdexcept>
#include <array>

using namespace std;

Date::Date(int m, int d, int y)
{
  //validate month
  if(m >= 1 && m < monthsPerYear)
    month = m;
  else
    throw invalid_argument("Month must be between 1 - 12");
  //assign year
  year = y;
  //assign day
  day = checkDay(d);
  //output Date to show constructor is called
  cout << "Date object constructor for date ";
  print();
  cout << endl;
}

void Date::print() const
{
  cout << month << "/" << day << "/" << year;
}

Date::~Date()
{
  cout << "Date object destructor for date ";
  print();
  cout << endl;
}

unsigned int Date::checkDay(int d) const{
  static const array<int, monthsPerYear + 1> daysPerMonth =
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(d > 0 && d <= daysPerMonth[month])
    return d;

  if(month == 2 && d == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    return day;

  throw invalid_argument("Invalid day for current month and year");
}
