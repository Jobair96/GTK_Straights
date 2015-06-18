//
// Created by jobair_hassan on 15/06/15.
//

#include "View.h"
#include "Command.h"
#include <iostream>

using namespace std;

View::View(int argc, const char** argv, Model &model, Controller &controller) : model_(model), controller_(controller) {

    int seed = 0;

    if(argc >= 2) {
        int seed = atoi(argv[1]);
    }

    controller_.initializeDeck(seed);

    invitePlayers();

    beginGameLoop();
}

void View::printPlayer(Player player) {
    model_.tableCards().print();
    player.print();
}

void View::beginGameLoop() {

    beginRound();

    Command command;

    while(!cin.eof()) {
        controller_.updateLegalPlays();
        printPlayer(controller_.activePlayer());

        cout << ">";
        cin >> command;

        switch(command.type) {
            case DECK: {
                model_.deck().print();
            }

            case QUIT: {
                return;
            }

            default: {
                cerr << "Invalid Command" << endl;
            }
        }
    }
}

View::~View() {

}

void View::invitePlayers() {
    for(int i = 1; i < 5; ++i) {
        string message = ">Is player ";
        message += (i + 1) + " a human(h) or a computer(c)?";
        string playerType;
        cout << message << endl;
        cin >> playerType;
        controller_.initializePlayer(playerType, i);
    }
}

void View::beginRound() {
    string message = "A new round begins. It's player ";
    int playerNumber = controller_.getPlayerWithSevenSpade(Card(SPADE, SEVEN));
    cout << message << playerNumber << "'s turn to play." << endl;
    controller_.setActivePlayer(playerNumber);
}

