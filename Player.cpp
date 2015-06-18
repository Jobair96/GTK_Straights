//
// Created by jobair_hassan on 16/06/15.
//

#include "Player.h"
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player() {

}

Player::Player(const Deck &deck, const int playerNumber) : playerNumber_(playerNumber) {
    for(int i = (playerNumber - 1) * 13; i < (playerNumber) * 13; ++i) {
        hand_.push_back(deck.cards()[i]);
    }
}

int Player::playerNumber() const {
    return playerNumber_;
}

bool Player::findCard(const Card card) const {
    if(find(hand_.begin(), hand_.end(), card) != hand_.end()) {
        return true;
    }

    return false;
}

void Player::updateLegalPlays(const TableCards &tableCards) {
    std::vector<Card> legalPlays;

    for(int i = 0; i < tableCards.tableCards().size(); ++i) {
        Card card = tableCards.tableCards()[i];

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
    }

    legalPlays_ = legalPlays;
}

void Player::print() const {
    cout << "Your hands: ";

    for(int i = 0; i < hand_.size(); ++i) {
        cout << hand_[i];
        if(i != hand_.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    cout << "Legal plays:";
    for(int i = 0; i < legalPlays_.size(); ++i) {
        cout << legalPlays_[i] << endl;
        if(i != legalPlays_.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;
}

