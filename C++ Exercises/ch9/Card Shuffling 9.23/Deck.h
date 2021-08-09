#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
public:
  Deck();
  bool moreCards() const;
  void shuffle();
  Card &dealCard();
private:
  std::array<Card, 52> deck;
  int currentCard;
};

#endif
