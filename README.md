## Webview  
Many webview-based framework ([tauri](https://github.com/tauri-apps/tauri), [Neutralinojs](https://github.com/neutralinojs/neutralinojs)) said has [lighter resource usage](https://github.com/Elanis/web-to-desktop-framework-comparison#benchmarks) than chromium-based framework ([nwjs](https://github.com/nwjs/nw.js/), [electronjs](https://github.com/electron/electron)). With that reason i try to create simple [webview](https://github.com/webview/webview) that has similar function as [webview-nodejs](https://github.com/Winterreisender/webview-nodejs), [suchipi-webview](https://github.com/suchipi/webview) or [webview-node](https://github.com/suchipi/webview-node). If i can't create library, at least it can be exectuble command on any desktop platform.

## Usage  
```
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
```

## Result example
![image](/uploads/970547dfddc8799de2d0c9e13c2805df/image.png)  

As reminder, use right click to open "Inspect Element".

## Build  
Same like documentation of [webview](https://github.com/webview/webview). To build command you can use command :  
```sh
# Linux
g++ webview.cc -std=c++11 -Ilibs/webview $(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0) -o build/webview
# macOS
g++ webview.cc -std=c++11 -Ilibs/webview -framework WebKit -o build/webview
# Windows/MinGW
g++ webview.cc -std=c++14 -mwindows -Ilibs/webview -Ilibs/webview2/build/native/include -ladvapi32 -lole32 -lshell32 -lshlwapi -luser32 -lversion -o build/webview.exe
```
