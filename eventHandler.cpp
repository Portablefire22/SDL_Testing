

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
    bool getEvent(SDL_Event e, GameEntity& player){
        while (SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT) {
                return true;
            } else if (e.type == SDL_KEYDOWN) {
               // Player handles keypresses 
               player.EntityInput(e);
            }

        }
        return false;
    }
}
