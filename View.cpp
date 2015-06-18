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
        int seed = atoi(argv[1]);
    }

    controller_->initializeDeck(seed);

    invitePlayers();

    beginGameLoop();
}

void View::printPlayer(Player player) {
    model_->tableCards().print();
    player.print();
}

void View::beginGameLoop() {

    beginRound();

    Command command;

    while(!cin.eof()) {

        if (controller_->isActiveHumanPlayer()) {

            printPlayer(*(controller_->activePlayer()));

            input:
            cout << ">";
            cin >> command;

            switch (command.type) {
                case PLAY: {
                    bool result = false;
                    if (controller_->isLegalPlay(command.card)) {
                        controller_->playCard(command.card);
                    } else {
                        cout << "This is not a legal play." << endl;
                        cout << ">";
                    }

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
        }  else {
            cout << "This is a computer" << endl;
            controller_->playComputerTurn();
        }
        controller_->updateLegalPlays();
    }

}

View::~View() {

}

void View::invitePlayers() {
    for(int i = 1; i < 5; ++i) {
        string message = ">Is player ";
        string message_2 = " a human(h) or a computer(c)?";
        string playerType;
        cout << message << i << message_2 << endl;
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

