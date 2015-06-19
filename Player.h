//
// Created by jobair_hassan on 14/06/15.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Deck.h"
#include "TableCards.h"
#include <string>

class Player {

public:
    Player(const Deck &, const int);
    virtual ~Player();

    int playerNumber() const;

    bool findCard(const Card card) const;

    void dealHand(const Deck &, const int);

    void removeCard(const Card);

    virtual Card removeCardFromHand(const Card);

    void addToScore(const Card);

    std::vector<Card> hand() const;
    std::vector<Card> discards() const;
    virtual void discard(const Card);
    int score() const;
    int scoreGain() const;

    void updateScore();

protected:
    std::vector<Card> discards_;
    std::vector<Card> hand_;
    int score_;
    int scoreGain_;
    int playerNumber_;

};

#endif //PROJECT_1_PLAYER_H
