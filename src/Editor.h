//
// Created by Administrator on 25-6-5.
//

#pragma once

#include <vector>
#include <string>
#include <optional>
#include "Widget.h"
#include "Window.h"

struct LineStyle {
    // 位置
    float x_;
    float y_;
    // 宽高
    float w_;
    float h_;

    // 背景颜色
    Uint8 br_;
    Uint8 bg_;
    Uint8 bb_;
    Uint8 ba_;

    // 光标颜色
    Uint8 cr_;
    Uint8 cg_;
    Uint8 cb_;
    Uint8 ca_;

    // 字体颜色
    Uint8 fr_;
    Uint8 fg_;
    Uint8 fb_;
    Uint8 fa_;

};


class Editor : public Widget {

private:
    std::vector<std::string> lines_;
    int cursorX_;
    int cursorY_;
    Window *window_;
    LineStyle lineStyle_;


public:

    explicit Editor(Window *window);

    void event(const SDL_Event &e) override;

    bool draw(SDL_Renderer *renderer) override;

    void destroy() override;

};

