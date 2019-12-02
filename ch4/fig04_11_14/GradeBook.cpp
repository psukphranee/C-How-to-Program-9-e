#include <iostream>
#include <iomanip>
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
  unsigned int counter = 0;

  cout << "Enter grade or -1 to quit: ";
  int grade = 0;
  cin >> grade;

  while(grade != -1){
    total += grade;
    counter += 1;
    cout << "Enter grade or -1 to quit: ";
    cin >> grade;
  }

  if(counter != 0){
    double average = static_cast<double>(total)/counter;
    cout << "The total of all " << counter << " grades entered is " << total << endl;

    cout << setprecision(2) << fixed;
    cout << "Class average is " << average << endl;
  }else{
    cout << "No grades were entered\n." << endl;
  }
}
