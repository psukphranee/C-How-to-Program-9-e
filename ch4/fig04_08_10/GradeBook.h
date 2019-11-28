#include <string>

class GradeBook
{
public:
    explicit GradeBook(std::string);
    void setCourseName(set::string);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAverage() const;
private:
    std::string courseName;
}
