#include <vector>
#include <iostream>
#include <algorithm>
#include "RangeFilter.h"
using namespace std;

RangeFilter::RangeFilter(float inf, float sup)
    : range_min(inf), range_max(sup)
{

}

void RangeFilter::setVector(vector<float> &input){
    readingsPtr = &input;
}

void RangeFilter::printVector() const{

    for(auto const &reading : *readingsPtr){
        cout << reading << ' ';
    }
    cout << endl;
}

vector<float> RangeFilter::update() const{

    //initialize a copy of the vector that the filter is applied to
    vector<float> modified_vector = *readingsPtr;

    //truncate reading values to be <= range_max
    for(auto &item : modified_vector){
        if(item > range_max){
            item = range_max;
        }else if(item < range_min){
            item = range_min;
        }
    }
    //debugging
    return modified_vector;
}
