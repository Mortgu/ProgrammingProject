#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "window.h"

struct text_node {
    struct text_node *next;
    char *text;
};

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("Arg: %s", argv[i]);
    }

    Window window;
    window.title = "HDR Image Viewer";
    window.application = gtk_application_new("de.pp.image", G_APPLICATION_DEFAULT_FLAGS);
    window.width = 1080;
    window.height = 620;
    window.title = "HDR Image Viewer";

    return initialize_application(&window, argc, argv);
}