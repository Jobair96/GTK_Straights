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

    void removeCard(const Card);
    void print() const;

    bool checkCard(const Card) const;

    void updateLegalPlays(const TableCards &);

    void setLegalPlay(const Card);

    virtual Card removeCardFromHand(const Card);

    std::vector<Card> hand() const;
    virtual void discard(const Card);
    std::vector<Card> legalPlays() const;

protected:
    std::vector<Card> discards_;
    std::vector<Card> hand_;
    std::vector<Card> legalPlays_;
    int playerNumber_;

};

#endif //PROJECT_1_PLAYER_H
