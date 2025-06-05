//
// Created by Administrator on 25-6-1.
//


#include "Window.h"
#include "Font.h"

bool Window::show(const char *title, int x, int y, int w, int h) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return false;
    }
    window_ = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE);
    if (!window_) {
        return false;
    }
    SDL_SetWindowPosition(window_, x, y);
    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (!renderer_) {
        return false;
    }
    bool run = true;
    while (run) {
        SDL_WaitEvent(&event_);
        switch (event_.type) {
            case SDL_EVENT_QUIT: {
                run = false;
                break;
            }
            case SDL_EVENT_KEY_DOWN: {
                run = event_.key.key != SDLK_ESCAPE;
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer_, color_.r, color_.g, color_.b, color_.a);
        SDL_RenderClear(renderer_);

        draws();

        SDL_RenderPresent(renderer_);
    }
    return true;
}

void Window::addWidget(Widget &widget) {
    widgets_.push_back(&widget);
}

void Window::setColor(SDL_Color color) {
    color_ = color;
}

bool Window::draws() {
    if (!widgets_.empty()) {
        for (auto &widget: widgets_) {
            widget->event(event_);
            bool r = widget->draw(renderer_);
            if (!r)
                return false;
        }
    }
    return true;
}

void Window::destroy() {
    if (!widgets_.empty()) {
        for (auto &widget: widgets_) {
            widget->destroy();
        }
    }

    Font::close();
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    TTF_Quit();
    SDL_Quit();
}

bool Window::loadFont(const char *fontPath) {
    if (!TTF_Init()) {
        return false;
    }
    Font::setFontPath(fontPath);
    return true;
}




