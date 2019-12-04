#include <iostream>
#include <string>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
    :
    aCount(0),
    bCount(0),
    cCount(0),
    dCount(0),
    fCount(0)
    {
            setCourseName(name);
    }

void GradeBook::setCourseName(std::string name)
{
    if(name.size() <= 25)
        courseName = name;
    else
        cerr <<
}
