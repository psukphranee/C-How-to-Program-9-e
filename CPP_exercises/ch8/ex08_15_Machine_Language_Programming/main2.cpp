/*
Revision 2 of Simpletron Computer interpreter.
This is the first revision of main.cpp to be consistent
with the book in terms of naming convention and program structure.
------------------------------------------------------------------
Additional features to revision 1 are:
  -memory dump upon exiting
  -inputing instructions from user, including value checking
  -divide by zero checking
  -accumulator overflow

Vaiable additions:
  -instructionRegister, a temporary area to hold instructions for processing
Variable name changes:
  operand -> operand
*/

#include <iostream>
#include <iomanip>
using namespace std;

//void loadInstructions(const int *instructions, const int instructionSize, int * memoryBlock);
void loadInstructions(int *memory, const int memorySize);
void setOpOff(int &operationCode, int &operand, const int instructionRegister);
int IO_function(int * memPtr, int operationCode);
int loadStore(int &accumulator, int * memPtr, int code);
int arithmetic(int & accumulator, int * memPtr, int code);
int branchFunc(const int accumulator, const int operand, const int instructionCounter, int code);
void memoryDump(const int &accumulator, const int &instructionCounter, const int &instructionRegister, const int &operationCode, const int &operand, const int *memory);
void displayIntro();

int main()
{
  displayIntro();
  //Virtual memory
  int memory[100] = {};
  int accumulator = 0;

  //program variables
  int operationCode = 0; //2-digit operation code telling the computer what to do
  int operand = 0; //an offset indicating the memory block on which to operate on, i.e. 0 is first block, 1 is second block, etc.
  int instructionCounter = 0; //an offset indicating the memory block of the current instruction
  int instructionRegister = 0; //buffer holding a copy of the instruction value for processing

  //memoryPtr points to 1st element of memory array
  int * memoryPtr = memory;
  int * instructionPtr = nullptr;

  //instructions
  //int instructions[] = {1009,1010,2009,3110,4107,1109,4300,1110,4300};

  int memorySize = sizeof(memory)/sizeof(memory[0]);

  loadInstructions(memory, memorySize); //loads instructions into memory

  /* The two following statements will be compactly written in array indexing notation
  instructionPtr = memory + instructionCounter; //points to current instruction being executed. at this line, it is the first location of the memory block
  instructionRegister = *instructionPtr; //copies the instruction into the instruction
  */
  instructionRegister = memory[instructionCounter];

  setOpOff(operationCode, operand, instructionRegister); //assigns operationCode and operand variables of the current instruction
  memoryPtr = memory + operand;
  cout << "\nRunning program... " <<  endl;
  //cout << "Executing line " << instructionCounter + 1 << " of code: " << instructionRegister << endl;

  while(operationCode != 43){
    switch(operationCode){
      case 10:
      case 11:
        //cout << "Calling I/O function with code " << operationCode << " and memory offset " << operand << endl;
        IO_function(memoryPtr, operationCode);
        (++instructionCounter > 99) ? (operationCode = 43) : 0;
        break;
      case 20:
      case 21:
        loadStore(accumulator, memoryPtr, operationCode);
        (++instructionCounter > 99) ? (operationCode = 43) : 0;
        break;
      case 30:
      case 31:
      case 32:
      case 33:
        operationCode = arithmetic(accumulator, memoryPtr, operationCode);
        (++instructionCounter > 99) ? (operationCode = 43) : 0;
        break;
      case 40:
      case 41:
      case 42:
        instructionCounter = branchFunc(accumulator, operand, instructionCounter, operationCode);
        break;
      default:
        cout << "Unrecognized code: " << operationCode << "...exiting\n." << endl;
        operationCode = 43;
        continue;
    }
    /* The two following statements will be compactly written in array indexing notation
    instructionPtr = memory + instructionCounter;
    instructionRegister = *instructionPtr;
    */
    instructionRegister = memory[instructionCounter];

    //cout << endl << "Executing line " << instructionCounter + 1 << " of code: " << instructionRegister << endl;
    setOpOff(operationCode, operand, instructionRegister);
    memoryPtr = memory + operand;
  }

  if(operationCode == 43){
    cout << endl;
    memoryDump(accumulator, instructionCounter, instructionRegister, operationCode, operand, memory);
    cout << endl;
  }
}

void displayIntro(){
  cout << "*** " << "Welcome to Simpletron!" << " ***\n\n"
      << "*** " << "Please enter your program one instruction" << " ***\n"
      << "*** " << "(or data word) at a time. I will type the" << " ***\n"
      << "*** " << "location number and a question mark (?). " << " ***\n"
      << "*** " << "You then type the word for that location." << " ***\n"
      << "*** " << "Tyoe the sentinel -99999 to stop entering" << " ***\n"
      << "*** " << "your program." << " ***\n" << endl;
}

void loadInstructions(int *memory, const int memorySize){

  int temp = 0;

  for(int i = 0; i < memorySize; i++){
    cout << setw(2) << setfill('0') << i << " ? ";
    cin >> temp;
    if(temp == -99999)
      break;
    memory[i] = temp;
  }
}

void setOpOff(int &operationCode, int &operand, const int instructionRegister){

  //cout << "Separating word: " << instructionRegister << " into operation code and memory location." << endl;
  operationCode = instructionRegister / 100;
  //cout << "Operation code is " << operationCode << endl;
  operand = instructionRegister % 100;
  //cout << "Memory offset is " << operand << endl << endl;
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
  int temp = *memPtr;

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
      if(temp == 0){
        cout << "FATAL: Divide by Zero.\n";
        return 43;
      }else{
      accumulator /= *memPtr;
      cout << accumulator << endl;
      }
      break;
    case 33: //Multiply
      cout << "Multiply accumulator by " << *memPtr << ": " << accumulator << " * " << *memPtr <<  " = ";
      accumulator *= *memPtr;
      cout << accumulator << endl;
      break;
    default:
      break;
  }

  return code;
}

int branchFunc(const int accumulator, const int  operand, const int instructionCounter, int code){

  if(code == 40){
    return operand;
  }else if((code == 41) && (accumulator < 0)){
    return operand;
  }else if((code == 42) && (accumulator == 0)){
    return operand;
  }else{
    return instructionCounter;
  }
}

void memoryDump(const int &accumulator, const int &instructionCounter, const int &instructionRegister, const int &operationCode, const int &operand, const int *memory){
  //reset previous output flags
  cout << setfill(' ');

  //output registers
  cout << "REGISTERS:\n"
      << setw(21) << left << "accumulator" << right << showpos << setfill('0') << internal << setw(5) << accumulator << "\n"
      << setw(24) << setfill(' ') << left << "instructionCounter" << right << noshowpos << setfill('0') << setw(2) << instructionCounter << endl
      << setw(21) << setfill(' ') << left << "instructionRegister" << showpos << setfill('0') << internal << setw(5) << instructionRegister << endl
      << setw(24) << setfill(' ') << left << "operationCode" << noshowpos << setfill('0') << internal << setw(2) << operationCode << endl
      << setw(24) << setfill(' ') << left << "operand" << setfill('0') << internal << setw(2) << operand << endl
      << setfill(' ') << endl;

  cout << "MEMORY:\n";
  cout << setw(8) << "0";

  for(int i = 1; i < 10; i++){
    cout << setw(6) << i;
  }
  cout << endl;

  for(int i = 0; i < 100; i += 10){
    cout << setw(2) << i << " ";
    for(int j = 0; j < 10; j++){
      cout << showpos << setw(5) << right << setfill('0') << internal << memory[i+j] << " ";
    }
    cout << noshowpos << setfill(' ') << endl;
  }

}
