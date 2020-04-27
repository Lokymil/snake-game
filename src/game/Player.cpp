#include "Player.h"

namespace game {
Player::Player(graphics::Screen* screen, int thickness) : m_thickness(thickness), m_pScreen(screen), speed(10) {
    init();
}

void Player::init() {
    m_vx = 0;
    m_vy = 0;
    m_size = INITIAL_LENGTH;
    m_positions = {{m_pScreen->WINDOW_WIDTH / 2, m_pScreen->WINDOW_HEIGHT / 2}};
    drawFront();
}

const std::vector<std::array<int, 2>> Player::getPositions() { return m_positions; }

bool Player::update() {
    move();
    return isInValidPosition();
}

bool Player::hasEatenPoint(int xPoint, int yPoint) {
    int x = m_positions.front()[0];
    int y = m_positions.front()[1];
    if (xPoint == x && yPoint == y) {
        m_size++;
        return true;
    }

    return false;
}

int Player::getScore() { return m_size - INITIAL_LENGTH; }

void Player::reset() {
    for (std::array<int, 2> pos : m_positions) {
        drawSprite(pos[0], pos[1], 0, 0, 0);
    }

    init();
}

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

void Player::setDirection(int vx, int vy) {
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
            m_pScreen->setPixel(posx + x, posy + y, red, green, blue);
        }
    }

    m_pScreen->update();
}

bool Player::isInValidPosition() {
    int x = m_positions.front()[0];
    int y = m_positions.front()[1];

    if (x <= 0 || m_pScreen->WINDOW_WIDTH <= x || y <= 0 || m_pScreen->WINDOW_HEIGHT <= y) {
        return false;
    }

    for (unsigned int trailIndex = 1; trailIndex < m_positions.size(); trailIndex++) {
        if (m_positions[trailIndex][0] == x && m_positions[trailIndex][1] == y) {
            return false;
        }
    }

    return true;
}

}  // namespace game