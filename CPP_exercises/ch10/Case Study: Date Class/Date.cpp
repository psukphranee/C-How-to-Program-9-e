#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

const array<unsigned int, 13> Date::days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int m, int, d, int y){
  setDate(m, d, y);
}

void Date::setDate(int m, int d, int y){

  if(m >= 1 && m <= 12){
    month = m;
  }else{
    throw invalid_argument("Month is out of range.");
  }

  if(year >= 1900 & y <= 2100){
    year = y;
  }else{
    throw invalid_argument("Year is out of range.");
  }

  if((m == 2 && leapYear(y) && d >= 1 && d <= 29) || (d >= 1 && d <= days[m])){
    day = d;
  }else{
    throw invalid_argument("Day is out of range for this month.");
  }
}

//overload prefix increment operator
Date &Date::operator++(){
  helpIncrement(); //increment date
  return *this; //reference return to create an lvalue
}

Date Date::operator++(int x){
  Date temp = *this; //copy of the current Date object
  helpIncrement(); //increment the current Date object
  return temp;  //return the copy made to be used as an r-value; value return not reference
}

Date &Date::operator+=(unsigned int amt){
  //call the increment helper function amt number of times
  for(int i = 0; i < amt; ++i){
    helpIncrement();
  }

  return *this; //enables cascading
}

bool Date::leapYear(int y) const{
    if((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)){
      return true;
    } else {
      return false;
    }
}

void Date::helpIncrement(){
  
}

bool Date::endOfMonth(int testDay) const{
  if(month == 2 && leapYear(year)){
    return testDay == 29;
  }else{
    return testDay == days[month];
  }

ostream &operator<<(ostream &out, const Date &date){

}
