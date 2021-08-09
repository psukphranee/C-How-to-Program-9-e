#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <array>
#include <iomanip>

using namespace std;

bool onePair(array<Card, 5> &currHand);
bool twoPair(array<Card, 5> &currHand);
bool threeKind(array<Card, 5> &currHand);
bool fourKind(array<Card, 5> &currHand);
bool isStraight(array<Card, 5> &currHand);
bool isFlush(array<Card, 5> &currHand);

void displayHand(const array<Card, 5> &);

array<string, 13> global_faces{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
array<string, 4> global_suits{"Hearts", "Clubs", "Diamonds", "Spades"};

int main()
{
  /*Create a Deck of Cards, shuffle, then deal a five card hand.
  Determine whether the hand contains: a pair, two pairs, three of a kind, four of a kind, flush, straight.
  */

  //Hand to deal to
  array<Card, 5> hand;

  Deck newDeck;
  newDeck.shuffle();

  //cout << "Cards shuffled." << endl;
  /*
  while(newDeck.moreCards()){
    cout << newDeck.dealCard().toString() << endl;
  } */
  /*
  for(int i = 0; i < 52; ++i){
    cout << newDeck.dealCard().toString() << endl;
  }
  */
  newDeck.resetCurrentCard();

  //cout << "Dealing hands..." << endl;
  for(int i = 0; i < 5; ++i){
    hand[i] = newDeck.dealCard();
  }


  //cout << "\nDisplaying Hand:" << endl;

  for(int i = 0; i < 5; ++i){
    cout << hand[i].toString() << endl;
  }
  cout << endl;

  //Test hand
  //array<Card, 5> hand = {Card(1,1), Card(2,1), Card(3,1), Card(4,1), Card(5, 1)};
  displayHand(hand);
  cout << (onePair(hand) ? "One Pair" : "") << endl;
  cout << (twoPair(hand) ? "Two Pair" : "") << endl;
  cout << (threeKind(hand) ?  "Three of a Kind" : "") << endl;
  cout << (fourKind(hand) ? "Four of a Kind " : "") << endl;
  cout << (isFlush(hand) ? "Flush" : "") << endl;
  cout << (isStraight(hand) ? "Straight" : "") << endl;
}

bool onePair(array<Card, 5> &currHand){
  //create an array mapping face values to indices, e.g. lowest face "Two" = 0, highest face "Ace" = 12
  array<int, 13> face_mapping{0};
  int pair_counter = 0;
  //loop through currHand and increment corresponding face_mapping element

  for(int i = 0; i < currHand.size(); ++i){
    ++face_mapping[currHand[i].getFace()];
    //cout << "Incrementing index " << currHand[i].getFace() << " of face_mapping" << endl;
  }
  /*
  cout << "[ ";
  for(int i = 0; i < face_mapping.size(); ++i){
    cout << face_mapping[i] << ", ";
  }
  cout << " ]" << endl;
  */
  //Loop through face_mapping and output values = 2
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] == 2){
      //cout << "Index " << i << " is a pair" << endl;
      //cout << "Pair of " << global_faces[i] << endl;
      ++pair_counter;
    }
  }
  //cout << "Number of pairs: " << pair_counter << endl;

  return (pair_counter == 1);
}

bool twoPair(array<Card, 5> &currHand){
  //create an array mapping face values to indices, e.g. lowest face "Two" = 0, highest face "Ace" = 12
  array<int, 13> face_mapping{0};
  int pair_counter = 0;
  //loop through currHand and increment corresponding face_mapping element

  for(int i = 0; i < currHand.size(); ++i){
    ++face_mapping[currHand[i].getFace()];
  }

  //Loop through face_mapping and output values = 2
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] == 2){
      //cout << "Index " << i << " is a pair" << endl;
      //cout << "Pair of " << global_faces[i] << endl;
      ++pair_counter;
    }
  }

  return (pair_counter == 2);
}

bool threeKind(array<Card, 5> &currHand){
  //create an array mapping face values to indices, e.g. lowest face "Two" = 0, highest face "Ace" = 12
  array<int, 13> face_mapping{0};
  int three_counter = 0;
  //loop through currHand and increment corresponding face_mapping element

  for(int i = 0; i < currHand.size(); ++i){
    ++face_mapping[currHand[i].getFace()];
  }

  //Loop through face_mapping and output values = 3
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] == 3){
      //cout << "Index " << i << " is a pair" << endl;
      //cout << "Three of " << global_faces[i] << endl;
      return true;
    }
  }

  return false;
}

bool fourKind(array<Card, 5> &currHand){
  //create an array mapping face values to indices, e.g. lowest face "Two" = 0, highest face "Ace" = 12
  array<int, 13> face_mapping{0};
  int four_counter = 0;
  //loop through currHand and increment corresponding face_mapping element

  for(int i = 0; i < currHand.size(); ++i){
    ++face_mapping[currHand[i].getFace()];
  }

  //Loop through face_mapping and output values = 4
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] == 4){
      cout << "Four of " << global_faces[i] << endl;
      return true;
    }
  }

  return false;
}

bool isStraight(array<Card, 5> &currHand){
  array<int, 13> face_mapping{0}; //counter to keep track number of each faces in hand
  int face_counter = 0;
  //loop through currHand and increment corresponding face_mapping element
  for(int i = 0; i < currHand.size(); ++i){
    ++face_mapping[currHand[i].getFace()];
    //cout << "Incrementing index: " << currHand[i].getFace() << endl;
  }

  //check that there is one of each face in the hand
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] > 1){
      return false;
    }
  }

  //get the index of the lowest face. sum up this index's face_mapping value + the next 4. If the sum is 5 then we have a Flush
  for(int i = 0; i < face_mapping.size(); ++i){
    if(face_mapping[i] == 1){
      int sum = 0;
      for(int j = i; j < i + 5; ++j){
        sum += face_mapping[j];
      }
      if(sum == 5){
        return true;
      }else{
        return false;
      }
    }
  }
}

bool isFlush(array<Card, 5> &currHand){
  array<int, 4> suit_mapping{0}; //counter to keep track number of each faces in hand
  int suit_counter = 0;
  //loop through currHand and increment corresponding face_mapping element
  for(int i = 0; i < currHand.size(); ++i){
    ++suit_mapping[currHand[i].getSuit()];
    //cout << "Incrementing index: " << currHand[i].getFace() << endl;
  }

  for(int i = 0; i < suit_mapping.size(); ++i){
    if(suit_mapping[i] == 5){
      return true;
    }
  }

  return false;
}

void displayHand(const array<Card, 5> &currHand){
  for(int i = 0; i < currHand.size(); ++i){
    cout << setw(7) << global_faces[currHand[i].getFace()] << " of " << setw(8) << global_suits[currHand[i].getSuit()] << endl;
  }
}
