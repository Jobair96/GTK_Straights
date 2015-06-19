//
// Created by jobair_hassan on 15/06/15.
//

#include "View.h"
#include "Command.h"
#include <iostream>
#include <cstdlib>

using namespace std;

View::View(int argc, const char** argv, Model *model, Controller *controller) : model_(model), controller_(controller) {

    int seed = 0;

    if(argc >= 2) {
        seed = atoi(argv[1]);
    }

    controller_->initializeDeck(seed);

    invitePlayers();

    roundStart:
    beginGameLoop();

    if (!controller_->isEndOfGame()) {
        refreshGame();
        goto roundStart;
    }
}

View::~View() {

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

void View::beginGameLoop() {

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
                        cout << ">";
                    }

                    break;
                }

                case DISCARD: {
                    if(!model_->hasLegalPlay()) {
                        cout << "Player " << model_->activePlayer()->playerNumber() << " discards " << command.card << "." << endl;
                        controller_->discard(command.card);
                    } else {
                        cout << "You have a legal play. You may not discard." << endl;
                    }
                    break;
                }

                case RAGEQUIT: {
                    controller_->rageQuit();
                    cout << "Player " << model_->activePlayer()->playerNumber() << " ragequits. A computer will now take over." << endl;
                    goto label;
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

        } else {
            label:

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
        cout << "Player " << i << "'s discards: ";
        vector<Card> discards = controller_->getDiscards(i);
        for (int j = 0; j < discards.size(); ++j) {
            cout << discards.at(j);

            if (j < discards.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
        cout << "player " << i << "'s score: " << controller_->getScore(i) << " + " << controller_->getScoreGain(i);
        controller_->updateScore(i);
        cout << " = " << controller_->getScore(i) << endl;
    }

}

void View::invitePlayers() {
    for(int i = 1; i < 5; ++i) {
        string message = "Is player ";
        string message_2 = " a human(h) or a computer(c)?";
        string playerType;
        cout << message << i << message_2 << endl;
        cout << ">";
        cin >> playerType;
        controller_->initializePlayer(playerType, i);
    }
}

void View::beginRound() {
    string message = "A new round begins. It's player ";
    int playerNumber = controller_->getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    cout << message << playerNumber << "'s turn to play." << endl;
    controller_->setFirstPlayer(playerNumber);
}

void View::refreshGame() {

}
