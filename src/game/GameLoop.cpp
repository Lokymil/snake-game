#include "GameLoop.h"

#include <unistd.h>

namespace game {
GameLoop::GameLoop(graphics::Screen* pScreen) : frameRate(60.0) {
    int thickness = 10;
    m_pPlayer = new Player(pScreen, thickness);
    m_pInputDevice = new InputDevice(m_pPlayer);
    m_pPoint = new Point(pScreen, thickness);
}

GameLoop::~GameLoop() {
    delete m_pPoint;
    delete m_pInputDevice;
    delete m_pPlayer;
}

void GameLoop::loop() {
    int frame = 0;
    bool lost = false;

    m_pPoint->generate(m_pPlayer->getPositions());

    while (hasQuit() && !lost) {
        // Cannot iterate more than 60 times per second
        // Poorly coded max framerate but must start somewhere
        usleep(1000000.0 / frameRate);
        updateInputState();
        if (frame == frameRate / m_pPlayer->speed) {
            lost = !m_pPlayer->update();
            if (m_pPlayer->hasEatenPoint(m_pPoint->m_x, m_pPoint->m_y)) {
                m_pPoint->generate(m_pPlayer->getPositions());
            }
            frame = 0;
        } else {
            frame++;
        }
    }
}

bool GameLoop::hasQuit() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }

    return true;
}

void GameLoop::updateInputState() { m_pInputDevice->updateState(); }
}  // namespace game