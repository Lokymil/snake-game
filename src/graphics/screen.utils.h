#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace graphics {
SDL_Surface* generateTextSurface(TTF_Font* font, int xOrigin, int yOrigin, int width, int height, const char* text,
                                 int textSize);
}