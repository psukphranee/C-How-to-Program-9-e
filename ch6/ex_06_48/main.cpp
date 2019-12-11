#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

enum class Status {CONTINUE, WIN, LOSE};

Status playCraps();
unsigned int rollDice();
void askWager(double ,double &);

default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randInt(1,6);

int main(){
  Status gameStatus = Status::CONTINUE;
  double playerBalance = 1000;
  double wagerAmt = 0;

  askWager(playerBalance, wagerAmt);

  while(static_cast<int>(wagerAmt) != -1){

    while(wagerAmt > playerBalance){
      cout << "Insufficient funds for wager!\n";
      askWager(playerBalance, wagerAmt);
    }
    gameStatus = playCraps();

    if(gameStatus == Status::WIN){
      cout << "Winner.\n";
      playerBalance += wagerAmt;
      askWager(playerBalance, wagerAmt);
    }else{
      cout << "Lose.\n";
      playerBalance -= wagerAmt;
      askWager(playerBalance, wagerAmt);
    }
  }
}

Status playCraps(){
  unsigned int myPoint = 0;
  unsigned int dieSum = 0;
  Status gameStatus = Status::CONTINUE;

  cout << "Dices coming out!" << endl;
  dieSum = rollDice();

  switch(dieSum){
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
      myPoint = dieSum;
      cout << "Point is on " << myPoint << endl;
      gameStatus = Status::CONTINUE;
      break;
  }

  while(gameStatus == Status::CONTINUE){
    dieSum = rollDice();

    if (dieSum == myPoint){
      gameStatus = Status::WIN;
    }else if(dieSum == 7){
      gameStatus = Status::LOSE;
    }else{
      gameStatus = Status::CONTINUE;
    }
  }

  return gameStatus;
}

unsigned int rollDice(){
  unsigned int dice1 = 0;
  unsigned int dice2 = 0;

  dice1 = randInt(engine);
  dice2 = randInt(engine);

  cout << "Rolled " << dice1 << " + " << dice2 << endl;
  return dice1 + dice2;
}

void askWager(double playerBalance, double &wager){
  double input = 0;

  cout << "Player Balance: $" << playerBalance << endl;
  cout << "Enter wager amount: $";
  cin >> wager; //does this work?
}
