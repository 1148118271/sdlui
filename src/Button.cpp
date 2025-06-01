//
// Created by Administrator on 25-5-31.
//

#include <array>
#include "Button.h"


Button::Button(float x, float y, float w, float h, SDL_Renderer *renderer)
    : x_(x), y_(y), w_(w), h_(h), renderer_(renderer)
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
//    SDL_Vertex vertex[6] = {
//            {x_, y_},
//            {x_, y_ + h_},
//            {x_ + w_, y_},
//
//            {x_, y_ + h_},
//            {x_ + w_, y_},
//            {x_ + w_, y_ + h_},
//    }

    SDL_FColor color = normalColor_;
    if (pressed) color = pressedColor_;
    else if (hovered) color = hoverColor_;

    std::array<SDL_Vertex, 6> vertex = {
        SDL_Vertex{ .position = {x_, y_},               .color = {.r=0.88, .g=0.5, .b=0.5, .a = 1}, .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_, y_ + h_},          .color = {.r=0.88, .g=0.5, .b=0.5, .a = 1}, .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_},          .color = {.r=0.88, .g=0.5, .b=0.5, .a = 1}, .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_, y_ + h_},          .color = {255, 144, 255, 255}, .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_},          .color = {255, 144, 255, 255}, .tex_coord = {0.0f, 0.0f} },
        SDL_Vertex{ .position = {x_ + w_, y_ + h_},     .color = {255, 144, 255, 255}, .tex_coord = {0.0f, 0.0f} },
    };

    bool rst = SDL_RenderGeometry(renderer, nullptr, vertex.data(), vertex.size(), nullptr, 0);

    SDL_Log("SDL_RenderGeometry failed: %s", SDL_GetError());








//    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//    SDL_RenderFillRect(renderer, &rect_);
//    SDL_RenderPresent(renderer);
}

bool Button::contains(float x, float y) const {
    return x >= x_ && x <= x_ + w_ &&
           y >= y_ && y <= y_ + h_;
}
