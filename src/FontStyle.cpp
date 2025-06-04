//
// Created by Administrator on 25-6-1.
//

#include "FontStyle.h"

SDL_Texture* FontStyle::renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg) {
    SDL_Surface *surface = TTF_RenderText_Shaded(font, text, strlen(text), fg, bg);
    SDL_Texture *rst = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    return rst;
}
