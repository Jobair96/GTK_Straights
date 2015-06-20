#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {

public:
    Computer(const Deck &, const int); // Constructor - calls the parent constructor
};

#endif //COMPUTER_H
