//
// Created by jobair_hassan on 15/06/15.
//

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {

public:
    Deck();
    ~Deck();

    void shuffle(const int);
    void print() const;

    Card getCard(const Card) const;

    std::vector<Card> cards() const;

private:
    static const int CARD_COUNT = 52;

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
