//
// Created by Administrator on 25-5-31.
//

#pragma once

#include <SDL3/SDL.h>
#include <functional>


class Button {

public:

    SDL_Renderer *renderer_;

    SDL_FColor normalColor_{5.0f, 50.0f, 255.0f, 1.0f};
    SDL_FColor hoverColor_{120.0f, 120.0f, 255.0f, 255.0f};
    SDL_FColor pressedColor_{80.0f, 80.0f, 200.0f, 255.0f};

    float x_;
    float y_;
    float w_;
    float h_;

    bool hovered = false;
    bool pressed = false;

    std::function<void()> onClick;

    Button(float x, float y, float w, float h, SDL_Renderer *renderer);

    void handleEvent(const SDL_Event &e);

    void draw(SDL_Renderer *renderer);


private:
    bool contains(float x, float y) const;
};
