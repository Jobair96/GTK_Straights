//
// Created by jobair_hassan on 16/06/15.
//

#include "Player.h"
#include <algorithm>

using namespace std;

Player::Player(const Deck &deck, const int playerNumber) : playerNumber_(playerNumber) {
    for(int i = (playerNumber - 1) * 13; i < (playerNumber) * 13; ++i) {
        hand_.push_back(deck.cards()[i]);
    }
}

int Player::playerNumber() const {
    return playerNumber_;
}

bool Player::findCard(const Card card) const {
    for(int i = 0; i < hand_.size(); ++i) {
        Card current = hand_.at(i);
        if(current == card) {
            return true;
        }
    }

    return false;
}

void Player::removeCard(const Card card) {
    for( vector<Card>::iterator iter = hand_.begin(); iter != hand_.end(); ++iter ) {
        if( *iter == card )
        {
            hand_.erase( iter );
            break;
        }
    }
}

vector<Card> Player::hand() const {
    return hand_;
}
