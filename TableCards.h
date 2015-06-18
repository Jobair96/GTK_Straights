//
// Created by jobair_hassan on 17/06/15.
//

#ifndef TABLECARDS_H
#define TABLECARDS_H

#include "Deck.h"

class TableCards {

public:
    TableCards();
    ~TableCards();

    std::vector<Card> tableCards() const;

    void addCard(const Card);

    void print();

private:
    std::vector<Card> tableCards_;
};


#endif //PROJECT_1_TABLECARDS_H
