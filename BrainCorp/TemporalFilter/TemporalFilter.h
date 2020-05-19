
#ifndef TEMPORAL_FILTER_H
#define TEMPORAL FILTER_H

#include <vector>

class TemporalFilter{
public:
  TemporalFilter(int = 1); //the constructors argument specifies D, the number of previous scans to consider.
  std::vector<float> update(std::vector<float> &); //the update() function returns a vector of median values. The argument of update will get pushed onto the buffer stack, scan_buffer.
  void addToScanBuffer(std::vector<float> &);
  void printVector(std::vector<float> &) const; //function to print individual vectors in the buffer stack.
  void printScanBuffer() const;
  std::vector<float> calculateMedianVector(); //calculates median of vectors in the scan_buffer.
  float calculateMedian(std::vector<float> );
private:
  int scan_hold_len; //corresponds to D+1, the number of previous scans + one current scan to consider when calculating the median.
  std::vector<std::vector<float> *> scan_buffer; //a vector of pointers. Each pointer points to a vector. There are D number of pointers.
};

#endif //TEMPORAL_FILTER_H
