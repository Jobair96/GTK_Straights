#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "TableCards.h"

class Player {

public:
    Player(const Deck &, const int); // Constructor
    virtual ~Player(); // Destructor

    int playerNumber() const; // Getter - returns playerNumber_
    std::vector<Card> hand() const; // Getter - returns hand_

    bool findCard(const Card) const; // Returns a boolean indicating if the card is in the player's hands

    void removeCard(const Card); // removes the specified card from the player's hand

    virtual void discard(const Card); // discards the specified card from the hand

protected:
    std::vector<Card> discards_; // A list of all the player's discards
    std::vector<Card> hand_; // A list of all the cards in a player's hand

    int playerNumber_; // The player number - can only be 1, 2, 3, 4

};

#endif //PROJECT_1_PLAYER_H
