#include "PhoneNumber.h"
#include <iomanip>
using namespace std;

ostream &operator<<(ostream &output, const PhoneNumber &phone){
  output << "(" << phone.areaCode << ") "
      << phone.exchange << "-" << phone.line;
  return output;
}

istream &operator>>(istream &input, PhoneNumber &phone){
  input.ignore();
  input >> setw(3) >> phone.areaCode;
  input.ignore(2);
  input >> setw(3) >> phone.exchange;
  input.ignore();
  input >> setw(4) >> phone.line;

  return input;
}
