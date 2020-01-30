#include <iostream>
#include <array>
using namespace std;

int main(){

  const size_t arraySize = 11;
  array<unsigned int, arraySize> gradeDist =
    {0,0,0,0,0,0,1,2,4,2,1};

  cout << "Grade distribution:\n";

  for(size_t i = 0; i < gradeDist.size(); i++){
    if(0 == i){
      cout << "  0-9:";
    }else if(10 == i){
      cout << "  100:";
    }else{
      cout << 10*i << "-" << 10*i+9 << ":";
    }
    for(unsigned int j = 0; j < gradeDist[i]; ++j){
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;
}
