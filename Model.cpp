//
// Created by jobair_hassan on 16/06/15.
//

#include "Model.h"

using namespace std;

Model::Model() : deck_(), player_1_(NULL), player_2_(NULL), player_3_(NULL), player_4_(NULL) {

}

Model::~Model() {
    if(NULL != player_1_) {
        delete player_1_;
        player_1_ = NULL;
    }

    if(NULL != player_2_) {
        delete player_2_;
        player_2_ = NULL;
    }

    if(NULL != player_3_) {
        delete player_3_;
        player_3_ = NULL;
    }

    if(NULL != player_4_) {
        delete player_4_;
        player_4_ = NULL;
    }

}

void Model::setPlayer(string playerType, int playerNumber) {
    if(playerType == "h") {
        Human *human = new Human(deck_, playerNumber);
        if(playerNumber == 1) {
            player_1_ = human;
        } else if(playerNumber == 2) {
            player_2_ = human;
        } else if(playerNumber == 3) {
            player_3_ = human;
        } else if(playerNumber == 4) {
            player_4_ = human;
        }
    } else if(playerType == "c") {
        Computer *computer = new Computer(deck_, playerNumber);
        if(playerNumber == 1) {
            player_1_ = computer;
        } else if(playerNumber == 2) {
            player_2_ = computer;
        } else if(playerNumber == 3) {
            player_3_ = computer;
        } else if(playerNumber == 4) {
            player_4_ = computer;
        }
    }
}

void Model::shuffleDeck(int seed) {
    deck_.shuffle(seed);
}

Player* Model::getPlayerWithCard(const Card card) const {
    if(player_1_->findCard(card)) {
        return player_1_;
    } else if(player_2_->findCard(card)) {
        return player_2_;
    } else if(player_3_->findCard(card)) {
        return player_3_;
    } else if(player_4_->findCard(card)) {
        return player_4_;
    }
}

void Model::setActivePlayer(const int playerNumber) {
    if(playerNumber == 1) {
        activePlayer_ = player_1_;
    } else if(playerNumber == 2) {
        activePlayer_ = player_2_;
    } else if(playerNumber == 3) {
        activePlayer_ = player_3_;
    } else if(playerNumber == 4) {
        activePlayer_ = player_4_;
    }
}

Player* Model::activePlayer() const {
    return activePlayer_;
}

Deck Model::deck() const {
    return deck_;
}

TableCards Model::tableCards() const {
    return tableCards_;
}

void Model::updateAllLegalPlays() {

    player_1_->updateLegalPlays(tableCards_);
    player_2_->updateLegalPlays(tableCards_);
    player_3_->updateLegalPlays(tableCards_);
    player_4_->updateLegalPlays(tableCards_);

    activePlayer_ = activePlayer();
}

void Model::addCardToTable(const Card card) {
    tableCards_.addCard(card);
}

void Model::updateActivePlayer() {
    Player *currentActivePlayer = activePlayer();
    if(currentActivePlayer == player_1_) {
        activePlayer_ = player_2_;
    } else if(currentActivePlayer == player_2_) {
        activePlayer_ = player_3_;
    } else if(currentActivePlayer == player_3_) {
        activePlayer_ = player_3_;
    } else if(currentActivePlayer == player_4_) {
        activePlayer_ = player_1_;
    }
}

void Model::replaceCurrentHumanWithComputer() {
    Player *currentPlayer = activePlayer();

    Computer *computer = static_cast<Computer*>(currentPlayer);

    *currentPlayer = *computer;
}