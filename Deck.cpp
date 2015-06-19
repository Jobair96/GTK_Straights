#include "Deck.h"
#include <random>
#include <iostream>

using namespace std;

Deck::Deck() {

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
