//
// Created by Administrator on 25-6-5.
//

#pragma once

#include <map>
#include <string>
#include "SDL3_ttf/SDL_ttf.h"

class Font {



private:

    static std::string FONT_PATH_;

    static std::map<float, TTF_Font*> CACHE_;

public:

    static TTF_Font* getFont(float size);

    static void setFontPath(const char *fontPath);

    static void close();

};

