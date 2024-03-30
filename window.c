#include <gtk/gtk.h>
#include "window.h"

static void print_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

/**
 * This function generates the actual window and sets its attributes!
 *
 * @param gtkApplication = required param even if its not in use!
 * @param window = Pointer to the window struct!
 */
void create_window(GtkApplication *gtkApplication, Window *window) {
    GtkWidget *gtkWindow = gtk_application_window_new(window->application);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *button = gtk_button_new_with_label("Open Image");
    GtkWidget *label = gtk_label_new("oder");
    GtkWidget *label2 = gtk_label_new("right click > open with > hdr_image_viewer");

    /** WINDOW CONFIGURATION **/
    gtk_window_set_title(GTK_WINDOW(gtkWindow), window->title);
    gtk_window_set_default_size(GTK_WINDOW(gtkWindow), window->width, window->height);
    gtk_window_set_resizable(GTK_WINDOW(gtkWindow), false);

    /** SET BOX SETTINGS **/
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    gtk_window_set_child(GTK_WINDOW (gtkWindow), box);

    g_signal_connect (button, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK(gtk_window_destroy), gtkWindow);

    gtk_box_append(GTK_BOX (box), button);
    gtk_box_append(GTK_BOX (box), label);
    gtk_box_append(GTK_BOX (box), label2);

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
void initialize_window(Window *window, int argc, char *argv[]) {
    window->application = gtk_application_new("de.pp.image", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(window->application, "activate", G_CALLBACK(create_window), window);
    g_application_run(G_APPLICATION(window->application), argc, argv);
    g_object_unref(window->application);
}