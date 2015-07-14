/*
 * Model class. It is responsible for keeping track of the players (their discards, their hands,
 * their score) and the cards on the table. It also manages the deck of cards (shuffling). It has no
 * knowledge about views or controllers.
 */

#ifndef MODEL_H
#define MODEL_H

#include "Subject.h"

#include "Deck.h"
#include "Human.h"
#include "Player.h"
#include "Computer.h"
#include "TableCards.h"



class Model : public Subject {

public:
    Model(); // constructor
    ~Model(); // destructor

    Deck deck() const; // returns the shuffled deck
    TableCards tableCards() const; // returns the list of cards on the table

    void setPlayer(const std::string, const int); // creates a player based on player type (c or h) and player number
    void shuffleDeck(const int); // shuffles the deck using the specified seed
    void setActivePlayer(const int); // sets the active player to the specified player number
    void setLegalPlay(const Card); // adds a specified card to the list of legal plays

    void updateLegalPlays(Card card); // updates the list of legal plays based on which card was just played

    void updateActivePlayer(); // sets the next player as active

    void addCardToTable(const Card); // places a card from a player's hand to the table

    Player* getPlayerWithCard(const Card) const; // returns a player who holds a card
    Player* activePlayer() const; // returns the active player
    int getActivePlayerNumber() const; // returns the active player's player number
    Card getFirstLegalPlay() const; // returns the first legal play in a computer's hand
    std::vector<Card> getDiscards(int) const; // returns the list of discards based on player number
    int getScore(int) const; // returns the game score based on player number
    int getScoreGain(int) const; // returns the round score based on player number
    std::vector<int> getWinners() const; // finds the winner of the game

    bool allHandsEmpty() const; // checks if every player has no cards left
    bool hasLegalPlay() const; // checks if a player has legal plays available

    bool isLegal(const Card) const; // checks if a card is a legal play
    bool isActiveHumanPlayer() const; // checks if the active player is human
    bool isEndOfGame() const; // checks if the game is ending (score > 80)

    void updateScore(int); // adds a player's round score to their game score and resets round score

    void clearTable(); // clears the table's cards
    void resetPlayers(); // resets the player's hand and discards
    void resetLegalPlays(); // resets the list of legal plays

    void replaceCurrentHumanWithComputer(); // passes a ragequitting player's hands, discards, and score to a new computer

private:
    Deck deck_; // shuffled deck of cards
    TableCards tableCards_; // entity containing list of cards on the table
    std::vector<Card> legalPlays_; // list of legal plays

    Player *player_1_; // pointer to player 1
    Player *player_2_; // pointer to player 2
    Player *player_3_; // pointer to player 3
    Player *player_4_; // pointer to player 4

    Player *activePlayer_; // pointer to active player

    std::string playerTypes_[4]; // array of player types in player order

    Player *getPlayer(int) const; // returns player point by player number
};


#endif //MODEL_H
