#include "View.h"
#include "Command.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Controller.h"

using namespace std;

View::View(Model *model, Controller *controller) : model_(model), controller_(controller), mainPanel_(true, 5), topPanel_(true, 5), playerPanel_(true, 5), endCurrentGameButton_("End current game"),
tableCardsBox_(true, 5), startNewGameButtonWithSeedButton_("Start new game with seed: "), player_1_button_("Human"),
 player_2_button_("Human"), player_3_button_("Human"), player_4_button_("Human"), cardBox_(true, 20) {

    // Sets some properties of the window
    set_title("Straights UI");
    set_border_width(20);

    // Add the top panel widgets to topPanel_
    topPanel_.add(startNewGameButtonWithSeedButton_);
    topPanel_.add(seedField_);
    topPanel_.add(endCurrentGameButton_);

    // Used for initializtion of table and hand cards
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();

    // The following is all the code required to initialize the table cards
    for(int i = 0; i < 52; ++i) {
        tableCards_[i] = new Gtk::Image( nullCardPixbuf );
    }

    for(int i = 0; i < 13; ++i) {
        tableClubCards_.add(*tableCards_[i]);
    }

    for(int i = 13; i < 26; ++i) {
        tableDaimondCards_.add(*tableCards_[i]);
    }

    for(int i = 26; i < 39; ++i) {
        tableHeartCards_.add(*tableCards_[i]);
    }

    for(int i = 39; i < 52; ++i) {
        tableSpadeCards_.add(*tableCards_[i]);
    }


    tableCardsBox_.add(tableClubCards_);
    tableCardsBox_.add(tableDaimondCards_);
    tableCardsBox_.add(tableHeartCards_);
    tableCardsBox_.add(tableSpadeCards_);

    // Add the player panel widgets to playerPanel_
    playerPanel_.add(player_1_button_);
    playerPanel_.add(player_2_button_);
    playerPanel_.add(player_3_button_);
    playerPanel_.add(player_4_button_);

    // The following is all the code required to
    // Add all the player hand panel to the player hand horizontal box.

    // Set the look of the frame.
    cardFrame_.set_label( "Your hand:" );
    cardFrame_.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
    cardFrame_.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );

    // Initialize the 13 null card buttons and place them in the box.
    for (int i = 0; i < 13; ++i) {
        card_[i] = new Gtk::Image( nullCardPixbuf );
        button_[i].set_image( *card_[i]);
        cardBox_.add( button_[i] );
    } // for

    // Add the horizontal box for laying out the images to the frame.
    cardFrame_.add(cardBox_);

    // Add all the horizontal panels to the main vertical panel
    mainPanel_.add(topPanel_);
    mainPanel_.add(tableCardsBox_);
    mainPanel_.add(playerPanel_);
    mainPanel_.add(cardFrame_);

    // Add the main vertical panel to the window
    add(mainPanel_);

    // Associate button "clicked" events with local onButtonClicked() method defined below.
    startNewGameButtonWithSeedButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::startNewGameButtonWithSeedButtonClicked));
    endCurrentGameButton_.signal_clicked().connect(sigc::mem_fun(*this, &View::endCurrentGameButtonClicked));

    // The final step is to display the buttons (they display themselves)
    show_all();

    int seed = 0;

    //runGame(seed);

    // Register view as observer of model

} // View::View

View::~View() {
    for(int i = 0; i < 13; ++i) {
        delete card_[i];
    }

    for(int i = 0; i < 52; ++i) {
        delete tableCards_[i];
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

void View::runGame(int seed) {

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
}

void View::invitePlayers() {
    for(int i = 1; i < 5; ++i) {
        string message = "Is player ";
        string message_2 = " a human(h) or a computer(c)?";
        string playerType;
        cout << message << i << message_2 << endl;
        cout << ">";
        cin >> playerType;
        playerType = playerType.substr(0,1);
        assert(playerType == "c" || playerType == "h");
        controller_->initializePlayer(playerType.substr(0,1), i);
    }
}

void View::beginRound() {
    string message = "A new round begins. It's player ";
    int playerNumber = controller_->getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    cout << message << playerNumber << "'s turn to play." << endl;
    controller_->setFirstPlayer(playerNumber);
}

void View::refreshGame(int seed) {
    controller_->clearTable();
    controller_->initializeDeck(seed);
    controller_->resetPlay();
}

void View::update() {

}

void View::startNewGameButtonWithSeedButtonClicked() {
    cout << "start new game button was clicked!" << endl;
}

void View::endCurrentGameButtonClicked() {
    cout << "end current game button was clicked!" << endl;
}
