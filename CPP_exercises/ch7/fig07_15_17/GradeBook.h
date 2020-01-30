#include <string>
#include <array>

class GradeBook
{
public:
  static const size_t gradeBookLen = 10;

  GradeBook(const std::string &, const std::array<int, gradeBookLen> &);
  void displayMessage() const;
  double getAverage() const;
  int getMinimum() const;
  int getMaximum() const;
  std::string getCourseName() const;
  void setCourseName(const std::string &);
  void processGrades() const;
  void outputGrades() const;
  void outputBarChart() const;

private:

  std::string courseName;
  std::array<int, gradeBookLen> grades;
};
