//
// Created by jobair_hassan on 16/06/15.
//

#include "Model.h"

using namespace std;

Model::Model() : deck_() {

}

Model::~Model() {

}

void Model::setPlayer(string playerType, int playerNumber) {
    if(playerType == "h") {
        if(playerNumber == 1) {
            player_1_ = Human(deck_, playerNumber);
        } else if(playerNumber == 2) {
            player_2_ = Human(deck_, playerNumber);
        } else if(playerNumber == 3) {
            player_3_ = Human(deck_, playerNumber);
        } else if(playerNumber == 4) {
            player_4_ = Human(deck_, playerNumber);
        }
    } else if(playerType == "c") {
        if(playerNumber == 1) {
            player_1_ = Computer(deck_, playerNumber);
        } else if(playerNumber == 2) {
            player_2_ = Computer(deck_, playerNumber);
        } else if(playerNumber == 3) {
            player_3_ = Computer(deck_, playerNumber);
        } else if(playerNumber == 4) {
            player_4_ = Computer(deck_, playerNumber);
        }
    }
}

void Model::shuffleDeck(int seed) {
    deck_.shuffle(seed);
}

Player Model::getPlayerWithCard(const Card card) const {
    if(player_1_.findCard(card)) {
        return player_1_;
    } else if(player_2_.findCard(card)) {
        return player_2_;
    } else if(player_3_.findCard(card)) {
        return player_3_;
    } else if(player_4_.findCard(card)) {
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

Player Model::activePlayer() const {
    return activePlayer_;
}

Deck Model::deck() const {
    return deck_;
}

TableCards Model::tableCards() const {
    return tableCards_;
}

void Model::updateAllLegalPlays() {

    player_1_.updateLegalPlays(tableCards_);
    player_2_.updateLegalPlays(tableCards_);
    player_3_.updateLegalPlays(tableCards_);
    player_4_.updateLegalPlays(tableCards_);

    activePlayer_ = activePlayer();
}
