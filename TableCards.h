#ifndef TABLECARDS_H
#define TABLECARDS_H

#include "Deck.h"

/* This represents the cards that have been played, i.e the ones face up on the table
 * This is NOT the discard pile for each player
 * */
class TableCards {

public:
    TableCards(); // Constructor
    ~TableCards(); // Destructor

    std::vector<Card> tableCards() const; // returns tableCards_

    void addCard(const Card); // Adds a card to the list of table cards i.e when a player a plays a card, it will be added.
    void clearTable(); //Removes all the cards on the table to restart a new round.

private:
    std::vector<Card> tableCards_;
};


#endif //PROJECT_1_TABLECARDS_H
