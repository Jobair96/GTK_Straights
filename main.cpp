#include <iostream>
#include "Command.h"
#include "Deck.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "View.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // This is the main code we need
    Model model;
    Controller controller(&model);
    View view(argc, argv, &model, &controller);

    return 0;
}