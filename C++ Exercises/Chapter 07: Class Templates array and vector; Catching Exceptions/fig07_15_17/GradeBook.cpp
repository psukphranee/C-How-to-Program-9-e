#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(const string &name, const array<int, gradeBookLen> &gradeEntry)
  : courseName(name), grades(gradeEntry)
  {

  }

void GradeBook::displayMessage() const{
  cout << "Welcome to the grade book for\n" << courseName << endl;
}

double GradeBook::getAverage() const
{
  int sum = 0;

  for (int item : grades)
    sum += item;

  return static_cast<double>(sum)/(gradeBookLen);
}

int GradeBook::getMinimum() const
{
  int minimum = 100;

  for(int item: grades)
    (item < minimum) ? (minimum = item) : 0 ;

  return minimum;
}
int GradeBook::getMaximum() const
{
  int maximum = 0;

  for(int item: grades)
    (item > maximum) ? (maximum = item) : 0 ;

  return maximum;
}

string GradeBook::getCourseName() const
{
  return courseName;
}

void GradeBook::setCourseName(const string &name)
{
    courseName = name;
}

void GradeBook::processGrades() const
{
  outputGrades();

  cout << "Class average is " << getAverage()
      << "\nLowest grade is " << getMinimum()
      << "\nHighest grade is " << getMaximum()
      << endl;

  outputBarChart();
}

void GradeBook::outputBarChart() const
{
  const size_t gradeIntervals = 11;
  array<unsigned int, gradeIntervals> frequency = {};

  cout << "\nGrade distribution:\n";

  for(int i : grades)
    ++frequency[i/10];

  for(size_t i = 0; i < frequency.size(); i++){
    if(0 == i){
      cout << "  0-9: ";
    }else if(10 == i){
      cout << "  100: ";
    }else
      cout << 10*i << "-" << 10*i + 9 << ": ";

    
    for(unsigned int j = 0; j < frequency[i]; j++){
      cout << "*";
    }

    cout << endl;
  }

  cout << endl;
}

void GradeBook::outputGrades() const
{
  cout << "The grades are: \n" << endl;

  for(size_t i = 0; i < grades.size(); i++){
    cout << "Student " << setw(2) << i+1 << ":" << setw(4) << grades[i] << "\n";
  }

  cout << endl;
}
