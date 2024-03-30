#include <gtk/gtk.h>

#include "main.h"
#include "window.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        runWindow(argc, argv);
    } else {
        runWithFile("", argc, argv);
    }

    return 0;
}

void runWindow(int argc, char* argv[]) {
    Window window;
    window.title = "HDR Image Viewer";
    window.application = gtk_application_new("de.pp.image", G_APPLICATION_DEFAULT_FLAGS);
    window.width = 1080;
    window.height = 620;

    initialize_window(&window, argc, &argv);
}

void runWithFile(char* fileName, int argc, char* argv[]) {
}