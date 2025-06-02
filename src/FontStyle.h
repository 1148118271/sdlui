//
// Created by Administrator on 25-6-1.
//

#pragma once
#include <SDL3_ttf/SDL_ttf.h>


class FontStyle {

public:
    static SDL_Texture* renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
};

