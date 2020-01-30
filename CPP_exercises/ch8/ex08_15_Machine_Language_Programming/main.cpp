/*
Revision 1 of Simpletron Computer interpreter.
I created this from scratch without the books guidance. 
The next revision will be consistent with the books exercise.
*/

#include <iostream>
using namespace std;

void loadInstructions(const int *instructions, const int instructionSize, int * memoryBlock);
void setOpOff(int &operation_code, int &memOffset, const int *instructionPtr);
int IO_function(int * memPtr, int operation_code);
int loadStore(int &accumulator, int * memPtr, int code);
int arithmetic(int & accumulator, int * memPtr, int code);
int branchFunc(const int accumulator, const int memOffset, const int instructionOffset, int code);

int main()
{

  //Virtual memory
  int memory[100] = {};
  int accumulator = 0;

  //program variables
  int operation_code = 0;
  int memOffset = 0;
  int instructionOffset = 0;

  //memoryPtr points to 1st element of memory array
  int * memoryPtr = memory;
  int * instructionPtr = nullptr;

  //instructions
  int instructions[] = {1009,1010,2009,3110,4107,1109,4300,1110,4300};
  int instructionSize = sizeof(instructions)/sizeof(instructions[0]);

  loadInstructions(instructions, instructionSize, memoryPtr);
  instructionPtr = memory + instructionOffset;
  setOpOff(operation_code, memOffset, instructionPtr);
  memoryPtr = memory + memOffset;

  cout << "Executing line " << instructionOffset + 1 << " of code: " << *instructionPtr << endl;

  while(operation_code != 43){
    switch(operation_code){
      case 10:
      case 11:
        //cout << "Calling I/O function with code " << operation_code << " and memory offset " << memOffset << endl;
        IO_function(memoryPtr, operation_code);
        (++instructionOffset > 99) ? (operation_code = 43) : 0;
        break;
      case 20:
      case 21:
        loadStore(accumulator, memoryPtr, operation_code);
        (++instructionOffset > 99) ? (operation_code = 43) : 0;
        break;
      case 30:
      case 31:
      case 32:
      case 33:
        arithmetic(accumulator, memoryPtr, operation_code);
        (++instructionOffset > 99) ? (operation_code = 43) : 0;
        break;
      case 40:
      case 41:
      case 42:
        instructionOffset = branchFunc(accumulator, memOffset, instructionOffset, operation_code);
        break;
      default:
        cout << "Unrecognized code: " << operation_code << "...exiting\n." << endl;
        operation_code = 43;
        continue;
    }

    instructionPtr = memory + instructionOffset;
    cout << endl << "Executing line " << instructionOffset + 1 << " of code: " << *instructionPtr << endl;
    setOpOff(operation_code, memOffset, instructionPtr);
    memoryPtr = memory + memOffset;
  }
}

void loadInstructions(const int *instructions, const int instructionSize, int * memoryBlock){

  cout << "Loading " << instructionSize << " lines of instructions into memory...";

  for(int i = 0; i < instructionSize; ++i){
    *(memoryBlock + i) = *(instructions + i);
  }

  cout << "Done.\n" << endl;
}

void setOpOff(int &operation_code, int &memOffset, const int *instructionPtr){

  //cout << "Separating word: " << *instructionPtr << " into operation code and memory location." << endl;

  int opCode = *instructionPtr / 100;
  operation_code = opCode;
  //cout << "Operation code is " << opCode << endl;

  int temp = operation_code * 100;
  memOffset = (*instructionPtr) - temp;
  //cout << "Memory offset is " << (*instructionPtr) - temp << endl << endl;

}

int IO_function(int * memPtr, int code){

  int temp = 0;

  if(code == 10){
    cout << "Enter an integer to memory location " << memPtr << ": ";
    cin >> temp;
    *memPtr = temp;
  }/* expression */

  if(code == 11){
    cout << memPtr << " value is " << *memPtr << endl;
  }

}

int loadStore(int &accumulator, int * memPtr, int code){

  if(code == 20){
    cout << "Loading " << *memPtr << " from memory " << memPtr << " to accumulator...";
    accumulator = *memPtr;
  }

  if(code == 21){
    cout << "Loading " << accumulator << " from accumulator to memory " << memPtr << "...";
    *memPtr = accumulator;
  }

  cout << "Done." << endl;
}

int arithmetic(int & accumulator, int * memPtr, int code){

  cout << "Accumulator value " << accumulator << endl;

  switch (code) {
    case 30: //add
      cout << "Add " << *memPtr << " to accumulator: " << accumulator << " + " << *memPtr << " = ";
      accumulator += *memPtr;
      cout << accumulator << endl;
      break;
    case 31: //Subtract
      cout << "Subtract " << *memPtr << " to accumulator: " << accumulator << " + " << *memPtr <<  " = ";
      accumulator -= *memPtr;
      cout << accumulator << endl;
      break;
    case 32: //Divide
      cout << "Divide accumulator by " <<  *memPtr << ": " << accumulator << " / " << *memPtr <<  " = ";
      accumulator /= *memPtr;
      cout << accumulator << endl;
      break;
    case 33: //Multiply
      cout << "Multiply accumulator by " << *memPtr << ": " << accumulator << " * " << *memPtr <<  " = ";
      accumulator *= *memPtr;
      cout << accumulator << endl;
      break;
    default:
      break;
  }
}

int branchFunc(const int accumulator, const int  memOffset, const int instructionOffset, int code){

  if(code == 40){
    return memOffset;
  }else if((code == 41) && (accumulator < 0)){
    return memOffset;
  }else if((code == 42) && (accumulator == 0)){
    return memOffset;
  }else{
    return instructionOffset;
  }
}
