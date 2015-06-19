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

    if(card.getSuit() == CLUB) {
        if (card.getRank() == ACE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, ACE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TWO));

            }
        }

        if (card.getRank() == TWO) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TWO));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, THREE));

            }
        }

        if (card.getRank() == THREE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, THREE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TWO));

            }
        }

        if (card.getRank() == FOUR) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FOUR));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, THREE));

            }
        }

        if (card.getRank() == FIVE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FIVE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FOUR));

            }
        }

        if (card.getRank() == SIX) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SIX));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FIVE));

            }
        }

        if (card.getRank() == SEVEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SEVEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SIX));

            }
        }

        if (card.getRank() == EIGHT) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, EIGHT));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SEVEN));

            }
        }

        if (card.getRank() == NINE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, NINE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, EIGHT));

            }
        }

        if (card.getRank() == TEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, NINE));

            }
        }

        if (card.getRank() == JACK) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, JACK));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TEN));

            }
        }

        if (card.getRank() == QUEEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, QUEEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, JACK));

            }
        }

        if (card.getRank() == KING) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, KING));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(CLUB, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, KING));

            }
        }
    }


    if(card.getSuit() == DIAMOND) {
        if (card.getRank() == ACE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, ACE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TWO));

            }
        }

        if (card.getRank() == TWO) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TWO));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, THREE));

            }
        }

        if (card.getRank() == THREE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, THREE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TWO));

            }
        }

        if (card.getRank() == FOUR) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FOUR));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, THREE));

            }
        }

        if (card.getRank() == FIVE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FIVE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FOUR));

            }
        }

        if (card.getRank() == SIX) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SIX));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FIVE));

            }
        }

        if (card.getRank() == SEVEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SEVEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SIX));

            }
        }

        if (card.getRank() == EIGHT) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, EIGHT));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SEVEN));

            }
        }

        if (card.getRank() == NINE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, NINE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, EIGHT));

            }
        }

        if (card.getRank() == TEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, NINE));

            }
        }

        if (card.getRank() == JACK) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, JACK));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TEN));

            }
        }

        if (card.getRank() == QUEEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, QUEEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, JACK));

            }
        }

        if (card.getRank() == KING) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(HEART, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, KING));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, KING));

            }
        }
    }

    if(card.getSuit() == HEART) {
        if (card.getRank() == ACE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, ACE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TWO));

            }
        }

        if (card.getRank() == TWO) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TWO));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, THREE));

            }
        }

        if (card.getRank() == THREE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, THREE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TWO));

            }
        }

        if (card.getRank() == FOUR) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FOUR));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, THREE));

            }
        }

        if (card.getRank() == FIVE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FIVE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FOUR));

            }
        }

        if (card.getRank() == SIX) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SIX));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FIVE));

            }
        }

        if (card.getRank() == SEVEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SEVEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SIX));

            }
        }

        if (card.getRank() == EIGHT) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, EIGHT));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SEVEN));

            }
        }

        if (card.getRank() == NINE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, NINE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, EIGHT));

            }
        }

        if (card.getRank() == TEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, NINE));

            }
        }

        if (card.getRank() == JACK) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, JACK));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TEN));

            }
        }

        if (card.getRank() == QUEEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, QUEEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, JACK));

            }
        }

        if (card.getRank() == KING) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, KING));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, KING));

            }
        }
    }

    if(card.getSuit() == SPADE) {
        if (card.getRank() == ACE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, ACE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TWO));

            }
        }

        if (card.getRank() == TWO) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TWO));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TWO));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, ACE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, ACE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, THREE));

            }
        }

        if (card.getRank() == THREE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, THREE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, THREE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TWO)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TWO));

            }
        }

        if (card.getRank() == FOUR) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FOUR));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FOUR));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, THREE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, THREE));

            }
        }

        if (card.getRank() == FIVE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, FIVE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, FIVE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FOUR)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FOUR));

            }
        }

        if (card.getRank() == SIX) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SIX));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SIX));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, FIVE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, FIVE));

            }
        }

        if (card.getRank() == SEVEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, SEVEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, SEVEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SIX)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SIX));

            }
        }

        if (card.getRank() == EIGHT) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, EIGHT));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, EIGHT));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, SEVEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, SEVEN));

            }
        }

        if (card.getRank() == NINE) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, NINE));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, NINE));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, EIGHT)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, EIGHT));

            }
        }

        if (card.getRank() == TEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, TEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, TEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, NINE)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, NINE));

            }
        }

        if (card.getRank() == JACK) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, JACK));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, JACK));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, TEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, TEN));

            }
        }

        if (card.getRank() == QUEEN) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, QUEEN));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, QUEEN));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, JACK)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, JACK));

            }
        }

        if (card.getRank() == KING) {
            if(find(legalPlays.begin(), legalPlays.end(), Card(DIAMOND, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(DIAMOND, KING));
            }

            if(find(legalPlays.begin(), legalPlays.end(), Card(CLUB, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(CLUB, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(HEART, KING)) == legalPlays.end()) {
                legalPlays.push_back(Card(HEART, KING));

            }

            if (find(legalPlays.begin(), legalPlays.end(), Card(SPADE, QUEEN)) == legalPlays.end()) {
                legalPlays.push_back(Card(SPADE, KING));

            }
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