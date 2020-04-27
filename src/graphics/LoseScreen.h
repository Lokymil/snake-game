#ifndef LOSE_SCREEN_H_
#define LOSE_SCREEN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Screen.h"

namespace graphics {
class LoseScreen {
   private:
    Screen* m_pScreen;
    SDL_Surface* m_pSurface;
    TTF_Font* m_font;
    bool m_isDisplay;

   public:
    LoseScreen(Screen* pScreen);
    ~LoseScreen();
    bool shouldRestart(int score);

   private:
    void display(int score);
    bool hasClickRestart();
    void hide();
};
}  // namespace graphics

#endif