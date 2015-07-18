#include "Model.h"
#include <algorithm>

using namespace std;

Model::Model() : deck_(), player_1_(nullptr), player_2_(nullptr), player_3_(nullptr), player_4_(nullptr) {
    Model::setLegalPlay(Card(SPADE, SEVEN));
}

Model::~Model() {
    if(nullptr != player_1_) {
        delete player_1_;
        player_1_ = nullptr;
    }

    if(nullptr != player_2_) {
        delete player_2_;
        player_2_ = nullptr;
    }

    if(nullptr != player_3_) {
        delete player_3_;
        player_3_ = nullptr;
    }

    if(nullptr != player_4_) {
        delete player_4_;
        player_4_ = nullptr;
    }

}

void Model::setPlayer(string playerType, int playerNumber) {
    playerTypes_[playerNumber - 1] = playerType;

    Player *player = nullptr;

    if(playerType == "Human") {
        player = new Human(deck_, playerNumber);
    } else if(playerType == "Computer") {
        player = new Computer(deck_, playerNumber);
    }

    if(playerNumber == 1) {
        deletePlayer(1);
        player_1_ = player;
    } else if(playerNumber == 2) {
        deletePlayer(2);
        player_2_ = player;
    } else if(playerNumber == 3) {
        deletePlayer(3);
        player_3_ = player;
    } else if(playerNumber == 4) {
        deletePlayer(4);
        player_4_ = player;
    }

}

void Model::shuffleDeck(const int seed) {
    gameSeed_ = seed;
    deck_.shuffle(seed);
}

void Model::shuffleDeckWithPersistedSeed() {
    shuffleDeck(gameSeed_);
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
    return nullptr;
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

    if(isActiveHumanPlayer()) {
        notify();
    }
}

Player* Model::activePlayer() const {
    return activePlayer_;
}

Player* Model::getPreviousPlayer() const {
    if (activePlayer_ == player_1_) {
        return player_4_;
    } else if (activePlayer_ == player_2_) {
        return player_1_;
    } else if (activePlayer_ == player_3_) {
        return player_2_;
    } else {
        return player_3_;
    }
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
    return "Human" == playerTypes_[getActivePlayerNumber() - 1];
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
    if (card == Card(SPADE, SEVEN)) {
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

    //notify();
}

void Model::resetLegalPlays() {
    legalPlays_.clear();
    legalPlays_ = vector<Card>();
    setLegalPlay(Card(SPADE,SEVEN));
}

bool Model::isEndOfGame() const {
    if(!player_1_ && !player_2_ && !player_3_ && !player_4_) {
        return true;
    }

    if (allHandsEmpty() &&
            (player_1_->score() + player_1_->scoreGain() >= 80
        || player_2_->score() + player_2_->scoreGain() >= 80
        || player_3_->score() + player_3_->scoreGain() >= 80
        || player_4_->score() + player_4_->scoreGain() >= 80)) {
        return true;
    }

    return false;
}

void Model::addCardToTable(const Card card) {
    tableCards_.addCard(card);

    //notify();
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

    notify();
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

void Model::restartGame(const int seed) {
    deck_.shuffle(seed);

    Player* tempPlayer = nullptr;

    for (int i = 0; i < 4; ++i) {
        if (playerTypes_[i] == "Human") {
            tempPlayer = new Human(deck_, i + 1);
        } else {
            tempPlayer = new Computer(deck_, i + 1);
        }

        if (i == 0) {
            deletePlayer(1);
            player_1_ = tempPlayer;
        }
        else if (i == 1) {
            deletePlayer(2);
            player_2_ = tempPlayer;
        }
        else if (i == 2) {
            deletePlayer(3);
            player_3_ = tempPlayer;
        }
        else {
            deletePlayer(4);
            player_4_ = tempPlayer;
        }

        if (tempPlayer->findCard(Card(SPADE, SEVEN))) {
            setActivePlayer(i + 1);
        }
    }

    delete tempPlayer;
    tempPlayer = nullptr;

}

void Model::resetGame() {
    delete player_1_;
    delete player_2_;
    delete player_3_;
    delete player_4_;

    player_1_ = nullptr;
    player_2_ = nullptr;
    player_3_ = nullptr;
    player_4_ = nullptr;

    deck_ = Deck();

    tableCards_.clearTable();

    legalPlays_.clear();
    legalPlays_ = vector<Card>();
    setLegalPlay(Card(SPADE, SEVEN));

}

void Model::replaceCurrentHumanWithComputer() {
    int playerNumber = getActivePlayerNumber();

    playerTypes_[playerNumber - 1] = "Computer";

    Player *currentPlayer = activePlayer();

    Computer *computer = static_cast<Computer*>(currentPlayer);

    *currentPlayer = *computer;
}

void Model::removeCardFromActivePlayer(Card card) {
    Model::activePlayer()->removeCard(card);

    //notify();

}

void Model::discardFromActivePlayer(Card card) {
    Model::activePlayer()->discard(card);

    //notify();

}

void Model::deletePlayer(const int playerNumber) {
    if(playerNumber == 1) {
        if(nullptr != player_1_) {
            delete player_1_;
            player_1_ = nullptr;
        }
    }

    if(playerNumber == 2) {
        if(nullptr != player_2_) {
            delete player_2_;
            player_2_ = nullptr;
        }
    }

    if(playerNumber == 3) {
        if(nullptr != player_3_) {
            delete player_3_;
            player_3_ = nullptr;
        }
    }

    if(playerNumber == 4) {
        if(nullptr != player_4_) {
            delete player_4_;
            player_4_ = nullptr;
        }
    }

}
