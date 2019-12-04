#include <iostream>
using namespace std;

int main(){
    unsigned int box_size{0};
    unsigned int outer_counter{1};

    cout << "Enter a box size: ";
    cin >> box_size;

    while(outer_counter <= box_size){
        cout << "*";

        unsigned int inner_counter={2};
        while (inner_counter <= (box_size - 1)){
            if((outer_counter == 1) || (outer_counter == box_size))
                cout << "*";
            else
                cout << " ";

            inner_counter += 1;
        }


        cout << "*" << endl;
        outer_counter += 1;
    }
}
