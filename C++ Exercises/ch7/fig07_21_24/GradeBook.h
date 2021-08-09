#include <array>
#include <string>

class GradeBook
{
public:
  static const size_t students = 10;
  static const size_t exams = 3;

  //constructor, takes a course title and 2D array of grades
  GradeBook(const std::string &, const std::array<std::array<int, exams>, students> &);

  //course name functions
  void setCourseName(const std::string &);
  std::string getCourseName() const;

  //calculating functions
  int getMinimumScore() const;
  int getMaximumScore() const;
  double getAverage(const std::array<int, exams> & ) const; //gets average of a row

  //output functions
  void displayMessage() const;
  void outputGrades() const;
  void outputBarChart() const;
  void processGrades() const;
private:
  std::string courseName;
  std::array<std::array<int, exams>, students> grades;
};
