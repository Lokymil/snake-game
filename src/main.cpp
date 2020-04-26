#include <SDL2/SDL.h>

#include <iostream>

#include "game/GameLoop.h"
#include "game/Player.h"
#include "graphics/Screen.h"

int main() {
    graphics::Screen screen;
    // std::unique_ptr<graphics::Screen> screenPtr = new graphics::Screen();
    // auto screenPtr = std::make_unique<graphics::Screen>();

    int initValue = screen.init();

    if (initValue < 0) {
        std::cout << "Fail to init screen with code: " << initValue << std::endl;
        return initValue;
    }

    game::GameLoop game(&screen);

    game.loop();

    screen.close();

    return 0;
}