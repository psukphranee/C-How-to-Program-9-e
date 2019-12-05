#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    for(unsigned int i = 1; i <= 20; i++){
        cout << setw(10) << (rand() % 6) + 1;

        if ((i % 5) == 0){
            cout << endl;
        }
    }
}
