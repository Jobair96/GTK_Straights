//
// Created by jobair_hassan on 16/06/15.
//

#ifndef MODEL_H
#define MODEL_H

#include "Deck.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "TableCards.h"


class Model {

public:
    Model();
    ~Model();

    Deck deck() const;
    TableCards tableCards() const;

    void setPlayer(const std::string, const int);
    void shuffleDeck(const int);
    void setActivePlayer(const int);

    void updateAllLegalPlays();

    void updateActivePlayer();

    void addCardToTable(const Card);

    Player* getPlayerWithCard(const Card) const;
    Player* activePlayer() const;

    void replaceCurrentHumanWithComputer();

private:
    Deck deck_;
    TableCards tableCards_;

    Player *player_1_;
    Player *player_2_;
    Player *player_3_;
    Player *player_4_;

    Player *activePlayer_;

};


#endif //MODEL_H
