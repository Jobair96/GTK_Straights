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
    return (find(legalPlays_.begin(), legalPlays_.end(), card) != legalPlays_.end())
           && activePlayer()->findCard(card);
}

Card Model::getFirstLegalPlay() const {
    vector<Card> activeHand = activePlayer()->hand();
    Card result = activeHand.at(0);

    for (int i = 0; i < activeHand.size(); ++i) {
        if (find(legalPlays_.begin(), legalPlays_.end(), activeHand.at(i)) != legalPlays_.end()) {
            result = activeHand.at(i);
            break;
        }
    }
    return result;
}

vector<Card> Model::getDiscards(int playerNumber) const {
    return getPlayer(playerNumber)->discards();
}

int Model::getScore(int playerNumber) const {
    return getPlayer(playerNumber)->score();
}

int Model::getScoreGain(int playerNumber) const {
    return getPlayer(playerNumber)->scoreGain();
}

Player *Model::getPlayer(int playerNumber) const {
    if (playerNumber == 1) {
        return player_1_;
    } else if (playerNumber == 2) {
        return player_2_;
    } else if (playerNumber == 3) {
        return player_3_;
    } else {
        return player_4_;
    }
}

vector<int> Model::getWinners() const {
    vector<int> winners;
    int lowestScore = getScore(1);

    for (int i = 1; i < 5; ++i) {
        if (getScore(i) <= lowestScore) {
            lowestScore = getScore(i);
        }
    }

    for (int i = 1; i < 5; ++i) {
        if (getPlayer(i)->score() == lowestScore) {
            winners.push_back(i);
        }
    }

    return winners;
}

bool Model::allHandsEmpty() const {
    return (player_1_->hand().size() + player_2_->hand().size() + player_3_->hand().size() + player_4_->hand().size()) == 0;
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
    if (legalPlays_.size() == 1) {
        setLegalPlay(Card(DIAMOND,SEVEN));
        setLegalPlay(Card(HEART,SEVEN));
        setLegalPlay(Card(CLUB,SEVEN));
    }

    if (card.getRank() > 0) {
        legalPlays_.push_back(Card(card.getSuit(), (Rank) (card.getRank() - 1)));
    }

    if (card.getRank() < 12) {
        legalPlays_.push_back(Card(card.getSuit(), (Rank) (card.getRank() + 1)));
    }
}

void Model::resetLegalPlays() {
    legalPlays_.clear();
    legalPlays_ = vector<Card>();
    setLegalPlay(Card(SPADE,SEVEN));
}

bool Model::isEndOfGame() const {
    if (player_1_->score() >= 80 || player_2_->score() >= 80 || player_3_->score() >= 80 || player_4_->score() >= 80) {
        return true;
    }
    return false;
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

void Model::updateScore(int playerNumber) {
    getPlayer(playerNumber)->updateScore();
}

void Model::clearTable() {
    tableCards_.clearTable();
}

void Model::resetPlayers() {
    for (int i = 1; i < 5; ++i) {
        getPlayer(i)->reset();
        getPlayer(i)->dealHand(deck_,i);
    }
}

void Model::replaceCurrentHumanWithComputer() {
    int playerNumber = getActivePlayerNumber();

    playerTypes_[playerNumber - 1] = "c";

    Player *currentPlayer = activePlayer();

    Computer *computer = static_cast<Computer*>(currentPlayer);

    *currentPlayer = *computer;
}