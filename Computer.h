//
// Created by jobair_hassan on 15/06/15.
//

#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {

public:
    Computer(const Deck &, const int);
};
#endif //COMPUTER_H
