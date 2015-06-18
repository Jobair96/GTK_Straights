//
// Created by jobair_hassan on 16/06/15.
//

#include "Controller.h"

using namespace std;

Controller::Controller(Model *model) : model_(model) {

}

Controller::~Controller() {

}

void Controller::initializePlayer(const string playerType, const int playerNumber) {
    model_->setPlayer(playerType, playerNumber);
}

void Controller::initializeDeck(const int seed) {
    model_->shuffleDeck(seed);
}

void Controller::setActivePlayer(const int playerNumber) {
    model_->setActivePlayer(playerNumber);
}
int Controller::getPlayerWithSevenSpade(const Card card) const {
    return model_->getPlayerWithCard(card)->playerNumber();
}

void Controller::updateLegalPlays() {
    model_->updateAllLegalPlays();
}

Player* Controller::activePlayer() const {
    return model_->getActivePlayer();
}

void Controller::setFirstPlayer(const int playerNumber) {
    setActivePlayer(playerNumber);
    model_->getActivePlayer()->setLegalPlay(Card(SPADE, SEVEN));
}

bool Controller::isActiveHumanPlayer() const {
    return model_->isActiveHumanPlayer();
}

bool Controller::isLegalPlay(const Card card) const {
    return model_->getActivePlayer()->checkCard(card);
}

void Controller::playCard(Card card) {
    model_->getActivePlayer()->removeCard(card);
    model_->addCardToTable(card);
    model_->updateAllLegalPlays();
    model_->updateActivePlayer();
}

void Controller::playComputerTurn() {
    model_->updateActivePlayer();
}

void Controller::rageQuit() {
    model_->replaceCurrentHumanWithComputer();
}
