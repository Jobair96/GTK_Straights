//
// Created by jobair_hassan on 16/06/15.
//

#include "Controller.h"

using namespace std;

Controller::Controller(Model &model) : model_(model) {

}

Controller::~Controller() {

}

void Controller::initializePlayer(const string playerType, const int playerNumber) {
    model_.setPlayer(playerType, playerNumber);
}

void Controller::initializeDeck(const int seed) {
    model_.shuffleDeck(seed);
}

void Controller::setActivePlayer(const int playerNumber) {
    model_.setActivePlayer(playerNumber);
}
int Controller::getPlayerWithSevenSpade(const Card card) const {
    return model_.getPlayerWithCard(card).playerNumber();
}

void Controller::updateLegalPlays() {
    model_.updateAllLegalPlays();
}

Player Controller::activePlayer() const {
    return model_.activePlayer();
}
