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
    else{
        cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
            << "Limiting course name to the first 25 characters.\n" << endl;
        courseName = name.substr(0,25);
        }
}

string GradeBook::getCourseName() const{
    return courseName;
}

void GradeBook::displayMessage() const{
    cout << "Welcome to the grade book for\n" << courseName << "!\n" << endl;
}

void GradeBook::inputGrades()
{
    cout << "Enter the letter grades.\nEnter the EOF character to end input." << endl;
    int grade = 0;
    while((grade = cin.get()) != EOF)
    {
        switch(grade){
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                cout << "Incorrect letter grade entered. Enter a new grade." << endl;
                break;
        }
    }
}

void GradeBook::displayGradeReport() const
{
    cout << "Number of students who recieved each lette grade:\n"
        << "A: " << aCount << "\n"
        << "B: " << bCount << "\n"
        << "C: " << cCount << "\n"
        << "D: " << dCount << "\n"
        << "F: " << fCount << "\n"
        << endl;
}
