//
// Created by Administrator on 25-6-1.
//

#pragma once
#include "Widget.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>


struct Size {
    int w;
    int h;
};


class Window {

private:
   std::vector<Widget*> widgets_{};
   SDL_Window* window_{};
   SDL_Renderer *renderer_{};
   SDL_Event event_{};
   SDL_Color color_ {16, 0, 16, 255};

public:
    bool show(const char *title, int x, int y, int w, int h);

    bool loadFont(const char *fontPath);

    void destroy();

    void setColor(SDL_Color color);

    void addWidget(Widget &widget);

    Size getSize();

private:
    bool draws();
};


