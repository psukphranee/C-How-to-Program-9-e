#include <vector>
#include <array>
#include <iostream>
#include <iomanip>
#include "Bottle.h"

using namespace std;

bool addDrop(Bottle &, int &);
void printResults(vector<int> &);
unsigned constructResult(vector<int> &);

int main(){
    
    int poisonIndex;
    cout << "Enter poison index:";
    cin >> poisonIndex;

    vector<Bottle> bottles;
    vector<int> testStrips(10, 0);

    //initialize vector of 1000 bottles and set their indices
    for (int i = 0; i < 1000; ++i){
        bottles.push_back(Bottle(i));
    }
    
    //Toggle a bottle to be poison per user input
    bottles[poisonIndex].togglePoison();
    cout << bottles[poisonIndex].isPoison() << endl;

    //iterate through bottles and add drop to test strip
    for (auto bottle : bottles){
        for (int i = 0; i < 10; ++i){
            //check each bit. if bit position is 1, add a drop to corresponding test strip. if 0 then leave it alone
            if(bottle.getBit(i)){
                cout << "Bottle: " << bottle.getIndex() << " to strip " << i << endl;
                addDrop(bottle, testStrips[i]);
            }
        }
    }
    
    cout << "---------Results---------\n";
    printResults(testStrips);

    cout << "---------Poison Bottle---------\n";
    cout << constructResult(testStrips) << endl;
    return 0;
}

bool addDrop(Bottle &bottle, int &strip){
    return strip = strip or bottle.isPoison();
}

void printResults(vector<int> &testStrips){
    for(int i = 0; i < testStrips.size(); ++i){
        cout << "Strip " << setw(2) << i << ":" << (testStrips[i] ? "Positive" : "Negative") << endl;
    }
    cout << endl;
}

unsigned constructResult(vector<int> &testStrips){
    unsigned result = 0;
    for(int i=0; i < testStrips.size(); ++i){
        if(testStrips[i]){
            result |= 1 << i;
        }
    }
    return result;
}