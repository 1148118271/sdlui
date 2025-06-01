//
// Created by Administrator on 25-5-31.
//

#pragma once

#include "Widget.h"
#include <functional>


class Button : public Widget {

public:
    SDL_FColor normalColor_{100.0f / 255.0f, 100.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
    SDL_FColor hoverColor_{120.0f / 255.0f, 120.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
    SDL_FColor pressedColor_{80.0f / 255.0f, 80.0f / 255.0f, 200.0f / 255.0f, 255.0f / 255.0f};

    float x_;
    float y_;
    float w_;
    float h_;

    bool hovered = false;
    bool pressed = false;

    std::function<void()> onClick;

    Button(float x, float y, float w, float h);

    void event(const SDL_Event &e) override;

    bool draw(SDL_Renderer *renderer) override;


private:
    bool contains(float x, float y) const;
};
