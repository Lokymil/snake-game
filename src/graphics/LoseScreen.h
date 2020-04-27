#ifndef LOSE_SCREEN_H_
#define LOSE_SCREEN_H_

#include "Screen.h"

namespace graphics {
class LoseScreen {
   private:
    Screen* m_pScreen;

   public:
    LoseScreen(Screen* pScreen);
};
}  // namespace graphics

#endif