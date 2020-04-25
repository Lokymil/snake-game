#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Screen.h"

namespace game {
class Player {
   private:
    int m_x;
    int m_y;
    int m_vx;
    int m_vy;
    graphics::Screen m_screen;

   public:
    Player(graphics::Screen screen);
    void setSpeed(int vx, int vy);
    void update();

   private:
    void move();
    void draw(Uint8 red, Uint8 green, Uint8 blue);
};
}  // namespace game

#endif