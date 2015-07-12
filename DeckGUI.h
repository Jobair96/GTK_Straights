//
// Created by jobair_hassan on 12/07/15.
//

#ifndef DECKGUI_H
#define DECKGUI_H
#include <gdkmm/pixbuf.h>
#include <vector>
#include "Deck.h"

class DeckGUI {
public:
    DeckGUI();
    virtual ~DeckGUI();
    Glib::RefPtr<Gdk::Pixbuf> getCardImage(Rank, Suit); // Returns the image for the scified card
    Glib::RefPtr<Gdk::Pixbuf> getNullCardImage(); // Returns the image to use for the placeholder.
private:
    std::vector<Glib::RefPtr<Gdk::Pixbuf>> deck; // Contains the pixel buffer images
};


#endif //DECKGUI_H
