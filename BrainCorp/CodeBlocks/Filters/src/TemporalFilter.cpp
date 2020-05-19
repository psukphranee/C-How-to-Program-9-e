#include "TemporalFilter.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

TemporalFilter::TemporalFilter(int stackLen)
:scan_hold_len(stackLen + 1)
{}

vector<float> TemporalFilter::update(vector<float> &reading){
  //push the argument to the scan_buffer
  addToScanBuffer(reading);
  //return the median
  calculateMedianVector();
}

void TemporalFilter::addToScanBuffer(std::vector<float> &reading){
  //if the buffer has scan_hold_len elements, then erase the front before pushing to the back.
  if(scan_buffer.size() == scan_hold_len){
    scan_buffer.erase(scan_buffer.begin());
  }
  scan_buffer.push_back(&reading);
}

void TemporalFilter::printScanBuffer() const{
  for(auto const &item: scan_buffer){
    printVector(*item);
  }
}

void TemporalFilter::printVector(vector<float> &singleVector) const{
  for(auto const &item: singleVector){
    cout << item << ' ';
  }
  cout << endl;
}

vector<float> TemporalFilter::calculateMedianVector(){
  /*We're going to find the median values along the "columns" of scan_buffer. We'll create two vectors, on to store the median value and one to temporarily store values along the columns.*/

  vector<float> median_values; //store the median values. as we find the median values along the columns, these values will be pushed onto median_values.

  //Get the number of columns using size of some row
  int columns = (*(scan_buffer.begin()))->size();
  //cout << "Columns: " << columns << endl; //debug

  for(int i = 0; i < columns; ++i){
    vector<float> tempColumn;
    for(auto const &row : scan_buffer){
      tempColumn.push_back(row->at(i));
    }
    //printVector(tempColumn); //debug
    float medianValue = calculateMedian(tempColumn);
    median_values.push_back(medianValue);
  }
  printVector(median_values);
  return median_values;
}

float TemporalFilter::calculateMedian(vector<float> column){
  size_t size = column.size();

  if (size == 0)
  {
    return 0;  // Undefined, really.
  }
  else
  {
    sort(column.begin(), column.end());
    if (size % 2 == 0)
    {
      return (column[size / 2 - 1] + column[size / 2]) / 2;
    }
    else
    {
      return column[size / 2];
    }
  }
}
