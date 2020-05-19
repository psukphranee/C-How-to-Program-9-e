#include <array>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

  vector<float> lidarScanCycle;
  int readingCount = 5; //take from command-line argument

  //input N readings into a vector
  istream_iterator<float> inputFloat(cin);

  //
  for(int i = 0; i < readingCount; ++i){
    ++inputFloat;
    float temp = *inputFloat;
    lidarScanCycle.push_back(temp);

  }

  cout << "End of pushback"  << endl;

  vector<float> *readingPtr = &lidarScanCycle;
  vector<float> tempVector = *readingPtr;
  tempVector[0] = 'a';
  cout << tempVector[0] << " || " << lidarScanCycle[0] << endl;
}
