#include "Deck.h"
#include <random>
#include <iostream>

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

void Deck::print() const {
    cout << cards_[0] << " ";

    for(int i = 1; i <= 11; ++i) {
        cout << cards_[i] << " ";
    }

    cout << cards_[12] << endl;

    for(int i = 13; i <= 24; ++i) {
        cout << cards_[i] << " ";
    }

    cout << cards_[25] << endl;

    for(int i = 26; i <= 37; ++i) {
        cout << cards_[i] << " ";
    }

    cout << cards_[38] << endl;

    for(int i = 39; i <= 50; ++i) {
        cout << cards_[i] << " ";
    }

    cout << cards_[51] << endl;
}

vector<Card> Deck::cards() const {
    return cards_;
}
