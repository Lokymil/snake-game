#include "screen.utils.h"

namespace graphics {
SDL_Surface* generateTextSurface(TTF_Font* font, int xOrigin, int yOrigin, int width, int height, std::string text) {
    SDL_Surface* destination = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    int currentX = xOrigin;
    int currentY = yOrigin;
    int lineHeight = TTF_FontAscent(font);

    SDL_Rect destinationRect;
    SDL_Surface* glyphSurface;
    SDL_Surface* lineSurface;
    int advance;
    std::string line;
    int delimiterIndex;

    while (text.size() > 0) {
        lineSurface = SDL_CreateRGBSurfaceWithFormat(0, width, lineHeight, 32, SDL_PIXELFORMAT_RGBA32);
        delimiterIndex = text.find('\n');
        if (delimiterIndex > 0) {
            line = text.substr(0, delimiterIndex);
            text.erase(0, delimiterIndex + 1);
        } else {
            line = text;
            text.erase(0, text.size());
        }

        for (unsigned int i = 0; i < line.size(); i++) {
            glyphSurface = TTF_RenderGlyph_Solid(font, line[i], {0xFF, 0xFF, 0xFF});
            TTF_GlyphMetrics(font, line[i], NULL, NULL, NULL, NULL, &advance);
            destinationRect.x = currentX;  // setup x on glyph's left coordinate
            destinationRect.y = 0;         // setup y on  glyph's top coordinate
            SDL_BlitSurface(glyphSurface, NULL, lineSurface, &destinationRect);
            currentX += advance;
            SDL_FreeSurface(glyphSurface);
        }

        currentY += lineHeight;
        int remainingSpace = width - currentX;
        int leftPadding = remainingSpace / 2;
        destinationRect.x = leftPadding;
        destinationRect.y = currentY;
        SDL_BlitSurface(lineSurface, NULL, destination, &destinationRect);

        currentX = 0;

        SDL_FreeSurface(lineSurface);
    }

    return destination;
}
}  // namespace graphics