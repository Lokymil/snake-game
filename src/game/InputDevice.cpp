#include "InputDevice.h"

namespace game {
InputDevice::InputDevice(Player* pPlayer) : m_pPlayer(pPlayer) {
    m_moveVector = new int[2];
    m_moveVector[0] = 0;
    m_moveVector[1] = 0;
}

InputDevice::~InputDevice() { delete[] m_moveVector; }

void InputDevice::catchInput(SDL_Event input) {
    if (input.type != SDL_KEYDOWN && input.type != SDL_KEYUP) {
        return;
    }

    updateMoveVector(input.key.keysym.sym, input.type == SDL_KEYDOWN);

    m_pPlayer->setSpeed(m_moveVector[0], m_moveVector[1]);
}

void InputDevice::updateMoveVector(int key, bool isKeyDown) {
    switch (key) {
        case SDLK_UP:
            m_moveVector[1] = isKeyDown ? -1 : 0;
            break;
        case SDLK_DOWN:
            m_moveVector[1] = isKeyDown ? 1 : 0;
            break;
        case SDLK_RIGHT:
            m_moveVector[0] = isKeyDown ? 1 : 0;
            break;
        case SDLK_LEFT:
            m_moveVector[0] = isKeyDown ? -1 : 0;
            break;
    }
};
}  // namespace game