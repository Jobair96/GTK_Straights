//
// Created by jobair_hassan on 15/06/15.
//

#include "Deck.h"
#include <random>
#include <iostream>

using namespace std;

Deck::Deck() {
}

Deck::~Deck() {

}

void Deck::shuffle(int seed) {
    static mt19937 rng(seed);

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

Card Deck::getCard(const Card card) const {
    for(int i = 0; i < CARD_COUNT; ++i) {
        if(cards_[i].getRank() == card.getRank() && cards_[i].getSuit() == card.getSuit()) {
            return cards_[i];
        }
    }
}

vector<Card> Deck::cards() const {
    return cards_;
}
