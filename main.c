#include <gtk/gtk.h>

#include "window.h"

int main(int argc, char* argv[]) {
    Window window;
    window.title = "HDR Image Viewer";
    window.application = gtk_application_new("de.pp.image", G_APPLICATION_DEFAULT_FLAGS);
    window.width = 1080;
    window.height = 620;

    if (argc <= 1) {
        window.title = "HDR Image Viewer";
        initialize_window(&window, argc, &argv);
    } else {
        window.title = argv[1];
        initialize_window(&window, argc, &argv);
    }

    return 0;
}