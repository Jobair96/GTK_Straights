//
// Created by jobair_hassan on 16/06/15.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller {

public:
    Controller(Model *);
    ~Controller();

    void initializePlayer(const std::string, const int);
    void initializeDeck(const int);

    void updateLegalPlays();

    void setActivePlayer(const int);
    void setFirstPlayer(const int);

    Player* activePlayer() const;

    bool isActiveHumanPlayer() const;
    bool isLegalPlay(const Card) const;

    void playCard(const Card);
    void playComputerTurn();

    int getPlayerWithSevenSpade(const Card) const;

    void rageQuit();

private:
    Model *model_;

};


#endif //CONTROLLER_H
