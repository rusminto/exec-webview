## Webview  
Many webview-based framework ([tauri](https://github.com/tauri-apps/tauri), [Neutralinojs](https://github.com/neutralinojs/neutralinojs)) said has [lighter resource usage](https://github.com/Elanis/web-to-desktop-framework-comparison#benchmarks) than chromium-based framework ([nwjs](https://github.com/nwjs/nw.js/), [electronjs](https://github.com/electron/electron)). With that reason i try to create simple [webview](https://github.com/webview/webview) that has similar function as [webview-nodejs](https://github.com/Winterreisender/webview-nodejs), [suchipi-webview](https://github.com/suchipi/webview) or [webview-node](https://github.com/suchipi/webview-node). If i can't create library, at least it can be exectuble command on any desktop platform.

## Build  
Same like documentation of [webview](https://github.com/webview/webview). To build command you can use command :  
```sh
# Linux
g++ basic.cc -std=c++11 -Ilibs/webview $(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0) -o build/basic && ./build/basic
# macOS
g++ basic.cc -std=c++11 -Ilibs/webview -framework WebKit -o build/basic && ./build/basic
# Windows/MinGW
g++ basic.cc -std=c++14 -mwindows -Ilibs/webview -Ilibs/webview2/build/native/include -ladvapi32 -lole32 -lshell32 -lshlwapi -luser32 -lversion -o build/basic.exe && "build/basic.exe"
```
