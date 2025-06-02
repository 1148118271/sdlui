#include <SDL3/SDL.h>
#include <iostream>
//#include <SDL3/SDL_main.h>

#include "Window.h"
#include "Button.h"

int main(int argc, char* argv[]) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);


    Window window;
    window.setColor({232, 217, 217, 1});

#ifdef _WIN32
    window.loadFont("C:/Windows/Fonts/msyhl.ttc", 45);
#endif
    Button btn("点击", 200, 200, 100, 50);

    btn.onClick = []() {
        SDL_Log("的吗徐阿姨");
    };

    window.addWidget(btn);

    if (!window.show("主窗口", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }
    window.destroy();
    return 0;
}