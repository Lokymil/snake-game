#include "GameLoop.h"

#include <unistd.h>

namespace game {
GameLoop::GameLoop(graphics::Screen* pScreen) : frameRate(60.0) {
    int thickness = 20;
    m_pLoseScreen = new graphics::LoseScreen(pScreen);
    m_pPlayer = new Player(pScreen, thickness);
    m_pInputDevice = new InputDevice(m_pPlayer);
    m_pPoint = new Point(pScreen, thickness);
}

GameLoop::~GameLoop() {
    delete m_pLoseScreen;
    delete m_pPoint;
    delete m_pInputDevice;
    delete m_pPlayer;
}

void GameLoop::loop() {
    int framePlayed = 0;
    bool lost = false;

    m_pPoint->generate(m_pPlayer->getPositions());

    while (!hasQuit()) {
        // Cannot iterate more than 60 times per second
        // Poorly coded max framerate but must start somewhere
        usleep(1000000.0 / frameRate);
        if (!lost) {
            lost = runGame(framePlayed);
        } else {
            lost = loseScreen();
        }
    }
}

bool GameLoop::hasQuit() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        }
    }

    return false;
}

void GameLoop::updateInputState() { m_pInputDevice->updateState(); }

bool GameLoop::runGame(int& framePlayed) {
    bool lost;
    updateInputState();
    if (framePlayed == frameRate / m_pPlayer->speed) {
        lost = !m_pPlayer->update();
        if (m_pPlayer->hasEatenPoint(m_pPoint->m_x, m_pPoint->m_y)) {
            m_pPoint->generate(m_pPlayer->getPositions());
        }
        framePlayed = 0;
    } else {
        framePlayed += 1;
    }

    return lost;
}

bool GameLoop::loseScreen() { return !m_pLoseScreen->shouldRestart(m_pPlayer->getScore()); }
}  // namespace game