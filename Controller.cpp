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

Player* Controller::activePlayer() const {
    return model_->activePlayer();
}

vector<Card> Controller::getActiveHand() const {
    return activePlayer()->hand();
}

vector<Card> Controller::getDiscards(int playerNumber) const {
    return model_->getDiscards(playerNumber);
}

int Controller::getScore(int playerNumber) const {
    return model_->getScore(playerNumber);
}

int Controller::getScoreGain(int playerNumber) const {
    return model_->getScoreGain(playerNumber);
}

vector<int> Controller::getWinners() const {
    return model_->getWinners();
}

void Controller::setFirstPlayer(const int playerNumber) {
    setActivePlayer(playerNumber);
    model_->resetLegalPlays();
}

bool Controller::isActiveHumanPlayer() const {
    return model_->isActiveHumanPlayer();
}

bool Controller::isLegalPlay(const Card card) const {
    return model_->isLegal(card);
}

bool Controller::isEndOfGame() const {
    return model_->isEndOfGame();
}

bool Controller::isEndOfRound() const {
    return model_->allHandsEmpty();
}

void Controller::playCard(Card card) {
    model_->activePlayer()->removeCard(card);
    model_->addCardToTable(card);
    model_->updateLegalPlays(card);
    model_->updateActivePlayer();
}

void Controller::clearTable() {
    model_->clearTable();
}

void Controller::resetPlay() {
    model_->resetPlayers();
    model_->resetLegalPlays();
}

void Controller::rageQuit() {
    model_->replaceCurrentHumanWithComputer();
}

void Controller::completeComputerPlayCard() {
    Card card = model_->getFirstLegalPlay();
    playCard(card);
}

void Controller::updateScore(int playerNumber) {
    model_->updateScore(playerNumber);
}

void Controller::completeComputerDiscard() {
    Card card = model_->activePlayer()->hand().at(0);
    discard(card);
}

void Controller::discard(const Card card) {
    model_->activePlayer()->removeCard(card);
    model_->activePlayer()->discard(card);
    model_->updateActivePlayer();
}
