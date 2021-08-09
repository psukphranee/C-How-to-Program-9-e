#include "Card.h"
using namespace std;

array<string, 13> Card::faces{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
array<string, 4> Card::suits{"Hearts", "Clubs", "Diamonds", "Spades"};

Card::Card(int f, int s)
  : face(f), suit(s)
{

}

string Card::toString() const{
  return faces[face] + " of " + suits[suit];
}
