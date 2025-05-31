//
// Created by Administrator on 25-5-31.
//

#include "Button.h"

Button::Button(float x, float y, float w, float h, SDL_Renderer *renderer)
    : rect_{x, y, w, h}, renderer_(renderer)
{}

void Button::handleEvent(const SDL_Event &e) {
    SDL_Log("e: 0x%X", e.type);
    if (e.type == SDL_EVENT_MOUSE_MOTION) {
        float mx = e.motion.x;
        float my = e.motion.y;
        hovered = contains(mx, my);
    } else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN &&
               e.button.button == SDL_BUTTON_LEFT) {
        if (contains(e.button.x, e.button.y)) {
            pressed = true;
        }
    } else if (e.type == SDL_EVENT_MOUSE_BUTTON_UP &&
               e.button.button == SDL_BUTTON_LEFT) {
        if (contains(e.button.x, e.button.y) && pressed) {
            if (onClick) onClick();
        }
        pressed = false;
    }
}

void Button::draw(SDL_Renderer *renderer) {
    SDL_Color color = normalColor_;
    if (pressed) color = pressedColor_;
    else if (hovered) color = hoverColor_;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect_);
    SDL_RenderPresent(renderer);
}

bool Button::contains(float x, float y) const {
    return x >= rect_.x && x <= rect_.x + rect_.w &&
           y >= rect_.y && y <= rect_.y + rect_.h;
}
