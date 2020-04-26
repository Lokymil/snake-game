#ifndef INPUT_DEVICE_H_
#define INPUT_DEVICE_H_

#include <SDL2/SDL.h>

#include "Player.h"

namespace game {
class InputDevice {
   private:
    int* m_moveVector;
    Player* m_pPlayer;

   public:
    InputDevice(Player* pPlayer);
    ~InputDevice();
    void updateState();

   private:
    void updateMoveVector(const Uint8* keyboardState);
};
}  // namespace game

#endif