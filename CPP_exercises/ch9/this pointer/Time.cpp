#include <iostream>
#include <iomanip>
#include "Time.h"
#include <stdexcept>
using namespace std;

Time::Time(int h, int m, int s){
  setTime(h, m, s);
}

Time &Time::setTime(int h, int m, int s){
  setHour(h);
  setMinute(m);
  setSecond(s);

  return *this;
}

Time &Time::setHour(int h){
  hour = h;
  return *this;
}

Time &Time::setMinute(int m){
  minute = m;
  return *this;
}

Time &Time::setSecond(int s){
  second = s;
  return *this;
}

unsigned int getHour() const{
  return hour;
}

unsigned int getMinute() const{
  return minute;
}

unsigned int getSecond() const{
  return second;
}

void Time::printUniversal() const
{
  cout << setfill('0');
  cout << setw(2) << getHour() << ":"
    << setw(2) << getMinute() << ":"
    << setw(2) << getSecond();
}

void Time::printStandard() const
{
  cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12 ) << ":"
    << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond()
    << (getHour() < 12 ? "AM" : "PM");
}
