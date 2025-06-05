//
// Created by Administrator on 25-5-31.
//

#include "Button.h"
#include "FontStyle.h"
#include "Font.h"


Button::Button(const char* text, float x, float y, float w, float h)
    : text_(text), rect_(x, y, w, h)
{}

void Button::event(const SDL_Event &e) {
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

bool Button::draw(SDL_Renderer *renderer) {
    SDL_FColor color = normalColor_;
    if (pressed) color = pressedColor_;
    else if (hovered) color = hoverColor_;
    float currentSize = ((rect_.w + rect_.h) - (20.f * 2.f)) / 4;
    TTF_Font *font = Font::getFont(currentSize);
    SDL_Texture *texture = FontStyle::renderText(renderer, font, text_, fontColor_, Util::fColorToColor(color));
    SDL_FRect textRect = {};
    textRect.w = (float) texture->w;
    textRect.h = (float) texture->h;
    textRect.x = rect_.x + ((rect_.w - textRect.w) / 2);
    textRect.y = rect_.y + ((rect_.h - textRect.h) / 2);
    SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect_);
    SDL_RenderTexture(renderer, texture, nullptr, &textRect);
    SDL_DestroyTexture(texture);
    return true;
}

bool Button::contains(float x, float y) const {
    return x >= rect_.x && x <= rect_.x + rect_.w &&
           y >= rect_.y && y <= rect_.y + rect_.h;
}

void Button::setFontColor(SDL_Color color) {
    fontColor_ = color;
}

void Button::destroy() {

}
