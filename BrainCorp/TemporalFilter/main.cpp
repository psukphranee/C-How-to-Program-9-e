/*******************************************************
Demonstration
********************************************************/

#include "TemporalFilter.h"
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T> void printVector(const vector<T> &);
template<typename T> void printReport(const vector<T> &median, TemporalFilter *);
int main(){
  TemporalFilter testFilter(3); //pass the number D to argument constructor

  vector<float> testVect1 = {0,1,2,1,3};
  vector<float> testVect2 = {1,5,7,1,3};
  vector<float> testVect3 = {2,3,4,1,0};
  vector<float> testVect4 = {3,3,3,1,3};
  vector<float> testVect5 = {10,2,4,0,0};

  vector<vector<float>> table = {testVect1,testVect2,testVect3,testVect4,testVect5};
  /*
  printVector(testFilter.update(testVect1));
  printVector(testFilter.update(testVect2));
  printVector(testFilter.update(testVect3));
  printVector(testFilter.update(testVect4));
  printVector(testFilter.update(testVect5));

  cout << "-----------Current Scan and Previous D Scans--------------------" << endl;
  testFilter.printScanBuffer();
  */
  for(auto &item : table){
    printReport(testFilter.update(item), &testFilter);
  }
  //printReport(testFilter.update(testVect1), &testFilter);
}
template<typename T> void printReport(const vector<T> &median, TemporalFilter *filter){
  cout << "The temporal median of the following vectors: " << endl;
  filter->printScanBuffer();
  cout << " is \n[";
  printVector(median);
  cout << "]\n-----------------------------" << endl;
}

template<typename T> void printVector(const vector<T> &readings){
  for(auto const &reading : readings){
    cout << setw(3) << reading << ' ';
  }
}
