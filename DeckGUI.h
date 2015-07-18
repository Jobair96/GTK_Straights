#ifndef DECKGUI_H
#define DECKGUI_H

#include <gdkmm/pixbuf.h>
#include <vector>
#include "Deck.h"

class DeckGUI {
public:
    DeckGUI(); // Constructor
    virtual ~DeckGUI(); // Destructor

    Glib::RefPtr<Gdk::Pixbuf> getCardImage(const Rank, const Suit) const; // Returns the image for the scified card
    Glib::RefPtr<Gdk::Pixbuf> getNullCardImage() const; // Returns the image to use for the placeholder.
private:
    std::vector<Glib::RefPtr<Gdk::Pixbuf>> deck; // Contains the pixel buffer images
};


#endif //DECKGUI_H
