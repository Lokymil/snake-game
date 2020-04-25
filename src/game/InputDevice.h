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
    void catchInput(SDL_Event event);

   private:
    void updateMoveVector(int key, bool isKeyDown);
};
}  // namespace game

#endif