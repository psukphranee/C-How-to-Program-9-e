#include <array>
#include <string>
#include "GradeBook.h"
using namespace std;

int main()
{
  array<int, GradeBook::gradeBookLen> grades =
    {87,68,94,100,83,78,85,91,76,87};
  GradeBook myGradeBook("CS101 C++ Programming", grades);
  myGradeBook.displayMessage();
  myGradeBook.processGrades();
}
