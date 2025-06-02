//
// Created by Administrator on 25-6-1.
//

#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class Widget {

public:
    virtual void event(const SDL_Event &e) = 0;

    virtual bool draw(SDL_Renderer *renderer, TTF_Font *font) = 0;

};

