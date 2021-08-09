#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

//dice rolling function prototype
unsigned int rollDice();
//global counter for number of times the dice was rolled
unsigned int rollCount = 0;
//global declaration of enumeration
enum class Status {WIN, LOSE, CONTINUE};
Status gameStatus = Status::CONTINUE;
//random engine
default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randInt(1,6);

int main()
{
  //Variables
  vector<int> winCount = {};
  vector<int> loseCount = {};
  array<int, 20> win_rolls = {};
  array<int, 20> lose_rolls = {};
  unsigned int myPoint = 0;
  unsigned int sumOfDice = 0;

  //play game 1000 times
  for(unsigned int i = 1; i <= 1000; ++i){
    //come out roll
    sumOfDice = rollDice();
    switch (sumOfDice) {
      case 7:
      case 11:
        gameStatus = Status::WIN;
        break;
      case 2:
      case 3:
      case 12:
        gameStatus = Status::LOSE;
        break;
      default:
        gameStatus = Status::CONTINUE;
        myPoint = sumOfDice;
        break;
    }
    //keep rolling until win or lose
    while(gameStatus == Status::CONTINUE){
      sumOfDice = rollDice();
      if(sumOfDice == myPoint)
        gameStatus = Status::WIN;
      else if(sumOfDice == 7)
        gameStatus = Status::LOSE;
      else
        gameStatus = Status::CONTINUE;
    }

    //the game has ended, take data of the game
    if(gameStatus == Status::WIN){
      winCount.push_back(rollCount);
    }else{
      loseCount.push_back(rollCount);
    }
    //reset roll counter
    rollCount = 0;
  }

  //display stats
  //average game length
  double avgGameLen = 0;
  for(int wins: winCount)
    avgGameLen += wins;
  for(int losses: loseCount)
    avgGameLen += losses;
  avgGameLen /= 1000;

  //count winning rolls
  for(int &rolls: winCount)
    if(rolls <= 20)
      ++win_rolls[rolls - 1];

  //count losing rolls
  for(int &rolls: loseCount)
    if(rolls <= 20)
      ++lose_rolls[rolls - 1];

  //display data
  cout << "Average game length is " << avgGameLen << " rolls.\n";

  cout << "Rolls" << setw(5) << "Won" << setw(5) << "Loss" << endl;
  for(unsigned int i = 0; i < 20; i++){
    cout << setw(5) << i+1 << setw(5) << win_rolls[i] << setw(5) << lose_rolls[i] << endl;
  }
}


unsigned int rollDice()
{
  unsigned int dice1 = randInt(engine);
  unsigned int dice2 = randInt(engine);

  ++rollCount;

  return dice1 + dice2;
}
