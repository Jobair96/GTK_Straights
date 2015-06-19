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
    std::vector<Card> cards_ = {
        Card(CLUB, ACE),
        Card(CLUB, TWO),
        Card(CLUB, THREE),
        Card(CLUB, FOUR),
        Card(CLUB, FIVE),
        Card(CLUB, SIX),
        Card(CLUB, SEVEN),
        Card(CLUB, EIGHT),
        Card(CLUB, NINE),
        Card(CLUB, TEN),
        Card(CLUB, JACK),
        Card(CLUB, QUEEN),
        Card(CLUB, KING),
        Card(DIAMOND, ACE),
        Card(DIAMOND, TWO),
        Card(DIAMOND, THREE),
        Card(DIAMOND, FOUR),
        Card(DIAMOND, FIVE),
        Card(DIAMOND, SIX),
        Card(DIAMOND, SEVEN),
        Card(DIAMOND, EIGHT),
        Card(DIAMOND, NINE),
        Card(DIAMOND, TEN),
        Card(DIAMOND, JACK),
        Card(DIAMOND, QUEEN),
        Card(DIAMOND, KING),
        Card(HEART, ACE),
        Card(HEART, TWO),
        Card(HEART, THREE),
        Card(HEART, FOUR),
        Card(HEART, FIVE),
        Card(HEART, SIX),
        Card(HEART, SEVEN),
        Card(HEART, EIGHT),
        Card(HEART, NINE),
        Card(HEART, TEN),
        Card(HEART, JACK),
        Card(HEART, QUEEN),
        Card(HEART, KING),
        Card(SPADE, ACE),
        Card(SPADE, TWO),
        Card(SPADE, THREE),
        Card(SPADE, FOUR),
        Card(SPADE, FIVE),
        Card(SPADE, SIX),
        Card(SPADE, SEVEN),
        Card(SPADE, EIGHT),
        Card(SPADE, NINE),
        Card(SPADE, TEN),
        Card(SPADE, JACK),
        Card(SPADE, QUEEN),
        Card(SPADE, KING)
    };
};

#endif //DECK_H
