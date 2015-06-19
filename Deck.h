#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

/* This class represents the deck of cards for the game */

class Deck {

public:
    Deck(); // Constructor
    ~Deck(); // Destructor

    void shuffle(const int); // Shuffles the deck using the seed parameter passed in
    void print() const; // prints the contents of the deck

    std::vector<Card> cards() const; // returns cards_

private:
    static const int CARD_COUNT = 52; // The number of cards in the deck

    // The list of cards in the deck
    std::vector<Card> cards_;
};

#endif //DECK_H
