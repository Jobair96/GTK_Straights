//
// Created by jobair_hassan on 12/07/15.
//

#ifndef HANDGUI_H
#define HANDGUI_H

#include <gtkmm.h>
#include "DeckGUI.h"

class HandGUI : public Gtk::Window {
public:
    HandGUI();
    virtual ~HandGUI();
private:
    DeckGUI deck;
};


#endif //HANDGUI_H
