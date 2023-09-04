#ifdef __linux__
// https://stackoverflow.com/questions/6649936/c-compiling-on-windows-and-linux-ifdef-switch
#include <gtk/gtk.h>
#endif

#include "webview.h"
#include <iostream>
using namespace std;


void showHelp(){
  const char * message = R"(
Usage : webview --title hi --width 1000 --height 800 --url https://www.google.com

Run your website on webview. If any installation failed please check my repo
or check github.com/webview/webview. This is available options that you can
use :
  --title [string]      Title of window
  --width [integer]     Width of window
  --height [integer]    Height of window
  --url [string]        URL to navigate when window opened
  --html [string]       Path of html to navigate when window opened
  --fullscreen          To make window fullscreen
  --debug               To allow inspect element on webview
  --help                To show this message
Some notes :
- Please only use one of --url or --html. You can't use both in one command
- Fullscreen option only works in linux (gtk)
)";
  cout << message;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
                   LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
#else
int main(int argc, char* argv[]) {
#endif

  string pTitle = "";
  int pWidth = 100;
  int pHeight = 100;
  string pUrl = "";
  bool pIsFullScreen = false;
  bool pIsDebug = false;
  string pHtml = "";

  for (int i = 0; i < argc; i++) {
    if(string(argv[i]) == "--title"){
      pTitle = string(argv[i + 1]);
    }else if(string(argv[i]) == "--width"){
      pWidth = stoi(string(argv[i + 1]));
    }else if(string(argv[i]) == "--height"){
      pHeight = stoi(string(argv[i + 1]));
    }else if(string(argv[i]) == "--url"){
      pUrl = string(argv[i + 1]);
    }else if(string(argv[i]) == "--fullscreen"){
      pIsFullScreen = true;
    }else if(string(argv[i]) == "--debug"){
      pIsDebug = true;
    }else if(string(argv[i]) == "--html"){
      pHtml = string(argv[i + 1]);
    }else if(string(argv[i]) == "--help"){
      showHelp();
      exit(0);
    }
  }

  if(argc <= 1){
    showHelp();
    exit(0);
  }

  // currently fullscreen only works for linux (gtk)
  #ifdef __linux__
  GtkWidget *window;
  if(pIsFullScreen){
    // https://stackoverflow.com/questions/43734072/how-to-make-a-gtk-application-go-fullscreen-overcoming-the-window-manager-gtk-w
    // https://www.codeguru.com/cplusplus/creating-a-c-c-gui-with-gtk/
    gtk_init(nullptr, nullptr);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    g_signal_connect(window, "destroy",
        G_CALLBACK(gtk_main_quit), NULL); 
    gtk_window_fullscreen(GTK_WINDOW(window));
  }

  // https://github.com/webview/webview/issues/568
  webview::webview w(pIsDebug, pIsFullScreen ? GTK_WINDOW(window) : nullptr);
  #else
  webview::webview w(pIsDebug, nullptr);
  #endif
 
  w.set_title(pTitle);
  w.set_size(pWidth, pHeight, WEBVIEW_HINT_NONE);

  if(pUrl != ""){
    w.navigate(pUrl);
  }

  if(pHtml != ""){
    w.set_html(pHtml);
  }

  if(pIsFullScreen){
    gtk_main();
  }else{
    w.run();
  }

  return 0;
}
