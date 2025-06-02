//
// Created by Administrator on 25-5-31.
//

#pragma once

#include "Widget.h"
#include "Util.hpp"
#include "SDL3_ttf/SDL_ttf.h"
#include <functional>


class Button : public Widget {

public:
    SDL_FColor normalColor_ = Util::colorToFColor({232, 201, 201, 255});
    SDL_FColor hoverColor_ = Util::colorToFColor({120, 120, 255, 255});
    SDL_FColor pressedColor_= Util::colorToFColor({80, 80, 200, 255});

    float x_;
    float y_;
    float w_;
    float h_;

    bool hovered = false;
    bool pressed = false;

    std::function<void()> onClick;

    explicit Button(float x, float y, float w, float h);

    void event(const SDL_Event &e) override;

    bool draw(SDL_Renderer *renderer, TTF_Font *font) override;


private:
    bool contains(float x, float y) const;
};
