//
// Created by Administrator on 25-6-5.
//

#include "Editor.h"
#include "Font.h"
#include "Util.hpp"


Editor::Editor(Window *window)
    : cursorX_(0), cursorY_(1), window_(window),
    lineStyle_({
            .x_  = 10.f,  .y_  = 0.f,  .w_  = 0.f,  .h_  = 0.f,
            .br_ = 38,    .bg_ = 40,   .bb_ = 46,   .ba_ = 255,
            .cr_ = 123,   .cg_ = 33,   .cb_ = 44,   .ca_ = 255,
            .fr_ = 168,   .fg_ = 170,  .fb_ = 175,  .fa_ = 255,
    })
{

    lines_.emplace_back("德玛西亚！");
    lines_.emplace_back("I Love You!");
}

void Editor::event(const SDL_Event &event) {
    switch (event.type) {
        // 键盘按下
        case SDL_EVENT_KEY_DOWN: {
            SDL_Log("------------- 键按下: %s", SDL_GetKeyName(event.key.key));
            break;
        }
        // 鼠标按下
        case SDL_EVENT_MOUSE_BUTTON_DOWN: {
            // 鼠标左键
            if (SDL_BUTTON_LEFT == event.button.button) {
                SDL_Log("------------- 鼠标按下 x: %f, y: %f", event.button.x, event.button.y);
                if (lineStyle_.h_ != 0.f) {
                    cursorY_ = (int) (event.button.y / lineStyle_.h_);
                    if (cursorY_ > lines_.size() - 1) {
                        cursorY_ = (int) lines_.size() - 1;
                    }
                }
            }
            // button
            SDL_Log("------------- 鼠标按下: %d", event.button.button);
        }
    }
}

bool Editor::draw(SDL_Renderer *renderer) {
    lineStyle_.y_ = 0.f;
    if (lineStyle_.w_ == 0.f) {
        Size winSize = window_->getSize();
        lineStyle_.w_ = (float)winSize.w;
    }
    SDL_Color fg = { lineStyle_.fr_, lineStyle_.fg_, lineStyle_.fb_, lineStyle_.fa_ };
    TTF_Font *font = Font::getFont(23.f);
    for (int i = 0; i < lines_.size(); ++i) {
        std::string text = lines_[i];
        SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), strlen(text.c_str()), fg);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (i == cursorY_) {
            SDL_Log("->>> w w %f", lineStyle_.w_);
            lineStyle_.h_ = (float)texture->h + 5;
            SDL_SetRenderDrawColor(renderer, lineStyle_.br_, lineStyle_.bg_, lineStyle_.bb_, lineStyle_.ba_);
            SDL_FRect rect = {0, lineStyle_.y_, lineStyle_.w_, lineStyle_.h_};
            SDL_RenderFillRect(renderer, &rect);
            SDL_RenderRect(renderer, &rect);


            // 渲染光标
            SDL_SetRenderDrawColor(renderer, 123, 33, 44, 255);
            SDL_RenderLine(renderer, (float)texture->w + lineStyle_.x_, lineStyle_.y_, (float)texture->w + lineStyle_.x_, (float)texture->h + lineStyle_.y_ + 5);
        }

        // 渲染文字
        SDL_FRect textRect = { lineStyle_.x_, lineStyle_.y_, (float)texture->w, (float )texture->h };
        SDL_RenderTexture(renderer, texture, nullptr, &textRect);

        lineStyle_.y_ += (float)texture->h + 5;
//        SDL_Log("->>> line %d y: %f", i + 1, y);
        SDL_DestroyTexture(texture);
        SDL_DestroySurface(surface);
    }
    return true;
}

void Editor::destroy() {

}

