#include "GameLoop.h"

#include <unistd.h>

#include "InputDevice.h"

namespace game {
GameLoop::GameLoop(Player* pPlayer) : frameRate(60.0), m_pPlayer(pPlayer) { m_pInputDevice = new InputDevice(pPlayer); }

GameLoop::~GameLoop() { delete m_pInputDevice; }

void GameLoop::loop() {
    int frame = 0;
    while (hasQuit()) {
        // Cannot iterate more than 60 times per second
        // Poorly coded max framerate but must start somewhere
        usleep(1000000.0 / frameRate);
        updateInputState();
        if (frame == frameRate / m_pPlayer->speed) {
            m_pPlayer->update();
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