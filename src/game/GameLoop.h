#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include <SDL2/SDL.h>

#include "InputDevice.h"
#include "Player.h"

namespace game {
class GameLoop {
   private:
    double frameRate;
    InputDevice* m_pInputDevice;
    Player* m_pPlayer;
    SDL_Event event;

   public:
    GameLoop(Player* pPlayer);
    ~GameLoop();
    void loop();

   private:
    bool hasQuit();
    void updateInputState();
};
}  // namespace game

#endif