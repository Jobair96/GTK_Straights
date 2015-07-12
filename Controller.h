#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller {

public:
    Controller(Model *); // constructor
    ~Controller(); // destructor

    void startNewGameButtonWithSeedButtonClicked(const int);
    void endCurrentGameButtonClicked();
    void playerTypeButtonClicked(const int);


















   // Starting here is our old code

    void initializePlayer(const std::string, const int); // creates a player using the incoming player type (c or h) and player number
    void initializeDeck(const int); // helper method to call shuffle function

    void setActivePlayer(const int); // sets the active player based on player number, mainly used for assigning active player to the player with the spade
    void setFirstPlayer(const int); // sets the first player as the player with the seven of spades

    Player* activePlayer() const; // returns the active player pointer
    std::vector<Card> getActiveHand() const; // returns the hand of the active player
    std::vector<Card> getDiscards(int) const; // gets a player's discards by player number
    int getScore(int) const; // gets a player's score by player number
    int getScoreGain(int) const; // gets a player's round score by player number
    std::vector<int> getWinners() const; // gets the game winner

    bool isActiveHumanPlayer() const; // checks if the active player is human
    bool isLegalPlay(const Card) const; // checks if the card being played is legal
    bool isEndOfGame() const; // checks if the game should be ended (score > 80)
    bool isEndOfRound() const; // checks if the round should end (no player has cards)

    void playCard(const Card); // puts the card into play on the table

    void updateScore(int); // updates the score of the specified player by number

    void completeComputerPlayCard(); // completes the computer turn if they play a card
    void completeComputerDiscard(); // completes the computer turn if they discard a card

    void discard(const Card); // the active player discards the specified card

    int getPlayerWithSevenSpade(const Card) const; // returns the player with seven of spades

    void clearTable(); // clears the table cards
    void resetPlay(); // resets the players' hands and discards, as well as the legal plays

    void rageQuit(); // changes human player to computer player and completes their turn

private:
    Model *model_; // the collection of business and utility logic

}; // Controller


#endif //CONTROLLER_H
