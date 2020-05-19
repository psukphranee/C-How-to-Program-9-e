#ifndef RANGEFILTER_H
#define RANGEFILTER_H

#include <vector>

class RangeFilter
{
    /* RangeFilter class truncates the lidar readings to be in
    [range_min, range_max]. The lidar readings are understood to be containted
    in a vector. The filter modifies the vector it is applied to.
    */
    public:
        RangeFilter(float = 0.0, float = 0.0); //specify number of readings per scan, range_min, range_max, respectively
        void printVector() const; //print contents of the vector this filter is applied to
        void setVector(std::vector<float> &input); //sets the vector the filter is to be applied to
        std::vector<float> update() const; //apply the fitler to a copy of the readings and return the copy
        //virtual ~RangeFilter();
    private:
        std::vector<float> *readingsPtr; //points to the vector an instance of the filter its applied to
        //int reading_counts; //readings per scan
        float range_min; //lower bound
        float range_max; //upper bound.
};

#endif // RANGEFILTER_H
