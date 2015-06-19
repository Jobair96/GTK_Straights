//
// Created by jobair_hassan on 16/06/15.
//

#include "Model.h"
#include <algorithm>

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
    playerTypes_[playerNumber - 1] = playerType;

    Player *player = NULL;

    if(playerType == "h") {
        player = new Human(deck_, playerNumber);
    } else if(playerType == "c") {
        player = new Computer(deck_, playerNumber);
    }

    if(playerNumber == 1) {
        player_1_ = player;
    } else if(playerNumber == 2) {
        player_2_ = player;
    } else if(playerNumber == 3) {
        player_3_ = player;
    } else if(playerNumber == 4) {
        player_4_ = player;
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
    return NULL;
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

int Model::getActivePlayerNumber() const {
    if (activePlayer() == player_1_) {
        return 1;
    } else if (activePlayer() == player_2_) {
        return 2;
    } else if (activePlayer() == player_3_) {
        return 3;
    } else {
        return 4;
    }
}

bool Model::isActiveHumanPlayer() const {
    return "h" == playerTypes_[getActivePlayerNumber() - 1];
}

Deck Model::deck() const {
    return deck_;
}

TableCards Model::tableCards() const {
    return tableCards_;
}

void Model::setLegalPlay(const Card card) {
    legalPlays_.push_back(card);
}

bool Model::isLegal(const Card card) const {
    return find(legalPlays_.begin(), legalPlays_.end(), card) != legalPlays_.end();
}

Card Model::getFirstLegalPlay() const {
    vector<Card> activeHand = activePlayer()->hand();

    for (int i = 0; i < activeHand.size(); ++i) {
        if (find(legalPlays_.begin(), legalPlays_.end(), activeHand.at(i)) != legalPlays_.end()) {
            return activeHand.at(i);
        }
    }
}

bool Model::hasLegalPlay() const {
    bool result = false;

    vector<Card> activeHand = activePlayer()->hand();

    for (int i = 0; i < activeHand.size(); ++i) {
        if (find(legalPlays_.begin(), legalPlays_.end(), activeHand.at(i)) != legalPlays_.end()) {
            result = true;
            break;
        }
    }

    return result;
}

void Model::updateLegalPlays(Card card) {
    std::vector<Card> legalPlays;

    if (card.getRank() > 0) {
        legalPlays.push_back(Card(card.getSuit(), (Rank)(card.getRank() - 1)));
    }

    if (card.getRank() < 12) {
        legalPlays.push_back(Card(card.getSuit(), (Rank)(card.getRank() + 1)));
    }

    for (int i = 0; i < 4; ++i) {
        if (i != card.getSuit()) {
            legalPlays.push_back(Card((Suit)i, card.getRank()));
        }
    }

    legalPlays_ = legalPlays;
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
        activePlayer_ = player_4_;
    } else if(currentActivePlayer == player_4_) {
        activePlayer_ = player_1_;
    }
}

void Model::replaceCurrentHumanWithComputer() {
    Player *currentPlayer = activePlayer();

    Computer *computer = static_cast<Computer*>(currentPlayer);

    *currentPlayer = *computer;
}