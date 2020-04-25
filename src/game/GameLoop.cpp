#include "GameLoop.h"

#include <unistd.h>

#include "InputDevice.h"

namespace game {
GameLoop::GameLoop(Player* pPlayer) : frameRate(60.0), m_pPlayer(pPlayer) { m_pInputDevice = new InputDevice(pPlayer); }

GameLoop::~GameLoop() { delete m_pInputDevice; }

void GameLoop::loop() {
    while (eventLoop()) {
        // Cannot iterate more than 60 times per second
        // Poorly coded max framerate but must start somewhere
        usleep(1000000.0 / frameRate);
        m_pPlayer->update();
    }
}

bool GameLoop::eventLoop() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }

        m_pInputDevice->catchInput(event);
    }

    return true;
}
}  // namespace game