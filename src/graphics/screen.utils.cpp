#include "screen.utils.h"

#include <iostream>

namespace graphics {
SDL_Surface* generateTextSurface(TTF_Font* font, int xOrigin, int yOrigin, int width, int height, std::string text) {
    SDL_Surface* destination = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    SDL_Surface* textSurface;
    SDL_Rect rect;
    int currentX = xOrigin;
    int currentY = yOrigin;
    int lineHeight = TTF_FontAscent(font);

    int advance;

    for (unsigned int i = 0; i < text.size(); i++) {
        if (text[i] == '\n') {
            currentY += lineHeight;
            currentX = 0;
            continue;
        }

        textSurface = TTF_RenderGlyph_Solid(font, text[i], {0xFF, 0xFF, 0xFF});
        TTF_GlyphMetrics(font, text[i], NULL, NULL, NULL, NULL, &advance);
        rect.x = currentX;  // setup x on glyph's left coordinate
        rect.y = currentY;  // setup y on  glyph's top coordinate
        SDL_BlitSurface(textSurface, NULL, destination, &rect);
        currentX += advance;
    }

    delete textSurface;

    return destination;
}
}  // namespace graphics