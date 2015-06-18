//
// Created by jobair_hassan on 15/06/15.
//

#include "Computer.h"

using namespace std;

Computer::Computer(const Deck &deck, const int playerNumber) : Player(deck, playerNumber) {

}

Card Computer::removeCardFromHand(const Card card) {
    vector<Card>::iterator iter = hand_.begin();
    hand_.erase(iter);
}

void Computer::discard(const Card card) {
    discards_.push_back(card);
}


