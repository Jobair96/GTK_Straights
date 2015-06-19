//
// Created by jobair_hassan on 16/06/15.
//

#include "Player.h"
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player(const Deck &deck, const int playerNumber) : playerNumber_(playerNumber) {
    score_ = 0;
    scoreGain_ = 0;
    dealHand(deck, playerNumber);
}

Player::~Player() {

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

void Player::dealHand(const Deck &deck, const int playerNumber) {
    for(int i = (playerNumber - 1) * 13; i < (playerNumber) * 13; ++i) {
        hand_.push_back(deck.cards()[i]);
    }
}

void Player::removeCard(const Card card) {
    for( vector<Card>::iterator iter = hand_.begin(); iter != hand_.end(); ++iter ) {
        if( *iter == card ) {
            hand_.erase( iter );
            break;
        }
    }
}

void Player::addToScore(const Card card) {
    scoreGain_ += card.getRank() + 1;
}

vector<Card> Player::discards() const {
    return discards_;
}

void Player::discard(const Card card) {
    discards_.push_back(card);
    addToScore(card);
}

vector<Card> Player::hand() const {
    return hand_;
}

int Player::score() const {
    return score_;
}

int Player::scoreGain() const {
    return scoreGain_;
}

Card Player::removeCardFromHand(const Card card) {
    return Card(SPADE, FOUR);
}

void Player::updateScore() {
    score_ += scoreGain_;
    scoreGain_ = 0;
}