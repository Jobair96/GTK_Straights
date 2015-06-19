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

    void setActivePlayer(const int);
    void setFirstPlayer(const int);

    Player* activePlayer() const;
    std::vector<Card> getActiveHand() const;
    std::vector<Card> getDiscards(int) const;
    int getScore(int) const;
    int getScoreGain(int) const;
    std::vector<int> getWinners() const;

    bool isActiveHumanPlayer() const;
    bool isLegalPlay(const Card) const;
    bool isEndOfGame() const;
    bool isEndOfRound() const;

    void playCard(const Card);

    void updateScore(int);

    void completeComputerPlayCard();
    void completeComputerDiscard();

    void discard(const Card);

    int getPlayerWithSevenSpade(const Card) const;

    void clearTable();
    void resetPlay();

    void rageQuit();

private:
    Model *model_;

};


#endif //CONTROLLER_H
