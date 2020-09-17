#include <gtk/gtk.h>


static void print_hello(GtkWidget *widget, gpointer data)
{
  // prints "Hello World" to the console using the gtk method for it
  g_print ("Hello World\n");
}

// function activates the application, giving it functionality and defining its necessary data
static void activate(GtkApplication *app, gpointer user_data)
{
  // initializes the window "object to be used to display values"
  GtkWidget *window;
  // initializes the middle button
  GtkWidget *button;
  // initializes the bounding box for the button
  GtkWidget *button_box;

  // sets the values of the initial window; semi self-explanatory names
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Gtk-Test-Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

  // defines the location and the properties of the box
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  // defines the center button's label
  button = gtk_button_new_with_label ("Hello World");
  // defines the function of the center button, these execute one right after the other
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);
  //places the functionality of the button onto the button_box structure (class)
  gtk_container_add (GTK_CONTAINER (button_box), button);

  // displays the window to the screen, making it visible
  gtk_widget_show_all (window);
}

int main(int argc, char **argv)
{
  // initializes a default application and a variable to determine the status of the program upon closing
  GtkApplication *app;
  int status;

  // app definition
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  // calling the activate function in a rather peculiar way
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  // runs all of the properties given to app by the activate function
  status = g_application_run (G_APPLICATION (app), argc, argv);
  // frees the application from memory
  g_object_unref (app);

  return status;
}
