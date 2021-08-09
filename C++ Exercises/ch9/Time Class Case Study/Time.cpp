#include "Time.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>

using namespace std;

Time::Time()
  : hour(0), minute(0), second(0)
{

}

void Time::setTime(int h, int m, int s)
{
  //Do error checking to see if h,m,s are in [0,24), [0,60), [0,60), respectively.
  if((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)){
    hour = h;
    minute = m;
    second = s;
  }else
    throw invalid_argument("hour, minute, and/or second was out of range");
}

void Time::printUniversal() const
{
  //print time as 13:30:07
  cout << setfill('0');
  cout << setw(2) << hour << ":"
    << setw(2) << minute << ":"
    << setw(2) << second << endl;

}

void Time::printStandard() const
{
  // e.g. 1:27:06 PM
  cout << setfill('0');
  cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
      << setw(2) << minute << ":"
      << setw(2) << second << " "
      << (hour < 12 ? "AM" : "PM") << endl;
}
