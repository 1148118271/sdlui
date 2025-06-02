//
// Created by Administrator on 25-5-31.
//

#include <array>
#include "Button.h"
#include "FontStyle.h"


Button::Button(const char* text, float x, float y, float w, float h)
    : text_(text), x_(x), y_(y), w_(w), h_(h)
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

bool Button::draw(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Log("draw");
    SDL_FColor color = normalColor_;
    if (pressed) color = pressedColor_;
    else if (hovered) color = hoverColor_;
    std::array<SDL_Vertex, 6> vertex = {
        SDL_Vertex{ .position = {x_, y_},               .color = color,     .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_, y_ + h_},          .color = color,     .tex_coord = {0.0f, 1.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_},          .color = color,     .tex_coord = {1.0f, 0.0f} },
        SDL_Vertex{ .position = {x_, y_ + h_},          .color = color,     .tex_coord = {0.0f, 1.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_},          .color = color,     .tex_coord = {1.0f, 0.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_ + h_},     .color = color,     .tex_coord = {1.0f, 1.0f} },
    };
    if (texture_ == nullptr) {
        texture_ = FontStyle::renderText(renderer, font, text_, fontColor_, Util::fColorToColor(color));
    }
    return SDL_RenderGeometry(renderer, texture_, vertex.data(), vertex.size(), nullptr, 0);
}

bool Button::contains(float x, float y) const {
    return x >= x_ && x <= x_ + w_ &&
           y >= y_ && y <= y_ + h_;
}

void Button::setFontColor(SDL_Color color) {
    fontColor_ = color;
}

void Button::destroy() {
    if (texture_ != nullptr) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
    }
}
