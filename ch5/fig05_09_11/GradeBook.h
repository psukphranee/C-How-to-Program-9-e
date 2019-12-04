#include <string>

class GradeBook{
public:
    explicit GradeBook(std::string);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void displayMessage() const;
    void displayGradeReport() const;
    void inputGrades();
private:
    std:string courseName;
    unsigned int aGrade;
    unsigned int bGrade;
    unsigned int cGrade;
    unsigned int dGrade;
    unsigned int fGrade;
}
