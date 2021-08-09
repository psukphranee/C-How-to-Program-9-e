#include <iostream>
using namespace std;

class Count{
  friend void setX(Count &, int);
public:
  Count()
    : x(0)
  {

  }

  void print() const { cout << x;}
private:
  int x;
};

void setX(Count &c, int input){
  c.x = input;
}

int main()
{
  Count myCount;
  cout << "myCount.x after initialization: ";
  myCount.print();
  setX(myCount, 8);
  cout << "\nmyCount.x after call to setX friend function: ";
  myCount.print();
  cout << endl;
}
