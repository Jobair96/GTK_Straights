//
// Created by jobair_hassan on 17/06/15.
//

#include "TableCards.h"
#include <iostream>

using namespace std;

TableCards::TableCards() {

}

TableCards::~TableCards() {

}

vector<Card> TableCards::tableCards() const {
    return tableCards_;
}

void TableCards::print() {
    cout << "Cards on the table:" << endl;

    cout << "Clubs: ";

    vector<Card> temp;

    // Clubs
    for(int i = 0; i < tableCards_.size(); ++i) {
        if(tableCards_[i].getSuit() == CLUB) {
            temp.push_back(tableCards_[i]);
        }
    }

    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i].getRank();
        if(i != temp.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    cout << "Diamonds: ";

    // Diamonds
    for(int i = 0; i < tableCards_.size(); ++i) {
        if(tableCards_[i].getSuit() == DIAMOND) {
            temp.push_back(tableCards_[i]);
        }
    }

    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i].getRank();
        if(i != temp.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    cout << "Hearts: ";

    // Hearts
    for(int i = 0; i < tableCards_.size(); ++i) {
        if(tableCards_[i].getSuit() == HEART) {
            temp.push_back(tableCards_[i]);
        }
    }

    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i].getRank();
        if(i != temp.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;
    cout << "Spades: ";

    // Spades
    for(int i = 0; i < tableCards_.size(); ++i) {
        if(tableCards_[i].getSuit() == SPADE) {
            temp.push_back(tableCards_[i]);
        }
    }

    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i].getRank();
        if(i != temp.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;
}
