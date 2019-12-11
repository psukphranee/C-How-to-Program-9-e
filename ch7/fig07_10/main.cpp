#include <iostream>
#include <ctime>
#include <iomanip>
#include <random>
#include <array>
using namespace std;

int main()
{
  const size_t arraySize = 7;
  array<unsigned int, arraySize> faceCount = {};

  default_random_engine engine(static_cast<unsigned int>(time(0)));
  uniform_int_distribution<unsigned int> randInt(1,6);

  for(unsigned int i = 1; i <= 6000000; ++i){
    ++faceCount[randInt(engine)];
  }

  cout << setw(4) << "Face" << setw(13) << "Frequency" << endl;
  for(unsigned int j = 1; j < arraySize; ++j){
    cout << setw(4) << j << setw(13) << faceCount[j] << endl;
  }
}
