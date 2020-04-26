#include "Point.h"

#include <cstdlib>
#include <ctime>

namespace game {
Point::Point(graphics::Screen* pScreen, int thickness) : m_pScreen(pScreen), m_thickness(thickness) { srand(time(0)); }

void Point::generate(std::vector<std::array<int, 2>> playerPositions) {
    bool isValidPosition;
    int newX;
    int newY;

    do {
        isValidPosition = true;
        newX = ((rand() % ((m_pScreen->WINDOW_WIDTH / m_thickness) - 1)) + 1) * m_thickness;
        newY = ((rand() % ((m_pScreen->WINDOW_HEIGHT / m_thickness) - 1)) + 1) * m_thickness;

        for (std::array<int, 2> positions : playerPositions) {
            if (positions[0] == newX && positions[1] == newY) {
                isValidPosition = false;
                break;
            }
        }
    } while (!isValidPosition);

    m_x = newX;
    m_y = newY;

    drawSprite(m_x, m_y, 0xFF, 0x99, 0x00);
}

void Point::drawSprite(int posx, int posy, Uint8 red, Uint8 green, Uint8 blue) {
    int leftTopPixelThickness = -m_thickness + m_thickness / 2;
    int rightBottomPixelThickness = m_thickness - m_thickness / 2;

    for (int x = leftTopPixelThickness; x < rightBottomPixelThickness; x++) {
        for (int y = leftTopPixelThickness; y < rightBottomPixelThickness; y++) {
            m_pScreen->setPixel(posx + x, posy + y, red, green, blue);
        }
    }

    m_pScreen->update();
}
}  // namespace game