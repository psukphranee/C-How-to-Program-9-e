#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:
  Employee(const std::string &, const std::string &);
  ~Employee();

  std::string getFirst() const;
  std::string getLast() const;

  static unsigned int getCount();
private:
  std::string firstName;
  std::string lastName;

  static unsigned int employeeCount;
};

#endif
