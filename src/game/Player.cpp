#include "Player.h"

namespace game {
Player::Player(graphics::Screen screen) : m_thickness(10), m_size(3), m_vx(0), m_vy(0), m_screen(screen) {
    m_positions = {{screen.WINDOW_WIDTH / 2, screen.WINDOW_HEIGHT / 2}};
    drawFront();
}

void Player::update() { move(); }

void Player::move() {
    if (m_vx == 0 && m_vy == 0) {
        return;
    }
    int x = m_positions.front()[0];
    int y = m_positions.front()[1];

    int nextX = x + m_vx * m_thickness;
    int nextY = y + m_vy * m_thickness;

    m_positions.insert(m_positions.begin(), {nextX, nextY});

    drawFront();
    clearRear();
}

void Player::setSpeed(int vx, int vy) {
    m_vx = vx;
    m_vy = vy;
}

void Player::drawFront() {
    int posx = m_positions.front()[0];
    int posy = m_positions.front()[1];

    drawSprite(posx, posy, 0xFF, 0xFF, 0xFF);
}

void Player::clearRear() {
    if (m_positions.size() <= m_size) {
        return;
    }

    int posx = m_positions.back()[0];
    int posy = m_positions.back()[1];
    drawSprite(posx, posy, 0, 0, 0);

    m_positions.pop_back();
}

void Player::drawSprite(int posx, int posy, Uint8 red, Uint8 green, Uint8 blue) {
    int leftTopPixelThickness = -m_thickness + m_thickness / 2;
    int rightBottomPixelThickness = m_thickness - m_thickness / 2;

    for (int x = leftTopPixelThickness; x < rightBottomPixelThickness; x++) {
        for (int y = leftTopPixelThickness; y < rightBottomPixelThickness; y++) {
            m_screen.setPixel(posx + x, posy + y, red, green, blue);
        }
    }

    m_screen.update();
}

}  // namespace game