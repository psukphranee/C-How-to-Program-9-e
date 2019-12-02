#include <iostream>
using namespace std;

int main()
{
  unsigned int pass = 0;
  unsigned int no_pass = 0;
  unsigned int student_counter = 1;

  while (student_counter <= 10)
  {
    cout << "Enter result (1 = pass, 2 = fail): ";
    int current_result = 0;
    cin >> current_result;

    if(current_result == 1)
      pass += 1;
    else
      no_pass += 1;

    student_counter += 1;
  }

  cout << "Passed " << pass << "\nFailed " << no_pass << endl;
  if (pass >  8)
    cout << "Bonus to instructor!" << endl;
}
