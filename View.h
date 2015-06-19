//
// Created by jobair_hassan on 15/06/15.
//

#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"

class View {

public:
    View(int, const char **, Model *, Controller *);
    ~View();

    void invitePlayers();
    void beginRound();

    void printPlayer() const;
    void printTableCards() const;
    void printWinner() const;

    void runGame(const int);

    void refreshGame(int);

private:
    Model *model_;
    Controller *controller_;
};

#endif //VIEW_H
