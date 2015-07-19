#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller {

public:
    Controller(Model *); // constructor
    ~Controller(); // destructor

    void startNewGameWithSeedButtonClicked(const int, std::string, std::string, std::string, std::string); //performs the necessary model commands for start button being pushed
    void restartGameWithSeedButtonClicked(const int); //performs the necessary model commands for pressing start in the middle of a game
    void endCurrentGameButtonClicked(); //performs the necessary model commands for pressing end game prematurely
    void playerRageButtonClicked(); //performs the necessary model commands for pressing rage quit
    void playerHandButtonClicked(const int); //performs the necessary model commands for pressing a hand card button





   // Starting here is our old code


    void setActivePlayer(const int); // sets the active player based on player number, mainly used for assigning active player to the player with the spade
    void setFirstPlayer(const int); // sets the first player as the player with the seven of spades

    Player* activePlayer() const; // returns the active player pointer
    std::vector<Card> getActiveHand() const; // returns the hand of the active player

    bool isLegalPlay(const Card) const; // checks if the card being played is legal

    void playCard(const Card); // puts the card into play on the table

    void completeComputerPlayCard(); // completes the computer turn if they play a card
    void completeComputerDiscard(); // completes the computer turn if they discard a card
    void completeComputerTurns(); // automatically runs through the computer turns until game over

    void discard(const Card); // the active player discards the specified card

    int getPlayerWithSevenSpade() const; // returns the player with seven of spades

    void clearTable(); // clears the table cards
    void resetPlay(); // resets the players' hands and discards, as well as the legal plays

private:
    Model *model_; // the collection of business and utility logic

}; // Controller


#endif //CONTROLLER_H
