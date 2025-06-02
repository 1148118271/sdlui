//
// Created by Administrator on 25-6-1.
//

#pragma once
#include <SDL3_ttf/SDL_ttf.h>

class FontStyle {

private:
    TTF_Font *font_;
    SDL_Color color_;
    const char* text_;


public:
    explicit FontStyle(TTF_Font *font, const char *text, SDL_Color color = {0, 0, 0});

    bool renderText(SDL_Renderer *renderer, const SDL_Vertex *vertices,
                    int numVertices, const int *indices, int numIndices);


};

