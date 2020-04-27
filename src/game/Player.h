#ifndef PLAYER_H_
#define PLAYER_H_

#include <array>
#include <vector>

#include "../graphics/Screen.h"

namespace game {
class Player {
   private:
    const int INITIAL_LENGTH = 3;
    int m_thickness;
    std::vector<std::array<int, 2>> m_positions;
    unsigned int m_size = INITIAL_LENGTH;
    int m_vx;
    int m_vy;
    graphics::Screen* m_pScreen;

   public:
    int speed;

   public:
    Player(graphics::Screen* screen, int thickness);
    void setDirection(int vx, int vy);
    const std::vector<std::array<int, 2>> getPositions();
    bool update();
    bool hasEatenPoint(int xPoint, int yPoint);
    int getScore();
    void reset();

   private:
    void init();
    void move();
    void drawFront();
    void clearRear();
    void drawSprite(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool isInValidPosition();
};
}  // namespace game

#endif