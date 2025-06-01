//
// Created by Administrator on 25-6-1.
//

#pragma once
#include "Widget.h"

#include <vector>

class Window {

private:
   std::vector<Widget*> widgets_{};
   SDL_Window* window_{};
   SDL_Renderer *renderer_{};
   SDL_Event event_{};


public:
    bool show(const char *title, int x, int y, int w, int h);
    void destroy();

    void addWidget(Widget &widget);

private:

    bool draws();

};


