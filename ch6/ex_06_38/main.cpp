#include <iostream>
using namespace std;

void moveDisks(unsigned int disk_count, int initial_peg, unsigned int destination_peg, unsigned int buffer_peg)
{
  if(disk_count == 1){
    cout << initial_peg << " -> " << destination_peg << endl;
  }else{
    moveDisks(disk_count - 1, initial_peg, buffer_peg, destination_peg);
    moveDisks(1, initial_peg, destination_peg, buffer_peg);
    moveDisks(disk_count - 1, buffer_peg, destination_peg, initial_peg);
  }
}

int main(){
  unsigned int disks = 0;
  unsigned int initial = 1;
  unsigned int destination = 3;
  unsigned int buffer = 2;

  cout << "Enter disks, initial peg, destination peg, and buffer peg: ";
  cin >> disks >> initial >> destination >> buffer;

  moveDisks(disks, initial, destination, buffer);

}
