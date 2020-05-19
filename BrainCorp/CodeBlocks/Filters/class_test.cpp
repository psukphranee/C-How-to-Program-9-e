#include "RangeFilter.h"
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

template<typename T> void printVector(const vector<T> &readings);

int main(int argc, char *argv[]){

    int readingCount;

    if(argc == 3){
        char *parseInt = argv[2] + 2; //set pointer to after the equal sign
        readingCount = atoi(parseInt);
        cout << "parseInt: " << readingCount << endl;
    }else if(argc == 2){
        char *parseInt = argv[1] + 2; //set pointer to after the equal sign
        readingCount = atoi(parseInt);
        cout << "parseInt: " << readingCount << endl;
    }

    ; //take from command-line argument
    RangeFilter testFilter(readingCount, 0, 5.6);
    vector<float> lidarScanCycle;

    //input N readings into a vector
    istream_iterator<float> inputFloat(cin);
    /*********************************************************************************************/
    float inputItem = *inputFloat;
    //cout << "inputItem: " << inputItem << endl;
    while(inputItem >= 0){
        //add to vector
        lidarScanCycle.push_back(inputItem);
        inputItem = *(++inputFloat);
        //cout << "inputItem: " << inputItem << endl;
    }
    /*
    for(int i = 0; i < readingCount - 1; ++i){
        float temp = *(inputFloat++);
        lidarScanCycle.push_back(temp);
    }
    float temp = *(inputFloat);
    lidarScanCycle.push_back(temp);
    /********************************************************************************************/
    cout << "End of pushback."  << endl;

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
