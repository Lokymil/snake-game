#include "Player.h"

namespace game {
Player::Player(graphics::Screen screen)
    : m_x(screen.WINDOW_WIDTH / 2), m_y(screen.WINDOW_HEIGHT / 2), m_vx(0), m_vy(0), m_screen(screen) {
    draw();
}

void Player::update() { move(); }

void Player::move() {
    if (m_vx == 0 && m_vy == 0) {
        return;
    }
    int xBeforeMove = m_x;
    int yBeforeMove = m_y;

    int nextX = m_x + m_vx * 10;
    int nextY = m_y + m_vy * 10;

    if (0 < nextX && nextX < m_screen.WINDOW_WIDTH) {
        m_x = nextX;
    }

    if (0 < nextY && nextY < m_screen.WINDOW_HEIGHT) {
        m_y = nextY;
    }

    if (m_x != xBeforeMove || m_y != yBeforeMove) {
        draw();
        clear(xBeforeMove, yBeforeMove);
    }
}

void Player::setSpeed(int vx, int vy) {
    m_vx = vx;
    m_vy = vy;
}

void Player::draw() {
    for (int x = -5; x <= 5; x++) {
        for (int y = -5; y <= 5; y++) {
            m_screen.setPixel(m_x + x, m_y + y, 0xFF, 0xFF, 0xFF);
        }
    }

    m_screen.update();
}

void Player::clear(int posx, int posy) {
    for (int x = -5; x <= 5; x++) {
        for (int y = -5; y <= 5; y++) {
            m_screen.setPixel(posx + x, posy + y, 0, 0, 0);
        }
    }

    m_screen.update();
}

}  // namespace game