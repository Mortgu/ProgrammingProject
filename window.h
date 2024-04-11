#ifndef PROGRAMMINGPROJECT_WINDOW_H
#define PROGRAMMINGPROJECT_WINDOW_H

#include <gtk/gtk.h>

typedef struct {
    char *title;
    GtkApplication *application;
    int width;
    int height;
} Window;

//void render_default_content(GtkApplication *gtkApplication, Window *window);
int initialize_application(Window *window, int argc, char* argv[]);

#endif
