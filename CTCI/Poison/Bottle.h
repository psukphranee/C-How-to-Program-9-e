#ifndef BOTTLE_H
#define BOTTLE_H

class Bottle{
public:
    explicit Bottle(int=0);
    void printIndex();
    int getIndex();
    int setIndex(unsigned);
    bool isPoison()         {return poison;}
    bool togglePoison()     {poison = (poison == true) ? false : true; return poison;}
    bool getBit(int position);
private:
    unsigned index;
    bool poison;
};

#endif