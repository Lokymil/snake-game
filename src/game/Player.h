#ifndef PLAYER_H_
#define PLAYER_H_

#include <array>
#include <vector>

#include "../graphics/Screen.h"

namespace game {
class Player {
   private:
    int m_thickness;
    std::vector<std::array<int, 2>> m_positions;
    unsigned int m_size;
    int m_vx;
    int m_vy;
    graphics::Screen m_screen;

   public:
    int speed;

   public:
    Player(graphics::Screen screen);
    void setDirection(int vx, int vy);
    bool update();

   private:
    void move();
    void drawFront();
    void clearRear();
    void drawSprite(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool isInValidPosition();
};
}  // namespace game

#endif