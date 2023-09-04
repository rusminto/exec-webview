#include <gtk/gtk.h>

// https://www.codeguru.com/cplusplus/creating-a-c-c-gui-with-gtk/

int main(int argc, char *argv[]) {

  GtkWidget *window;

  gtk_init(nullptr, nullptr);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show(window);
  
  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);  

  
  gtk_window_fullscreen(GTK_WINDOW(window));

  gtk_main();

  return 0;
}
