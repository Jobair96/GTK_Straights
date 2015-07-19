#include <iostream>
#include "View.h"
#include "Controller.h"

using namespace std;

// The constructor initializes the required gui elements properly
View::View(Model *model, Controller *controller) :
        model_(model), controller_(controller),
        gameBox_(), historyPanel_(), mainPanel_(), topPanel_(), playerPanel_(), tableCardsBox_(),
        finalBox_(), finalVertCardBox_(), playerHandBox_(), discardBox_(), historyScrolledWindow_(),
        endCurrentGameButton_("End current game"), startGameWithSeedButton_("Start new game with seed: "),
        player_1_button_("Human"), player_2_button_("Human"), player_3_button_("Human"), player_4_button_("Human"),
        player_1_score_("Score: 0"), player_2_score_("Score: 0"), player_3_score_("Score: 0"), player_4_score_("Score: 0"),
        player_1_discards_("Discards: 0"), player_2_discards_("Discards: 0"), player_3_discards_("Discards: 0"), player_4_discards_("Discards: 0"),
        player_1_frame_("Player 1"), player_2_frame_("Player 2"), player_3_frame_("Player 3"), player_4_frame_("Player 4"),
        playerHandFrame_("Your hand"), discardButton_("Discard"), popupDialog_(""), popupIcon_("img/info_icon.png"),
        historyTitleBox_(), historyTextViewBox_(), historyTitleLabel_("Play History"), historyTextView_(), historyTextBuffer_(historyTextView_.get_buffer())

{

    // Sets some properties of the window
    set_title("Straights UI");
    set_border_width(30);

    // Add the top panel widgets to topPanel_
    topPanel_.add(startGameWithSeedButton_);

    // set default value for seed
    seedField_.set_text("0");

    topPanel_.add(seedField_);
    topPanel_.add(endCurrentGameButton_);

    // Used for initialization of table and hand cards
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();

    // The following is all the code required to initialize the table cards
    for(int i = 0; i < 52; ++i) {
        tableCards_[i] = new Gtk::Image(nullCardPixbuf);
    }

    for(int i = 0; i < 13; ++i) {
        tableClubCards_.add(*tableCards_[i]);
    }

    for(int i = 13; i < 26; ++i) {
        tableDiamondCards_.add(*tableCards_[i]);
    }

    for(int i = 26; i < 39; ++i) {
        tableHeartCards_.add(*tableCards_[i]);
    }

    for(int i = 39; i < 52; ++i) {
        tableSpadeCards_.add(*tableCards_[i]);
    }

    // Add all the suits to the main tableCardsBox to display the entire table
    tableCardsBox_.pack_start(tableClubCards_, true, true, 10);
    tableCardsBox_.pack_start(tableDiamondCards_, true, true, 10);
    tableCardsBox_.pack_start(tableHeartCards_, true, true, 10);
    tableCardsBox_.pack_start(tableSpadeCards_, true, true, 10);


    // Add all the player buttons to the player vbox
    player_1_box_.add(player_1_button_);
    player_2_box_.add(player_2_button_);
    player_3_box_.add(player_3_button_);
    player_4_box_.add(player_4_button_);

    // Add the required player information labels to each box
    player_1_box_.add(player_1_score_);
    player_1_box_.add(player_1_discards_);

    player_2_box_.add(player_2_score_);
    player_2_box_.add(player_2_discards_);


    player_3_box_.add(player_3_score_);
    player_3_box_.add(player_3_discards_);

    player_4_box_.add(player_4_score_);
    player_4_box_.add(player_4_discards_);

    // Add the above boxes to the corresponding frames
    player_1_frame_.add(player_1_box_);
    player_2_frame_.add(player_2_box_);
    player_3_frame_.add(player_3_box_);
    player_4_frame_.add(player_4_box_);

    // Add the above frames to playerPanel_
    playerPanel_.add(player_1_frame_);
    playerPanel_.add(player_2_frame_);
    playerPanel_.add(player_3_frame_);
    playerPanel_.add(player_4_frame_);

    // The following is all the code required to
    // Add all the player hand panel to the player hand horizontal box.

    // Initialize the 13 null card buttons and place them in the box.
    for (int i = 0; i < 13; ++i) {
        playerHand_[i] = new Gtk::Image(nullCardPixbuf);
        playerHandButton_[i].set_image( *playerHand_[i]);
        playerHandButton_[i].set_sensitive(false);
        playerHandBox_.add( playerHandButton_[i] );
    } // for

    // Starts the game turned off as it doesn't do anything
    discardButton_.set_sensitive(false);

    // Add discard button to the bottom box
    discardBox_.add(discardButton_);

    // Add both hand and move boxes into the vertical card box
    finalVertCardBox_.add(playerHandBox_);
    finalVertCardBox_.add(discardBox_);

    // move vertical card box into horizontal card box
    finalBox_.add(finalVertCardBox_);

    // Add the horizontal box for laying out the images to the frame.
    playerHandFrame_.add(finalBox_);

    // Add all the horizontal panels to the main vertical panel
    mainPanel_.add(topPanel_);
    mainPanel_.add(tableCardsBox_);
    mainPanel_.add(playerPanel_);
    mainPanel_.add(playerHandFrame_);

    // Bolds the history title label
    historyTitleLabel_.set_markup("<b>Play History</b>");

    // Configure history textview
    historyTextView_.set_editable(false);
    historyTextView_.set_cursor_visible(false);
    historyTextView_.set_size_request(150);
    historyTextView_.set_wrap_mode(Gtk::WRAP_WORD);

    // Add history textview to scrolled window, set scrolled window horizontal and vertical scroll policies
    historyScrolledWindow_.add(historyTextView_);
    historyScrolledWindow_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);

    // Add the history widgets to their HBoxes
    historyTitleBox_.add(historyTitleLabel_);
    historyTextViewBox_.add(historyScrolledWindow_);

    // Add the history title box and text view box to the history panel
    historyPanel_.pack_start(historyTitleBox_, false, false, 5);
    historyPanel_.pack_start(historyTextViewBox_);

    // Add the main vertical panel and the history panel to the game HBox
    gameBox_.pack_start(mainPanel_, true, true, 10);
    gameBox_.pack_start(historyPanel_, true, true, 10);

    // Add the game box to the window
    add(gameBox_);

    // Associate button "clicked" events with local onButtonClicked() method defined below.
    startGameWithSeedButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::startGameButtonWithSeedButtonClicked));
    endCurrentGameButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::endCurrentGameButtonClicked));

    player_1_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_1_buttonClicked));
    player_2_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_2_buttonClicked));
    player_3_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_3_buttonClicked));
    player_4_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_4_buttonClicked));

    // For all the cards in the player's hand, connect it with the proper playerHandButtonClicked() method
    for(int i = 0; i < 13; ++i) {
        playerHandButton_[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::playerHandButtonClicked), i));
    }

    // Connect the signal for the discard button
    discardButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::discardButtonClicked));

    // Show the first popup dialog for game start
    popupDialog_.set_image(popupIcon_);

    // The final step is to display the buttons (they display themselves)
    show_all();

    // Now we register view as observer of model
    model_->subscribe(this);
} // View::View

// Delete all the images the we allocated in the destructor
View::~View() {
    for(int i = 0; i < 13; ++i) {
        if(nullptr != playerHand_[i]) {
            delete playerHand_[i];
            playerHand_[i] = nullptr;
        }
    }

    for(int i = 0; i < 52; ++i) {
        if(nullptr != tableCards_[i]) {
            delete tableCards_[i];
            tableCards_[i] = nullptr;
        }
    }
}


// Things to update:
// 1) Active player - if player is human, then show hand and wait for input
//    otherwise, let model play computer's turn, then notify again
// 2) Table cards - get relevent table card data from model, and update
//    table cards on gui
// 3) Update the player's points at the end of a round
// 4) Also update every player's discard number
void View::update() {

    // We insert the correct element into the history text
    historyTextBuffer_->insert(historyTextBuffer_->end(), model_->currentPlayMessage());

    // 1) If player is human, then show hand, otherwise do nothing
    if(model_->isActiveHumanPlayer()) {
        vector<Card> hand = model_->activePlayer()->hand();

        // display player's hand
        for (int i = 0; i < hand.size(); ++i) {
            const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getCardImage(hand[i].getRank(), hand[i].getSuit());
            playerHand_[i]->set(cardPixbuf);
        }

        // Now if the player's hand has less than 13 cards, fill the
        // rest of their hand with images of the null card
        for(unsigned long i = hand.size(); i < 13; ++i) {
            const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
            playerHand_[i]->set(nullCardPixbuf);

            // Make sure player cannot click on those
            playerHandButton_[i].set_sensitive(false);
        }

        toggleIllegalPlays();
    }


   // 2) Now get relevent table card data from model
    vector<Card> tableCards = model_->tableCards().tableCards();

    if(tableCards.size() != 0) {
        for (int i = 0; i < tableCards.size(); ++i) {
            Card card = Card(tableCards[i].getSuit(), tableCards[i].getRank());

            Rank rank = tableCards[i].getRank();
            Suit suit = tableCards[i].getSuit();

            const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getCardImage(rank, suit);

            // Get index of this card
            int index = (int) rank + ((int) suit * 13);

            // set the proper image for it on the table
            tableCards_[index]->set(cardPixbuf);
        }
    }

    ostringstream convert;   // stream used for the conversion
    ostringstream scoreStream; // stream used for keeping track of the score

    //Update player discards
    int playerNumber = model_->getPreviousPlayer()->playerNumber();

    convert.str("");

    convert << model_->getPreviousPlayer()->discards().size();
    string discardsAsString = convert.str();

    if(playerNumber == 1) {
        player_1_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 2) {
        player_2_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 3) {
        player_3_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 4) {
        player_4_discards_.set_label("Discards: " + discardsAsString);
    }

    // Check if end of game
    if(model_->isEndOfGame()) {

        for (int i = 1; i < 5; ++i) {

            model_->updateScore(i);
            scoreStream.str("");
            scoreStream << "Score: " << model_->getScore(i);

            if (i == 1) player_1_score_.set_label(scoreStream.str());
            else if (i == 2) player_2_score_.set_label(scoreStream.str());
            else if (i == 3) player_3_score_.set_label(scoreStream.str());
            else player_4_score_.set_label(scoreStream.str());
        }

        vector<int> winners = model_->getWinners();
        convert.str("");

       for (int i = 0; i < winners.size(); ++i) {
            convert << "Player " << winners.at(i) << " wins!" << endl;
        }

        historyTextBuffer_->insert(historyTextBuffer_->end(), "Game over! " + convert.str());
        showPopupDialog("Game Over", convert.str());

        // This is the end of the game, so it is akin to clicking the end game button
        endCurrentGameButtonClicked();

        return;

    } else if(model_->allHandsEmpty()) {
        convert.str("");
        cout << "End of round" << endl;

        for (int i = 1; i < 5; ++i) {
            convert << "Player " << i << "'s discards:";
            vector<Card> discards = model_->getDiscards(i);
            if (discards.size() > 0) convert << " ";
            for (int j = 0; j < discards.size(); ++j) {
                convert << discards.at(j);

                if (j < discards.size() - 1) {
                    convert << " ";
                }
            }
            convert << endl;
            convert << "Player " << i << "'s score: " << model_->getScore(i) << " + " << model_->getScoreGain(i);
            model_->updateScore(i);
            convert << " = " << model_->getScore(i) << endl;

            scoreStream.str("");
            scoreStream << "Score: " << model_->getScore(i);

            if (i == 1) player_1_score_.set_label(scoreStream.str());
            else if (i == 2) player_2_score_.set_label(scoreStream.str());
            else if (i == 3) player_3_score_.set_label(scoreStream.str());
            else player_4_score_.set_label(scoreStream.str());
        }

        showPopupDialog("Round End", convert.str());

        model_->shuffleDeckWithPersistedSeed();

        beginRound();
    }

    setActivePlayerOptions();

}

void View::beginRound() {
    controller_->clearTable();
    controller_->resetPlay();
    resetCardsInPlayView();

    int playerNumber = controller_->getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    controller_->setFirstPlayer(playerNumber);

    ostringstream convert;

    convert.str("");
    convert << "A new round begins. It's player " << playerNumber << "'s turn to play." << endl;

    historyTextBuffer_->insert(historyTextBuffer_->end(), "\n" + convert.str());

    showPopupDialog("New Round", convert.str());
}

// When starting a new game, there are several things we must do.
// Firstly, we gather the type of every player, then send that to the controller
// to properly initialize each player. Afterwards,
void View::startGameButtonWithSeedButtonClicked() {
    int seed = getCurrentSeedAsInt();

    if (player_1_button_.get_label() != "Rage!") {
        // When starting a new game, we check the type of players, then
        // send that information to the controller to initialize all the
        // new players.
        string player_1_type = player_1_button_.get_label();
        string player_2_type = player_2_button_.get_label();
        string player_3_type = player_3_button_.get_label();
        string player_4_type = player_4_button_.get_label();

        controller_->startNewGameWithSeedButtonClicked(seed, player_1_type, player_2_type, player_3_type,
                                                       player_4_type);

        // Set the button labels to rage
        player_1_button_.set_label("Rage!");
        player_2_button_.set_label("Rage!");
        player_3_button_.set_label("Rage!");
        player_4_button_.set_label("Rage!");

        setActivePlayerOptions();
    } else {
        resetCardsInPlayView();
        controller_->restartGameWithSeedButtonClicked(seed);
    }

    int playerNumber = controller_->getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    ostringstream convert;

    convert.str("");
    convert << "A new game begins. It's player " << playerNumber << "'s turn to play." << endl;

    historyTextBuffer_->erase(historyTextBuffer_->begin(), historyTextBuffer_->end());

    historyTextBuffer_->insert(historyTextBuffer_->end(), convert.str());

    showPopupDialog("New Game", convert.str());

    while (!model_->isActiveHumanPlayer()) {
        if (!model_->isEndOfGame()) {
            if (model_->hasLegalPlay()) {
                controller_->completeComputerPlayCard();
            } else {
                controller_->completeComputerDiscard();
            }
        } else {
            endCurrentGameButtonClicked();
            break;
        }
    }

    // reset the discard button
    discardButton_.set_sensitive(false);

    if(model_->isActiveHumanPlayer() && !model_->isEndOfGame()) {
        toggleIllegalPlays();
    }
}

void View::endCurrentGameButtonClicked() {
    controller_->endCurrentGameButtonClicked();

    // Reset required gui elements properly
    player_1_button_.set_label("Human");
    player_2_button_.set_label("Human");
    player_3_button_.set_label("Human");
    player_4_button_.set_label("Human");

    player_1_button_.set_sensitive(true);
    player_2_button_.set_sensitive(true);
    player_3_button_.set_sensitive(true);
    player_4_button_.set_sensitive(true);

    player_1_score_.set_label("Score: 0");
    player_1_discards_.set_label("Discards: 0");
    player_2_score_.set_label("Score: 0");
    player_2_discards_.set_label("Discards: 0");
    player_3_score_.set_label("Score: 0");
    player_3_discards_.set_label("Discards: 0");
    player_4_score_.set_label("Score: 0");
    player_4_discards_.set_label("Discards: 0");

    // fill the deck and hand with null card images
    resetCardsInPlayView();

    // reset the discard button
    discardButton_.set_sensitive(false);
}

void View::player_1_buttonClicked() {
    if(player_1_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked();
    } else if(player_1_button_.get_label() == "Human") {
        player_1_button_.set_label("Computer");
    } else if(player_1_button_.get_label() == "Computer") {
        player_1_button_.set_label("Human");
    }
}

void View::player_2_buttonClicked() {
    if(player_2_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked();
    } else if(player_2_button_.get_label() == "Human") {
        player_2_button_.set_label("Computer");
    } else if(player_2_button_.get_label() == "Computer") {
        player_2_button_.set_label("Human");
    }
}

void View::player_3_buttonClicked() {
    if(player_3_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked();
    } else if(player_3_button_.get_label() == "Human") {
        player_3_button_.set_label("Computer");
    } else if(player_3_button_.get_label() == "Computer") {
        player_3_button_.set_label("Human");
    }
}

void View::player_4_buttonClicked() {
    if(player_4_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked();
    } else if(player_4_button_.get_label() == "Human") {
        player_4_button_.set_label("Computer");
    } else if(player_4_button_.get_label() == "Computer") {
        player_4_button_.set_label("Human");
    }
}

// Send the card clicked to the controller
void View::playerHandButtonClicked(int indexOfCardChosen) {
    controller_->playerHandButtonClicked(indexOfCardChosen);
}

// If the discard button is active, it means
// that the player must discard. Thus, we
// allow the player now to pick a card to discard
void View::discardButtonClicked() {
    discardButton_.set_sensitive(false);

    for(int i = 0; i < controller_->getActiveHand().size(); ++i) {
        playerHandButton_[i].set_sensitive(true);
    }
}

void View::toggleIllegalPlays() {
    // turn off discard button by default
    discardButton_.set_sensitive(false);

    vector<Card> hand = model_->activePlayer()->hand();

    // Reset toggle sensitivity
    for(int i = 0; i < 13; ++i) {
        playerHandButton_[i].set_sensitive(false);
    }

    // If the active player doesn't have a legal play and it is
    // a human player, then
    // turn off the discard button. Otherwise, turn it on,
    // and enable the appropriate cards.
    if(!model_->hasLegalPlay() && model_->isActiveHumanPlayer()) {
        discardButton_.set_sensitive(true);
    } else {
        for (int i = 0; i < hand.size(); ++i) {
            if (controller_->isLegalPlay(hand.at(i))) {
                playerHandButton_[i].set_sensitive(true);
            }
        }
    }
}

void View::setActivePlayerOptions() {

    player_1_button_.set_sensitive(false);
    player_2_button_.set_sensitive(false);
    player_3_button_.set_sensitive(false);
    player_4_button_.set_sensitive(false);

    int activePlayerNumber = model_->activePlayer()->playerNumber();

    if(activePlayerNumber == 1) {
        player_1_button_.set_sensitive(true);
    }

    if(activePlayerNumber == 2) {
        player_2_button_.set_sensitive(true);
    }

    if(activePlayerNumber == 3) {
        player_3_button_.set_sensitive(true);
    }

    if(activePlayerNumber == 4) {
        player_4_button_.set_sensitive(true);
    }
}

// The following is to convert the seed value in the
// text field into an integer
int View::getCurrentSeedAsInt() const {
    string seedString = seedField_.get_text();
    int seed;
    std::istringstream(seedString) >> seed;
    return seed;
}

// The follwing is to reset all the cards on the table and the player's hand
// to the null card image. This is called when a new game starts
// and whenever we need to clear the table and player's hand in general
void View::resetCardsInPlayView() {
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();

    for(int i = 0; i < 52; ++i) {
        tableCards_[i]->set(nullCardPixbuf);
    }

    for (int i = 0; i < 13; ++i) {
        playerHandButton_[i].set_sensitive(false);
        playerHand_[i]->set(nullCardPixbuf);
    }
}

// This brings up the view's popup dialog with the specified title
// and text
void View::showPopupDialog(string title, string text) {
    popupDialog_.set_title(title);
    popupDialog_.set_secondary_text(text, false);

    popupDialog_.show_all();
    popupDialog_.run();
    popupDialog_.hide();
}