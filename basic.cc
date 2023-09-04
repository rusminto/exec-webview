#include "webview.h"
#include <gtk/gtk.h>

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
                   LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
#else
int main() {
#endif

  // https://stackoverflow.com/questions/43734072/how-to-make-a-gtk-application-go-fullscreen-overcoming-the-window-manager-gtk-w
  // https://www.codeguru.com/cplusplus/creating-a-c-c-gui-with-gtk/
  GtkWidget *window;
  gtk_init(nullptr, nullptr);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show(window);
  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL); 
  gtk_window_fullscreen(GTK_WINDOW(window));

  // https://github.com/webview/webview/issues/568
  // true for debug
  webview::webview w(true, GTK_WINDOW(window));
 
  w.set_title("Basic Example");
  w.set_size(480, 320, WEBVIEW_HINT_NONE);
  w.navigate("https://youtube.com");
  gtk_main();

  //w.run();
  return 0;
}
