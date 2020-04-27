#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace graphics {
class Screen {
   public:
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 600;

   private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    SDL_Texture* m_message_texture;
    Uint32* m_buffer;

   public:
    Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {}
    int init();
    void displayMessageScreen(SDL_Surface* messageSurface);
    void displayGame();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void close();
};
}  // namespace graphics

#endif