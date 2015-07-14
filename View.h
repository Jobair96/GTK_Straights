/*
 * View class. Is responsible for buttons (that user clicks) and for displaying the rest of the gui elements.
 */

#ifndef VIEW_H
#define VIEW_H

#include <gtkmm.h>
#include "Observer.h"
#include "DeckGUI.h"

class Controller;
class Model;

class View : public Gtk::Window, public Observer {

public:
    View(Model *, Controller *); // constructor
    ~View(); // destructor

    virtual void update(); // Observer Pattern: concrete update() method


    /* Old code here */

    void beginRound(); // initializes a new round

    void printPlayer() const; // prints a player information
    void printTableCards() const; // prints a tables information
    void printWinner() const; // prints a winning line

    void runGame(const int); // runs the game logic

    void refreshGame(int); // refreshes the game state for a new round

    /* Old code ends */

private:
    // Observer Pattern: to access Model accessors without having to downcast object
    Model *model_; // model

    // Strategy Pattern  member (plus signal handlers)
    Controller *controller_; // controller

    // Card Images
    DeckGUI deck;

    // Main window will be divided into four horizontal panels that will be
    // stacked on top of each other in a vertical panel
    Gtk::VBox mainPanel_;

    // The four Horizontal panels are below:

    // This contains the startNewGameButtonWithSeedButton, the text entry for the seed, and finally
    // the endCurrentGameButton
    Gtk::HBox topPanel_;

    // Member widgets for top panel
    Gtk::Button endCurrentGameButton_;
    Gtk::Entry seedField_; // This is the text area for the seed value to be entered
    Gtk::Button startNewGameButtonWithSeedButton_;

    // This horizontal panel contains the options for the four players
    Gtk::HBox playerPanel_;

    // Member widgets for the playerPanel
    Gtk::Button player_1_button_;
    Gtk::Button player_2_button_;
    Gtk::Button player_3_button_;
    Gtk::Button player_4_button_;

    // Now, we have the horizontal panel to display the cards that have been played
    // on the table. This itself is a vertical panel that has four horizontal panel inside
    // of it. There are four horizontal panels because there are four suits. Each panel
    // has an array of 52 cards as there are 52 cards in total.
    Gtk::VBox tableCardsBox_;

    Gtk::HBox tableDaimondCards_;
    Gtk::HBox tableHeartCards_;
    Gtk::HBox tableClubCards_;
    Gtk::HBox tableSpadeCards_;

    Gtk::Frame tableDaimondCardsFrame_;
    Gtk::Frame tableClubCardsFrame_;
    Gtk::Frame tableSpadeCardsFrame_;
    Gtk::Frame tableHeartCardsFrame_;

    Gtk::Image * tableCards_[52];


    // This horizontal panel is the final panel to be included as
    // the final panel in the main vertical box panel. It aligns the widgets
    // which are the current cards in the players hands
    Gtk::HBox cardBox_;

    // Member widgets for the player hand panel (which is the last panel)
    Gtk::Image * card_[13]; // Images to display
    Gtk::Button button_[13]; // Buttons for each card in the hand
    Gtk::Frame cardFrame_; // Create a niced framed border for the box

    // Signal handlers
    void endCurrentGameButtonClicked();
    void startNewGameButtonWithSeedButtonClicked();
    void player_1_buttonClicked();
    void player_2_buttonClicked();
    void player_3_buttonClicked();
    void player_4_buttonClicked();

}; // View

#endif //VIEW_H
