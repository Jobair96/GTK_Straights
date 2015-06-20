#include "TableCards.h"

using namespace std;

TableCards::TableCards() {

}

TableCards::~TableCards() {

}

vector<Card> TableCards::tableCards() const {
    return tableCards_;
}

void TableCards::addCard(const Card card) {
    for (int i = 0; i < tableCards_.size(); ++i) {
        if (tableCards_.at(i).getRank() > card.getRank()) {
            tableCards_.insert(tableCards_.begin() + i, card);
            return;
        }
    }

    tableCards_.push_back(card);
}

void TableCards::clearTable() {
    tableCards_.clear();
    tableCards_ = vector<Card>();
}