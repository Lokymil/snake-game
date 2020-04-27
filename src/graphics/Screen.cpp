#include "Screen.h"

namespace graphics {
int Screen::init() {
    const int initCode = SDL_Init(SDL_INIT_VIDEO);
    if (initCode < 0) {
        return -1;
    }

    m_window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
        SDL_Quit();
        return -2;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return -3;
    }

    m_texture =
        SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (m_texture == NULL) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return -4;
    }

    m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];
    memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

    return 0;
}

void Screen::displayMessageScreen(SDL_Surface* messageSurface) {
    m_message_texture = SDL_CreateTextureFromSurface(m_renderer, messageSurface);

    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_message_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::displayGame() { SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32)); }

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) {
        return;
    }

    Uint32 color = 0;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;  // unused alpha

    m_buffer[y * WINDOW_WIDTH + x] = color;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::close() {
    delete[] m_buffer;
    SDL_DestroyTexture(m_message_texture);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
}  // namespace graphics