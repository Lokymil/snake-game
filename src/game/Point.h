#ifndef POINT_H_
#define POINT_H_

#include <array>
#include <vector>

#include "../graphics/Screen.h"

namespace game {
class Point {
   public:
    int m_x;
    int m_y;

   private:
    graphics::Screen* m_pScreen;
    int m_thickness;

   public:
    Point(graphics::Screen* pScreen, int thickness);
    void generate(std::vector<std::array<int, 2>> playerPositions);
    void drawSprite(int posx, int posy, Uint8 red, Uint8 green, Uint8 blue);
};
}  // namespace game

#endif