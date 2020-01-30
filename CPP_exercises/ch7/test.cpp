#include <array>
#include <iostream>
using namespace std;

void printArray(array<int, int> &);

int main(){
  cout << "Testing\n";
  array<int, 9> testArray = {};

  printArray(testArray);

}

void printArray(array<int, int x> &param){
  cout << "does this work\n";
}
