#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  unsigned int currentTrip = 0;
  unsigned int overallTrip = 0;
  unsigned int overallGallons = 0;

  cout << "Enter miles driven (-1 to quit): ";
  cin >> currentTrip;

  while (currentTrip != -1)
  {
    overallTrip += currentTrip;
    unsigned int currentGallons = 0;
    cout << "Enter gallons used: ";
    cin >> currentGallons;
    overallGallons += currentGallons;

    double currentMPG = static_cast<double>(currentTrip)/currentGallons;
    double overallMPG = static_cast<double>(overallTrip)/overallGallons;

    cout << setprecision(6) << fixed;
    cout << "MPG this trip: " << currentMPG << "\nTotal MPG: " << overallMPG << "\n" << endl;

    cout << "Enter miles driven (-1 to quit): ";
    cin >> currentTrip;
  }
}
