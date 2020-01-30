#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int rollDice();

int main()
{

    unsigned int myPoint{0};
    unsigned int sumOfFaces = 0;
    enum Status{ CONTINUE, LOSE, WIN};
    Status gameStatus = CONTINUE;

    srand(static_cast<unsigned int>(time(0)));
    sumOfFaces = rollDice();

    switch (sumOfFaces) {
        case 7:
        case 11:
            gameStatus = WIN;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOSE;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfFaces;
            cout << "Point is " << myPoint << endl;
            break;
    }

    while(gameStatus == CONTINUE)
    {
        sumOfFaces = rollDice();

        if(sumOfFaces == myPoint){
            gameStatus = WIN;
        }else if(sumOfFaces == 7){
            gameStatus = LOSE;
        }else{
            gameStatus = CONTINUE;
        }
    }

    if(gameStatus == WIN){
        cout << "Player wins" << endl;
    }else{
        cout << "Player loses" << endl;
    }
}

unsigned int rollDice()
{
    unsigned int die1 = 1 + rand() % 6;
    unsigned int die2 = 1 + rand() % 6;

    unsigned int sum = die1 + die2;

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

    return sum;
}
