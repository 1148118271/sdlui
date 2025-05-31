#include <SDL3/SDL.h>
#include <iostream>
//#include <SDL3/SDL_main.h>

#include "Button.h"

int main(int argc, char* argv[]) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Window* window =
            SDL_CreateWindow("Hello, SDL3!", 800, 600, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_Log("Create renderer failed: %s", SDL_GetError());
        return -1;
    }

    Button myButton(300, 250, 200, 80, renderer);
    myButton.onClick = []() {
        std::cout << "Button clicked!" << std::endl;
    };

    SDL_Event event{};
    bool keep_going = true;

    while (keep_going) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_EVENT_QUIT: {
                keep_going = false;
                break;
            }
            case SDL_EVENT_KEY_DOWN: {
                keep_going = keep_going && (event.key.key != SDLK_ESCAPE);
                break;
            }
            case SDL_EVENT_WINDOW_EXPOSED: {
                SDL_SetRenderDrawColor(renderer, 16, 0, 16, 255);
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                break;
            }
        }
        myButton.handleEvent(event);
        myButton.draw(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}