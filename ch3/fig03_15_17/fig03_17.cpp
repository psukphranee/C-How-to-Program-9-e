#include <iostream>
#include "GradeBook.h"
using namespace std;

int main()
{
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures");

    //display each GradeBook's courseName
    cout << "gradeBook1's initial course name is: " << gradeBook1.getCourseName()
        << "\ngradeBook2's initial course name is: " << gradeBook2.getCourseName()
        << endl;

    gradeBook1.setCourseName("CS101 C++ Programming");

    cout << "\ngradeBook1's course name is: " << gradeBook1.getCourseName()
        << "\ngradeBook2's course name is: " << gradeBook2.getCourseName()
        << endl;
}
