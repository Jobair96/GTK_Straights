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
    void dealHand(const Deck &, const int); // deals 13 cards from the shuffled deck to each of the 4 players

    virtual void discard(const Card); // discards the specified card from the hand

    void addToScore(const Card); // adds the incoming card rank to the player's score gain from the current round

    std::vector<Card> discards() const; // returns a list of the player's discards
    int score() const; // returns the player's score
    int scoreGain() const; // returns the player's accumulated score for the current round

    void updateScore(); // updates the player's overall game score with the points accumulated from the current round, also clears scoreGain_

    void reset(); // clear's players list of discards and hand

private:
    std::vector<Card> discards_; // A list of all the player's discards
    std::vector<Card> hand_; // A list of all the cards in a player's hand

    int playerNumber_; // The player number - can only be 1, 2, 3, 4
    int score_; // The player's current score, not counting the points accumulated in the current round
    int scoreGain_; //accumulated score for the current round

};

#endif //PROJECT_1_PLAYER_H
