#include "RangeFilter.h"
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

template<typename T> void printVector(const vector<T> &readings);

int main(int argc, char *argv[]){

    RangeFilter testFilter(0, 5); //pass the lower and upper bounds to the filter
    vector<float> lidarScanCycle;

    //create a stream iterator to input objects from cin
    istream_iterator<float> inputFloat(cin);
    float inputItem = *inputFloat; //store floating point number into a variable

    while(inputItem >= 0){ //negative numbers are sentitel values to end input
        //add to vector
        lidarScanCycle.push_back(inputItem);
        inputItem = *(++inputFloat);
        //cout << "inputItem: " << inputItem << endl;
    }

    cout << "End of pushback."  << endl; //notifies end of adding to vector

    cout << "Assigning filter to lidarScanCycle and printing contents using the class' member function.\n";
    testFilter.setVector(lidarScanCycle);
    testFilter.printVector();

    cout << "Testing update().\n";
    printVector(testFilter.update());
}


template<typename T> void printVector(const vector<T> &readings){
    //print function template to print a vectors contents
    for(auto const &reading : readings){
        cout << reading << ' ';
    }

    cout << endl;
}
