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

void TableCards::addCard(const Card card) {
    tableCards_.push_back(card);
}
