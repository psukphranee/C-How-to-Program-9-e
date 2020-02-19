#include "Deck.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

Deck::Deck()
  :currentCard(0)
{
  int counter = 0; //index of current card to be intialized

  for(int i = 0; i < 4; ++i){
    for(int j = 0; j < 13; ++j){
      deck[counter++] = Card(j, i);
    }
  }
}

Card &Deck::dealCard(){
  return deck[currentCard++];
}

bool Deck::moreCards() const{
  return (currentCard < 52) ? 1 : 0;
}

void Deck::shuffle(){
  default_random_engine engine(static_cast<unsigned int>(time(0)));
  uniform_int_distribution<unsigned int> randInt(0,51);

  Card temp;

  for(int i = 0; i < 52; ++i){
    int k = randInt(engine);
    temp = deck[i];
    deck[i] = deck[k];
    deck[k] = deck[i];
  }
}
