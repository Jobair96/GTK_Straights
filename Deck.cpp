#include "Deck.h"
#include <random>

using namespace std;

Deck::Deck() {
    cards_ = {
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
}

Deck::~Deck() {

}

void Deck::shuffle(int seed) {
    static mt19937 rng((long)seed);

    int n = CARD_COUNT;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
}

vector<Card> Deck::cards() const {
    return cards_;
}
