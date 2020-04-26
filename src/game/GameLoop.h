#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include <SDL2/SDL.h>

#include "../graphics/Screen.h"
#include "InputDevice.h"
#include "Player.h"
#include "Point.h"

namespace game {
class GameLoop {
   private:
    double frameRate;
    InputDevice* m_pInputDevice;
    Player* m_pPlayer;
    Point* m_pPoint;
    SDL_Event event;

   public:
    GameLoop(graphics::Screen* screen);
    ~GameLoop();
    void loop();

   private:
    bool hasQuit();
    void updateInputState();
};
}  // namespace game

#endif