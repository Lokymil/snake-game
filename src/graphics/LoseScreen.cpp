#include "LoseScreen.h"

namespace graphics {
LoseScreen::LoseScreen(Screen* pScreen) : m_pScreen(pScreen), m_isDisplay(false) {
    TTF_Init();
    m_font = TTF_OpenFont("assets/Sans.ttf", 100);
}

LoseScreen::~LoseScreen() {
    SDL_FreeSurface(m_pSurface);
    TTF_CloseFont(m_font);
    TTF_Quit();
}

bool LoseScreen::shouldRestart(int score) {
    if (!m_isDisplay) {
        display(score);
    }
    return false;
}

void LoseScreen::display(int score) {
    m_isDisplay = true;
    SDL_Color White = {255, 255, 255};
    m_pSurface = TTF_RenderText_Solid(m_font, "Game over", White);

    m_pScreen->displayMessageScreen(m_pSurface);
}

void LoseScreen::hide() {
    m_isDisplay = false;
    m_pScreen->displayGame();
}
}  // namespace graphics