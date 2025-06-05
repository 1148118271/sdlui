//
// Created by Administrator on 25-6-5.
//

#include "Font.h"


std::string Font::FONT_PATH_;

std::map<float, TTF_Font*> Font::CACHE_;

TTF_Font* Font::getFont(float size) {
    if (CACHE_.find(size) != CACHE_.end()) {
        return CACHE_[size];
    }
    TTF_Font *font = TTF_OpenFont(FONT_PATH_.c_str(), size);
    CACHE_[size] = font;
    return font;
}


void Font::setFontPath(const char *fontPath) {
    FONT_PATH_ = fontPath;
}

void Font::close() {
    if (CACHE_.empty()) {
        return;
    }
    for (const auto& pair : CACHE_) {
        TTF_CloseFont(pair.second);
    }
}