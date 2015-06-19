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

void View::printPlayer() {
    model_->tableCards().print();

    vector<Card> hand = controller_->getActiveHand();

    cout << "Your hands: ";

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
            cout << hand.at(i);
            if (i != hand.size() - 1) {
                cout << " ";
            }
        }
    }

    cout << endl;
}

void View::beginGameLoop() {

    beginRound();

    Command command;

    while(!controller_->isEndOfRound() && !cin.eof()) {

        if (controller_->isActiveHumanPlayer()) {

            printPlayer();

            input:
            cout << ">";
            cin >> command;

            switch (command.type) {
                case PLAY: {
                    if (controller_->isLegalPlay(command.card)) {
                        controller_->playCard(command.card);
                    } else {
                        cout << "This is not a legal play." << endl;
                        cout << ">";
                    }

                    break;
                }

                case DISCARD: {
                    controller_->discard(command.card);
                    break;
                }

                case RAGEQUIT: {
                    controller_->rageQuit();
                    goto input;
                }

                case DECK: {
                    model_->deck().print();
                    break;
                }

                case QUIT: {
                    return;
                }

                default: {
                    cerr << "Invalid Command" << endl;
                }
            }

        } else {
            cout << "This is a computer" << endl;
            controller_->completeComputerTurn();
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