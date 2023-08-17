#include <SDL2/SDL.h>

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL,
};

namespace ManageInput {

}

namespace EventHandler {
    bool getEvent(SDL_Event e){
        while (SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT) {
                return true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym){
                    case SDLK_UP:
                        break;
                    case SDLK_DOWN:
                        break;
                    case SDLK_LEFT:
                        break;
                    case SDLK_RIGHT:
                        break;
                    default:
                        break;
                }
            }

        }
        return false;
    }
}
