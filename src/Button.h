//
// Created by Administrator on 25-5-31.
//

#pragma once

#include <SDL3/SDL.h>
#include <functional>


class Button {

public:

    SDL_Renderer *renderer_;

    SDL_FRect rect_;
    SDL_Color normalColor_{100, 100, 255, 255};
    SDL_Color hoverColor_{120, 120, 255, 255};
    SDL_Color pressedColor_{80, 80, 200, 255};

    bool hovered = false;
    bool pressed = false;

    std::function<void()> onClick;

    Button(float x, float y, float w, float h, SDL_Renderer *renderer);

    void handleEvent(const SDL_Event &e);

    void draw(SDL_Renderer *renderer);


private:
    bool contains(float x, float y) const;
};
