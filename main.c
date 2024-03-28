#include <stdio.h>
#include <gtk/gtk.h>
#include "common.h"

int main(int argc, char* argv[]) {
    init_application("Window title", argc, argv);
    return 0;
}

static void init_application(char* title, int argc, char* argv[]) {
    GtkApplication *application;
    int status;

    application = gtk_application_new(
            "org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(application, "activate", G_CALLBACK(init_window), NULL);
    status = g_application_run(G_APPLICATION(application), argc, argv);
    g_object_unref(application);
}

static void init_window(GtkApplication *application, gpointer user_data) {
    GtkWindow *window = gtk_application_window_new(application);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 1080, 720);
    gtk_window_present(GTK_WINDOW(window));
}

