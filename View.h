#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"

class View {

public:
    View(int, const char **, Model *, Controller *); // constructor
    ~View(); // destructor

    void invitePlayers(); // function to add players to a game
    void beginRound(); // initializes a new round

    void printPlayer() const; // prints a player information
    void printTableCards() const; // prints a tables information
    void printWinner() const; // prints a winning line

    void runGame(const int); // runs the game logic

    void refreshGame(int); // refreshes the game state for a new round

private:
    Model *model_; // model
    Controller *controller_; // controller
};

#endif //VIEW_H
