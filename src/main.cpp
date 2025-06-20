#include <SDL3/SDL.h>
#include <iostream>
//#include <SDL3/SDL_main.h>

#include "Window.h"
#include "Button.h"
#include "Editor.h"

int main(int argc, char* argv[]) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);



    Window window;
    window.setColor({30, 31, 34, 255});

#ifdef _WIN32
    window.loadFont("C:/Windows/Fonts/msyh.ttc");
#endif
//    Button btn("点击", 200, 200, 90, 40);
//
//
//    btn.onClick = []() {
//        std::cout << "sssss" << std::endl;
//    };

    Editor editor(&window);
    window.addWidget(editor);



    if (!window.show("主窗口", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }
    window.destroy();
    return 0;
}