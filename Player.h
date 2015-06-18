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
    Player();
    Player(const Deck &, const int);

    int playerNumber() const;

    bool findCard(const Card card) const;

    void print() const;

    void updateLegalPlays(const TableCards &);

private:
    std::vector<Card> hand_;
    std::vector<Card> legalPlays_;
    int playerNumber_;

};

#endif //PROJECT_1_PLAYER_H
