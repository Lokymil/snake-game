#include "LoseScreen.h"

#include <iostream>
#include <string>

#include "screen.utils.h"

namespace graphics {
LoseScreen::LoseScreen(Screen* pScreen) : m_pScreen(pScreen), m_isDisplay(false) {
    TTF_Init();
    m_pFont = TTF_OpenFont("assets/Sans.ttf", 100);
}

LoseScreen::~LoseScreen() {
    SDL_FreeSurface(m_pSurface);
    TTF_CloseFont(m_pFont);
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

    std::string loseSentence = "Game over\nScore: " + std::to_string(score);

    // m_pSurface = TTF_RenderText_Solid(m_font, cstr, White);
    m_pSurface = generateTextSurface(m_pFont, 0, 0, m_pScreen->WINDOW_WIDTH, m_pScreen->WINDOW_HEIGHT, loseSentence);

    m_pScreen->displayMessageScreen(m_pSurface);
}

void LoseScreen::hide() {
    m_isDisplay = false;
    m_pScreen->displayGame();
}
}  // namespace graphics