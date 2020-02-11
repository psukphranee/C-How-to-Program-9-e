#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main()
{
  /*Create a Deck of Cards, shuffle, then deal them.*/
  Deck testDeck;
  testDeck.shuffle();
  for(int i = 0; i < 52; ++i){
    cout << testDeck.dealCard().toString() << endl;
  }
}
