#include <gtk/gtk.h>
#include "window.h"

/**
 * This function generates the actual window and sets its attributes!
 *
 * @param gtkApplication = required param even if its not in use!
 * @param window = Pointer to the window struct!
 */
void create_window(GtkApplication *gtkApplication, Window *window) {
    GtkWidget *gtkWindow = gtk_application_window_new(window->application);

    gtk_window_set_title(GTK_WINDOW(gtkWindow), window->title);
    gtk_window_set_default_size(GTK_WINDOW(gtkWindow), window->width, window->height);
    gtk_window_set_resizable(GTK_WINDOW(gtkWindow), false);

    gtk_window_present(GTK_WINDOW(gtkWindow));
}

/**
 *
 * This function handles the initialization of the application window.
 *
 * @param window
 * @param argc
 * @param argv
 */
void initialize_window(Window *window, int argc, char* argv[]) {
    window->application = gtk_application_new("de.pp.image", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(window->application, "activate", G_CALLBACK(create_window), window);
    g_application_run(G_APPLICATION(window->application), argc, argv);
    g_object_unref(window->application);
}