#include "View.h"
#include "Command.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Controller.h"

using namespace std;

View::View(Model *model, Controller *controller) : model_(model), controller_(controller), mainPanel_(), topPanel_(), playerPanel_(), endCurrentGameButton_("End current game"),
tableCardsBox_(), startNewGameButtonWithSeedButton_("Start new game with seed: "), player_1_button_("Human"),
 player_2_button_("Human"), player_3_button_("Human"), player_4_button_("Human"), cardBox_(),
player_1_score_("Score: 0"), player_2_score_("Score: 0"),player_3_score_("Score: 0"), player_4_score_("Score: 0"),
player_1_discards_("Discards: 0"), player_2_discards_("Discards: 0"), player_3_discards_("Discards: 0"),player_4_discards_("Discards: 0"),
player_1_frame_("Player 1"), player_2_frame_("Player 2"), player_3_frame_("Player 3"), player_4_frame_("Player 4"),
playerHandFrame_("Your hand"), roundEndDialog_("Round End", true), roundEndSummary_(""), roundEndOKButton_("OK")

{

    // Sets some properties of the window
    set_title("Straights UI");
    set_border_width(20);


    // Add the top panel widgets to topPanel_
    topPanel_.add(startNewGameButtonWithSeedButton_);

    // set default value for seed
    seedField_.set_text("0");

    topPanel_.add(seedField_);
    topPanel_.add(endCurrentGameButton_);

    // Used for initializtion of table and hand cards
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

    // Add the player panel widgets to playerPanel_
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
        cardBox_.add( playerHandButton_[i] );
    } // for

    // Add the horizontal box for laying out the images to the frame.
    playerHandFrame_.add(cardBox_);

    // Add all the horizontal panels to the main vertical panel
    mainPanel_.add(topPanel_);
    mainPanel_.add(tableCardsBox_);
    mainPanel_.add(playerPanel_);
    mainPanel_.add(playerHandFrame_);

    // Add the main vertical panel to the window
    add(mainPanel_);

    // Associate button "clicked" events with local onButtonClicked() method defined below.
    startNewGameButtonWithSeedButton_.signal_clicked().connect(
            sigc::mem_fun(*this, &View::startGameButtonWithSeedButtonClicked));
    endCurrentGameButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::endCurrentGameButtonClicked));

    player_1_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_1_buttonClicked));
    player_2_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_2_buttonClicked));
    player_3_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_3_buttonClicked));
    player_4_button_.signal_clicked().connect(sigc::mem_fun(*this, &View::player_4_buttonClicked));

    // For all the cards in the player's hand, connect it to a signal
    for(int i = 0; i < 13; ++i) {
        playerHandButton_[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::playerHandButtonClicked), i));

    }

    roundEndDialog_.get_vbox()->add(roundEndSummary_);
    roundEndDialog_.get_vbox()->add(roundEndOKButton_);

    // The final step is to display the buttons (they display themselves)
    show_all();

    // Now we register view as observer of model
    model_->subscribe(this);

    //runGame(seed);

} // View::View

View::~View() {
    for(int i = 0; i < 13; ++i) {
        if(!playerHand_[i]) {
            delete playerHand_[i];
            playerHand_[i] = nullptr;
        }
    }

    for(int i = 0; i < 52; ++i) {
        if(!tableCards_[i]) {
            delete tableCards_[i];
            tableCards_[i] = nullptr;
        }
    }
}

void View::printPlayer() const {
    vector<Card> hand = controller_->getActiveHand();

    cout << "Your hand: ";

    for(int i = 0; i < hand.size(); ++i) {
        cout << hand.at(i);
        if(i != hand.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    cout << "Legal plays:";
    for(int i = 0; i < hand.size(); ++i) {
        if (controller_->isLegalPlay(hand.at(i))) {
            cout << " ";
            cout << hand.at(i);
        }
    }

    cout << endl;
}

void View::printTableCards() const {

    cout << "Cards on the table:" << endl;

    cout << "Clubs:";

    vector<Card> tableCards = model_->tableCards().tableCards();

    vector<Card> temp;

    // Clubs
    for(int i = 0; i < tableCards.size(); ++i) {
        if(tableCards[i].getSuit() == CLUB) {
            cout << " ";
            cout << Card::ranks[tableCards[i].getRank()];
        }
    }

    cout << endl;

    cout << "Diamonds:";

    // Diamonds
    for(int i = 0; i < tableCards.size(); ++i) {
        if(tableCards[i].getSuit() == DIAMOND) {
            cout << " ";
            cout << Card::ranks[tableCards[i].getRank()];
        }
    }

    cout << endl;

    cout << "Hearts:";

    // Hearts
    for(int i = 0; i < tableCards.size(); ++i) {
        if(tableCards[i].getSuit() == HEART) {
            cout << " ";
            cout << Card::ranks[tableCards[i].getRank()];
        }
    }

    cout << endl;

    cout << "Spades:";

    // Spades
    for(int i = 0; i < tableCards.size(); ++i) {
        if(tableCards[i].getSuit() == SPADE) {
            cout << " ";
            cout << Card::ranks[tableCards[i].getRank()];
        }
    }

    cout << endl;
}

void View::printWinner() const {
    vector<int> winners = controller_->getWinners();

    for (int i = 0; i < winners.size(); ++i) {
        cout << "Player " << winners.at(i) << " wins!" << endl;
    }
}

void View::update() {
    // Things to update:
    // 1) Active player - if player is human, then show hand and wait for input
    //    otherwise, let model play computer's turn, then notify again
    // 2) Table cards - get relevent table card data from model, and update
    //    table cards on gui
    // 3) Also Update every player's points
    // 4) Also update every player's discard number

    // The following is for if the current player is a computer


    // 1) If player is human, then show hand, otherwise do nothing
    if(model_->isActiveHumanPlayer()) {
        vector<Card> hand = model_->activePlayer()->hand();

        for (int i = 0; i < hand.size(); ++i) {
            const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getCardImage(hand[i].getRank(), hand[i].getSuit());

            playerHand_[i]->set(cardPixbuf);

        }

        for(int i = hand.size(); i < 13; ++i) {
            const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
            playerHand_[i]->set(nullCardPixbuf);
        }
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

            tableCards_[index]->set(cardPixbuf);
        }
    }

    ostringstream convert;   // stream used for the conversion

    // Check if end of round
    if(controller_->isEndOfRound()) {
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
        }

        roundEndSummary_.set_text(convert.str());

        roundEndDialog_.show_all();
        roundEndDialog_.run();

        cout << "Round has ended" << endl;

    }

    if(controller_->isEndOfGame()) {
        // Show dialog box showing end of game
        Gtk::Dialog endOfRoundDialog("Game has ended.", true);
    }

    //Update player scores and discards
    int playerNumber = model_->activePlayer()->playerNumber();
    int scoreAsInt = model_->getScore(model_->activePlayer()->playerNumber());
    int discardsAsInt = model_->activePlayer()->discards().size();

    string scoreAsString;          // string which will contain the result
    string discardsAsString;

    convert.str("");

    convert << scoreAsInt;      // insert the textual representation of 'Number' in the characters in the stream
    scoreAsString = convert.str();

    convert.str("");

    convert << discardsAsInt;
    discardsAsString = convert.str();

    convert.str("");


    if(playerNumber == 1) {
        player_1_score_.set_label("Score: " + scoreAsString);
        player_1_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 2) {
        player_2_score_.set_label("Score: " + scoreAsString);
        player_2_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 3) {
        player_3_score_.set_label("Score: " + scoreAsString);
        player_3_discards_.set_label("Discards: " + discardsAsString);
    } else if(playerNumber == 4) {
        player_4_score_.set_label("Score: " + scoreAsString);
        player_4_discards_.set_label("Discards: " + discardsAsString);
    }

    setActivePlayerOptions();

    View::toggleIllegalPlays();


}

/* void View::runGame(int seed) {

    controller_->initializeDeck(seed);

    invitePlayers();

    roundStart:
    beginRound();

    Command command;

    while(!controller_->isEndOfRound() && !cin.eof()) {

        if (controller_->isActiveHumanPlayer()) {

            printTableCards();
            printPlayer();

            input:
            cout << ">";
            cin >> command;

            switch (command.type) {
                case PLAY: {
                    if (controller_->isLegalPlay(command.card)) {
                        cout << "Player " << controller_->activePlayer()->playerNumber() << " plays " << command.card << "." << endl;
                        controller_->playCard(command.card);
                    } else {
                        cout << "This is not a legal play." << endl;
                        goto input;
                    }

                    break;
                }

                case DISCARD: {
                    if(!model_->hasLegalPlay()) {
                        cout << "Player " << model_->activePlayer()->playerNumber() << " discards " << command.card << "." << endl;
                        controller_->discard(command.card);
                    } else {
                        cout << "You have a legal play. You may not discard." << endl;
                        goto input;
                    }
                    break;
                }

                case RAGEQUIT: {
                    controller_->rageQuit();
                    cout << "Player " << model_->activePlayer()->playerNumber() << " ragequits. A computer will now take over." << endl;
                    break;
                }

                case DECK: {
                    model_->deck().print();
                    goto input;
                }

                case QUIT: {
                    return;
                }

                default: {

                }
            }
        }

        if (!controller_->isActiveHumanPlayer()){
            if(model_->hasLegalPlay()) {
                cout << "Player " << model_->activePlayer()->playerNumber() << " plays " << model_->getFirstLegalPlay() << "." << endl;
                controller_->completeComputerPlayCard();
            } else {
                cout << "Player " << model_->activePlayer()->playerNumber() << " discards " << model_->activePlayer()->hand().at(0) << "." << endl;
                controller_->completeComputerDiscard();
            }
        }
    }

    for (int i = 1; i < 5; ++i) {
        cout << "Player " << i << "'s discards:";
        vector<Card> discards = controller_->getDiscards(i);
        if (discards.size() > 0) cout << " ";
        for (int j = 0; j < discards.size(); ++j) {
            cout << discards.at(j);

            if (j < discards.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
        cout << "Player " << i << "'s score: " << controller_->getScore(i) << " + " << controller_->getScoreGain(i);
        controller_->updateScore(i);
        cout << " = " << controller_->getScore(i) << endl;
    }

    if (!controller_->isEndOfGame()) {
        refreshGame(seed);
        goto roundStart;
    }

    printWinner();
}*/

void View::beginRound() {
    string message = "A new round begins. It's player ";
    int playerNumber = controller_->getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    cout << message << playerNumber << "'s turn to play." << endl;
    controller_->setFirstPlayer(playerNumber);
}

void View::refreshGame(int seed) {
    controller_->clearTable();
    //controller_->initializeDeck(seed);
    controller_->resetPlay();
}

// When starting a new game, there are several things we must do.
// Firstly, we gather the type of every player, then send that to the controller
// to properly initialize each player. Afterwards,
void View::startGameButtonWithSeedButtonClicked() {
    int seed = getCurrentSeed();

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
        resetCardsInPlay();
        controller_->restartGameWithSeedButtonClicked(seed);
    }
}

void View::endCurrentGameButtonClicked() {
    controller_->endCurrentGameButtonClicked();

    player_1_button_.set_label("Human");
    player_2_button_.set_label("Human");
    player_3_button_.set_label("Human");
    player_4_button_.set_label("Human");

    player_1_button_.set_sensitive(true);
    player_2_button_.set_sensitive(true);
    player_3_button_.set_sensitive(true);
    player_4_button_.set_sensitive(true);

    resetCardsInPlay();
}

void View::player_1_buttonClicked() {
    if(player_1_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked(1);
    } else if(player_1_button_.get_label() == "Human") {
        player_1_button_.set_label("Computer");
    } else if(player_1_button_.get_label() == "Computer") {
        player_1_button_.set_label("Human");
    }
}

void View::player_2_buttonClicked() {
    if(player_2_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked(2);
    } else if(player_2_button_.get_label() == "Human") {
        player_2_button_.set_label("Computer");
    } else if(player_2_button_.get_label() == "Computer") {
        player_2_button_.set_label("Human");
    }
}

void View::player_3_buttonClicked() {
    if(player_3_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked(3);
    } else if(player_3_button_.get_label() == "Human") {
        player_3_button_.set_label("Computer");
    } else if(player_3_button_.get_label() == "Computer") {
        player_3_button_.set_label("Human");
    }
}

void View::player_4_buttonClicked() {
    if(player_4_button_.get_label() == "Rage!") {
        controller_->playerRageButtonClicked(4);
    } else if(player_4_button_.get_label() == "Human") {
        player_4_button_.set_label("Computer");
    } else if(player_4_button_.get_label() == "Computer") {
        player_4_button_.set_label("Human");
    }
}

void View::playerHandButtonClicked(int indexOfCardChosen) {
    controller_->playerHandButtonClicked(indexOfCardChosen);
}

void View::toggleIllegalPlays() {
    vector<Card> hand = model_->activePlayer()->hand();

    // Reset toggle sensitivity
    for(int i = 0; i < 13; ++i) {
        playerHandButton_[i].set_sensitive(false);
    }

    if(!model_->hasLegalPlay()) {
        for(int i = 0; i < hand.size(); ++i) {
            playerHandButton_[i].set_sensitive(true);
        }
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

int View::getCurrentSeed() const {
    // The following is to convert the seed value in the
    // text field into an integer
    string seedString = seedField_.get_text();
    int seed;
    std::istringstream(seedString) >> seed;
    return seed;
}

void View::resetCardsInPlay() {
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();

    for(int i = 0; i < 52; ++i) {
        tableCards_[i]->set(nullCardPixbuf);
    }

    for (int i = 0; i < 13; ++i) {
        playerHand_[i]->set(nullCardPixbuf);
        playerHandButton_[i].set_sensitive(false);
    }
}