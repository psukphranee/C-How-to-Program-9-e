#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
{
  setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
  if(name.size() <= 25)
    courseName = name;
  else
  {
    courseName = name.substr(0,25);
    cerr << "Name \"" << courseName << "\" exceeds max length (25).\n"
      << "Limiting courseName to first 25 characters.\n" << endl;
  }
}

string GradeBook::getCourseName() const
{
  return courseName;
}

void GradeBook::displayMessage() const
{
  cout << "Welcome to the grade book for " << courseName << "!\n"
   << endl;
}

void GradeBook::determineClassAverage() const
{
  int total = 0;
  unsigned int counter = 1;

  while(counter <= 10){
    cout << "Input student score:";
    int grade = 0;
    cin >>  grade;
    total += grade;
    counter += 1;
  }

  int classAverage = total/10;
  cout << "The total grades for all students in the class is " << total << endl;
  cout << "The class average is " << classAverage << endl;
}
