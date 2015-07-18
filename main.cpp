#include <gtkmm/main.h>
#include "View.h"
#include "Model.h"
#include "Controller.h"

using namespace std;

int main(int argc, char * argv[]) {

    Gtk::Main kit(argc,argv); // Initialize gtkmm with the command line arguments, as appropriate.

    Model model; // The model of the game
    Controller controller(&model); // The controller of the game
    View view(&model, &controller); // The view of the game - it is passed handle to controller and model

    Gtk::Main::run(view);


    return 0;

} // main
