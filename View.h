/*
 * View class. Is responsible for buttons (that user clicks) and for handling everything related to the gui,
 * as dictated by the MVC design pattern
 */

#ifndef VIEW_H
#define VIEW_H

#include <gtkmm.h>
#include <gtkmm/label.h>
#include "Observer.h"
#include "DeckGUI.h"

class Controller;
class Model;

class View : public Gtk::Window, public Observer {

public:
    View(Model *, Controller *); // constructor
    ~View(); // destructor

    virtual void update(); // Observer Pattern: concrete update() method

private:
    // Observer Pattern: to access Model accessors without having to downcast object
    Model *model_; // model

    // Strategy Pattern  member (plus signal handlers)
    Controller *controller_; // controller

    // Card Images
    DeckGUI deck;

    // Main window will be divided into two vertical panels; the main panel and the history panel
    Gtk::HBox gameBox_;

    // The main panel will be divided into four horizontal panels that will be
    // stacked on top of each other
    Gtk::VBox mainPanel_;

    // The history panel will contain the history textview
    Gtk::VBox historyPanel_;

    // The four Horizontal panels are below:

    // This contains the startNewGameButtonWithSeedButton, the text entry for the seed, and finally
    // the endCurrentGameButton
    Gtk::HBox topPanel_;

    // Member widgets for top panel
    Gtk::Button endCurrentGameButton_;
    Gtk::Entry seedField_; // This is the text area for the seed value to be entered
    Gtk::Button startGameWithSeedButton_;

    // This horizontal panel contains the options for the four players
    Gtk::HBox playerPanel_;

    // Member widgets for the playerPanel

    // We will display all the buttons in a frame
    // where we can also display the player's score and discards
    Gtk::Frame player_1_frame_;
    Gtk::Frame player_2_frame_;
    Gtk::Frame player_3_frame_;
    Gtk::Frame player_4_frame_;

    // These are buttons for each of the players. They will be added to the above frames
    Gtk::Button player_1_button_;
    Gtk::Button player_2_button_;
    Gtk::Button player_3_button_;
    Gtk::Button player_4_button_;

    // The following are labels for displaying player scores. They will also be added to the above frames
    Gtk::Label player_1_score_;
    Gtk::Label player_1_discards_;

    Gtk::Label player_2_score_;
    Gtk::Label player_2_discards_;

    Gtk::Label player_3_score_;
    Gtk::Label player_3_discards_;

    Gtk::Label player_4_score_;
    Gtk::Label player_4_discards_;

    // Finally, all the above widgets will be added to VBoxes to stack them vertically on top of each other
    Gtk::VBox player_1_box_;
    Gtk::VBox player_2_box_;
    Gtk::VBox player_3_box_;
    Gtk::VBox player_4_box_;

    // That's all for the player panel

    // Now, we have the horizontal panel to display the cards that have been played
    // on the table. This itself is a vertical panel that has four horizontal panels inside
    // of it. There are four horizontal panels because there are four suits. Each horizontal panel
    // holds 13 cards as there are 13 cards in a suit, and four of these panels make up all
    // the cards we can have on the table in total.
    Gtk::VBox tableCardsBox_;

    Gtk::HBox tableDiamondCards_;
    Gtk::HBox tableHeartCards_;
    Gtk::HBox tableClubCards_;
    Gtk::HBox tableSpadeCards_;

    // These are the images for all 52 cards that are on the
    // table. Initially, all these images are empty
    Gtk::Image * tableCards_[52];


    // This horizontal panel shows the player's hands and the discard button.
    // Therefore, it will be subdivided into two more horizontal panels
    Gtk::HBox finalBox_;

    // The last horizontal panel needs to be further divided into two horizontal
    // panels contained within the same frame

    // This one contains the cards in the player's hand
    Gtk::HBox playerHandBox_;

    // The following is for stacking the playerhand box and the discard button box
    Gtk::VBox finalVertCardBox_;

    // The following is to hold the discard button
    Gtk::HBox discardBox_;

    // Member widgets for the player hand panel (which is the last panel)
    Gtk::Image *playerHand_[13]; // Images to display
    Gtk::Button playerHandButton_[13]; // Buttons for each card in the hand
    Gtk::Frame playerHandFrame_; // Create a nice framed border for the box

    Gtk::Button discardButton_; // Button to turn on the ability to discard

    // That is it for the main four horizontal panels

    // The following is the popup dialog we use for the entire game
    // It gets loaded with different messages depending on the situation
    /******************************Dialog********************************************/
    Gtk::MessageDialog popupDialog_; //Dialog for round end
    Gtk::Image popupIcon_; //Dialog popup icon
    /**************************End Dialog********************************************/

    // The following are the widgets for the history of plays
    /****************************History********************************************/
    Gtk::ScrolledWindow historyScrolledWindow_; //Scrolled Window which allows for scrolling
    Gtk::HBox historyTitleBox_; // HBox containing title label
    Gtk::HBox historyTextViewBox_; // Hbox containing textview + scrolled window
    Gtk::Label historyTitleLabel_; // title label
    Gtk::TextView historyTextView_; //TextView displaying each player's play
    Glib::RefPtr<Gtk::TextBuffer> historyTextBuffer_; //text buffer for historyView
    /**************************End History******************************************/

    // Signal handlers
    void startGameButtonWithSeedButtonClicked();
    void endCurrentGameButtonClicked();

    void player_1_buttonClicked();
    void player_2_buttonClicked();
    void player_3_buttonClicked();
    void player_4_buttonClicked();

    void playerHandButtonClicked(int);

    void discardButtonClicked();

    // end signal handlers

    /************************Helper Functions************************/
    int getCurrentSeedAsInt() const;
    void resetCardsInPlayView();

    void toggleIllegalPlays(); // Makes sure the illegal plays on the player's hands cannot be clicked
    void setActivePlayerOptions(); // Sets the player options depending on which player is active and their type (Computer/Human)

    void showPopupDialog(std::string, std::string); //changes text and title values of popup dialog and runs it

    void beginRound(); // initializes a new round
}; // View

#endif //VIEW_H
