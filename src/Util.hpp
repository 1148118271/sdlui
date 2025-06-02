//
// Created by Administrator on 25-6-1.
//

#include <SDL3/SDL.h>

namespace Util {

    inline SDL_FColor colorToFColor(SDL_Color &color) {
        return SDL_FColor {
            .r = (float) color.r / 255.0f,
            .g = (float) color.g / 255.0f,
            .b = (float) color.b / 255.0f,
            .a = (float) color.a / 255.0f,
        };
    }

    inline SDL_FColor colorToFColor(SDL_Color color) {
        return SDL_FColor {
                .r = (float) color.r / 255.0f,
                .g = (float) color.g / 255.0f,
                .b = (float) color.b / 255.0f,
                .a = (float) color.a / 255.0f,
        };
    }

    inline SDL_Color fColorToColor(SDL_FColor &fColor) {
        return SDL_Color {
                .r = (Uint8) (fColor.r * 255),
                .g = (Uint8) (fColor.g * 255),
                .b = (Uint8) (fColor.b * 255),
                .a = (Uint8) (fColor.a * 255),
        };
    }

}
