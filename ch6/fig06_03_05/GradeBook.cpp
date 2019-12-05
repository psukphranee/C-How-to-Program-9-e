#include <iostream>
#include <iomanip>
#include <string>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
    : maximumGrade(0)
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

void GradeBook::inputGrades()
{
    int grade1;
    int grade2;
    int grade3;

    cout << "Enter three integer grades: ";
    cin >> grade1 >> grade2 >> grade3;

    maximumGrade = maximum(grade1, grade2, grade3);
}

void GradeBook::displayGradeReport() const
{
    cout << "Maximum of grades entered: " << maximumGrade << endl;
}

int GradeBook::maximum(int grade1, int grade2, int grade3) const
{
    int max = grade1;

    if(grade2 > max)
        max = grade2;

    if(grade3 > max)
        max = grade3;

     return max;
}
