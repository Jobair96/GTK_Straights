#include "View.h"

using namespace std;

int main(int argc, const char * argv[]) {

    // This is the main code we need

    Model model; // The model of the game
    Controller controller(&model); // The controller of the game
    View view(argc, argv, &model, &controller); // The view of the game, from which the game actually begins

    return 0;
}