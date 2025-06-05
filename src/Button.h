//
// Created by Administrator on 25-5-31.
//

#pragma once

#include "Widget.h"
#include "FontStyle.h"
#include "Util.hpp"



#include <functional>
#include <optional>

class Button : public Widget {

public:
    SDL_FColor normalColor_ = Util::colorToFColor({232, 201, 201, 255});
    SDL_FColor hoverColor_ = Util::colorToFColor({120, 120, 255, 255});
    SDL_FColor pressedColor_= Util::colorToFColor({80, 80, 200, 255});
    SDL_Color fontColor_ = { 0, 0, 0, 255 };
    SDL_FRect rect_;
    const char* text_;

    bool hovered = false;
    bool pressed = false;

    std::function<void()> onClick;

    explicit Button(const char* text, float x, float y, float w, float h);

    void event(const SDL_Event &e) override;

    bool draw(SDL_Renderer *renderer) override;

    void setFontColor(SDL_Color color);

    void destroy() override;

private:
    [[nodiscard]] bool contains(float x, float y) const;
};
