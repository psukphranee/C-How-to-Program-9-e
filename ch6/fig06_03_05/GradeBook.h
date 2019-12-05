#include <string>

class GradeBook
{
public:
    explicit GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAverage() const;
    int maximum(int, int, int) const;
    void inputGrades();
    void displayGradeReport() const;
private:
    std::string courseName;
    int maximumGrade;
};
