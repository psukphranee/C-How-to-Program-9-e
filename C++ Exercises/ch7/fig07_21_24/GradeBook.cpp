#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(const string &name, const array<std::array<int, exams>, students> &gradeInput)
  :courseName(name), grades(gradeInput)
{

}

//course name functions
void GradeBook::setCourseName(const std::string &name)
{
  courseName = name;
}
string GradeBook::getCourseName() const
{
  return courseName;
}

//calculating functions
int GradeBook::getMinimumScore() const{
  int minimum = 100;

  for(size_t i = 0; i < GradeBook::students; ++i){
    for(size_t j = 0; j < GradeBook::exams; ++j){
      (grades[i][j] < minimum) ? (minimum = grades[i][j]) : 0;
    }
  }
  return minimum;
}

int GradeBook::getMaximumScore() const{
  int maximum = 0;

  for(auto const &row: grades){
    for(auto const &score: row){
      (score > maximum) ? (maximum = score) : 0;
    }
  }
  return maximum;
}

double GradeBook::getAverage(const std::array<int, exams> &row ) const
{
  int sum = 0;

  for(int score: row)
    sum += score;

  return static_cast<double>(sum)/4;
}

//output functions
void GradeBook::displayMessage() const
{
  cout << "Welcome to the grade book for\n" << courseName << endl;
}

void GradeBook::processGrades() const{
  outputGrades();

  cout << "\nLowest grade is " << getMinimumScore()
      << "\nHighest grade is " << getMaximumScore() << endl << endl;

  outputBarChart();
}

void GradeBook::outputGrades() const
{
  cout << "The grades are:\n\n";
  cout << "          "
        << setw(8) << "Test 1"
        << setw(8) << "Test 2"
        << setw(8) << "Test 3"
        << setw(9) << "Average"
        << endl;

  for(size_t i = 0; i < grades.size(); ++i){
    cout << "Student " << setw(2) << i+1;
      for(size_t j = 0; j < grades[i].size(); ++j){
        cout << setw(8) << grades[i][j];
      }


    cout << setw(9) << getAverage(grades[i]) << endl;
  }
}

void GradeBook::outputBarChart() const
{
  cout << "Overall grade distribution:\n";

  array<unsigned int, 11> frequency = {};

  for(auto const &row : grades)
    for(auto const &element : row)
      ++frequency[element/10];

  for(size_t i = 0; i < frequency.size(); ++i){
    if(0 == i)
      cout << "  0-9:";
    else if(10 == i)
      cout << "  100:";
    else
      cout << 10*i << "-" << 10*i + 9 << ":";

    for(unsigned int j = 0; j < frequency[i]; ++j)
      cout << "*";

    cout << endl;
  }
}
