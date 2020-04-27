#include "InputDevice.h"

namespace game {
InputDevice::InputDevice(Player* pPlayer) : m_pPlayer(pPlayer) {
    m_moveVector = new int[2];
    m_moveVector[0] = 0;
    m_moveVector[1] = 0;
}

InputDevice::~InputDevice() { delete[] m_moveVector; }

void InputDevice::updateState() {
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    updateMoveVector(keyboardState);

    m_pPlayer->setDirection(m_moveVector[0], m_moveVector[1]);
}

void InputDevice::updateMoveVector(const Uint8* keyboardState) {
    if (keyboardState[SDL_SCANCODE_UP] && m_moveVector[1] != 1) {
        m_moveVector[0] = 0;
        m_moveVector[1] = -1;
    }

    if (keyboardState[SDL_SCANCODE_DOWN] && m_moveVector[1] != -1) {
        m_moveVector[0] = 0;
        m_moveVector[1] = 1;
    }

    if (keyboardState[SDL_SCANCODE_RIGHT] && m_moveVector[0] != -1) {
        m_moveVector[0] = 1;
        m_moveVector[1] = 0;
    }

    if (keyboardState[SDL_SCANCODE_LEFT] && m_moveVector[0] != 1) {
        m_moveVector[0] = -1;
        m_moveVector[1] = 0;
    }
};
}  // namespace game