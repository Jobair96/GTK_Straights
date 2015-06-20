#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {

public:
    Human(const Deck &, const int); // Constructor - calls parent constructor

};


#endif // HUMAN_H
