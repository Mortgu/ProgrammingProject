#ifndef PROGRAMMINGPROJECT_WINDOW_H
#define PROGRAMMINGPROJECT_WINDOW_H

#include <gtk/gtk.h>

typedef struct {
    char *title;
    GtkApplication *application;
    int width;
    int height;
} Window;

void create_window(GtkApplication *gtkApplication, Window *window);
void initialize_window(Window *window, int argc, char* argv[]);

#endif
