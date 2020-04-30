#include "screen.utils.h"

#include <iostream>

namespace graphics {
SDL_Surface* generateTextSurface(TTF_Font* font, int xOrigin, int yOrigin, int width, int height, const char* text,
                                 int textSize) {
    SDL_Surface* destination = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    SDL_Surface* glyph;
    SDL_Rect rect;
    int currentX = xOrigin;
    int currentY = yOrigin;
    int lineHeight = TTF_FontAscent(font);

    int advance;

    for (int i = 0; i < textSize; i++) {
        if (text[i] == '\n') {
            currentY += lineHeight;
            currentX = 0;
            continue;
        }

        glyph = TTF_RenderGlyph_Solid(font, text[i], {0xFF, 0xFF, 0xFF});
        TTF_GlyphMetrics(font, text[i], NULL, NULL, NULL, NULL, &advance);
        rect.x = currentX;  // setup x on glyph's left coordinate
        rect.y = currentY;  // setup y on  glyph's top coordinate
        SDL_BlitSurface(glyph, NULL, destination, &rect);
        currentX += advance;
    }

    delete glyph;

    return destination;
}
}  // namespace graphics