#include <array>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename T> void printVector(const vector<T> &readings);

int main(){

    vector<float> lidarScanCycle;
    int readingCount = 5; //take from command-line argument

    //input N readings into a vector
    istream_iterator<float> inputFloat(cin);

    /* The following for-loop and the 2 lines of subsequent code read N amount of inputs from cin.
    The for-loop reads N-1 items and the subsequent code reads the Nth item.*/
    for(int i = 0; i < readingCount - 1; ++i){
        float temp = *(inputFloat++);
        lidarScanCycle.push_back(temp);
    }
    float temp = *(inputFloat);
    lidarScanCycle.push_back(temp);

    cout << "End of pushback"  << endl;

    printVector(lidarScanCycle);

}

template<typename T> void printVector(const vector<T> &readings){

    for(auto const &reading : readings){
        cout << reading << ' ';
    }

    cout << endl;
}

