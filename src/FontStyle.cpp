//
// Created by Administrator on 25-6-1.
//

#include "FontStyle.h"

FontStyle::FontStyle(TTF_Font *font, const char *text, SDL_Color color)
    : font_(font), text_(text), color_(color)
{

}

bool FontStyle::renderText(SDL_Renderer *renderer, const SDL_Vertex *vertices,
                           int numVertices, const int *indices, int numIndices) {

    SDL_Surface* surface = TTF_RenderText_Solid(font_, text_, strlen(text_), color_);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    return SDL_RenderGeometry(renderer, texture, vertices, numVertices, indices, numIndices);

}
