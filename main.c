#include <gtk/gtk.h>
#include "window.h"

int main(int argc, char* argv[]) {
    Window window;
    window.title = "Window Title";
    window.application = gtk_application_new("de.pp.oskar", G_APPLICATION_DEFAULT_FLAGS);
    window.width = 1080;
    window.height = 620;

    initialize_window(&window, argc, &argv);
    return 0;
}
