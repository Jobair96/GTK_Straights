#include "Controller.h"

using namespace std;

Controller::Controller(Model *model) : model_(model) {

}

Controller::~Controller() {

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

void Controller::startNewGameButtonWithSeedButtonClicked(
        const int seed,
        string player_1_type,
        string player_2_type,
        string player_3_type,
        string player_4_type)
{
    // shuffle deck
    model_->shuffleDeck(seed);

    // initialize players
    model_->setPlayer(player_1_type, 1);
    model_->setPlayer(player_2_type, 2);
    model_->setPlayer(player_3_type, 3);
    model_->setPlayer(player_4_type, 4);

    // Initialize active player to player with seven of spades
    model_->setActivePlayer(model_->getPlayerWithCard(Card(SPADE, SEVEN))->playerNumber());

}

void Controller::playerRageButtonClicked(const int playerNumber) {

}

void Controller::endCurrentGameButtonClicked() {
    model_->clearTable();
    model_->resetPlayers();
    model_->resetLegalPlays();
}

void Controller::playerHandButtonClicked(const int indexOfCardPlayed) {
}
