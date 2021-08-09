#include "Bottle.h"
#include <vector>
#include <iostream>

using namespace std;

Bottle::Bottle(int i)
    : poison(false)
{
    index = i;
}

void Bottle::printIndex(){
    cout << index << endl;
}

int Bottle::getIndex(){
    return index;
}

int Bottle::setIndex(unsigned i){
    return index=i;
}

bool Bottle::getBit(int position){
    unsigned MASK = 1 << position;
    return (MASK & index);
}