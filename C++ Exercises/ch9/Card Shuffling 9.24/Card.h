#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>

class Card{
public:
  Card(int = 0, int = 0);
  std::string toString() const;
  int getFace() const;
  int getSuit() const;
private:
  static std::array<std::string, 13> faces;
  static std::array<std::string, 4> suits;

  int face;
  int suit;
};

#endif
