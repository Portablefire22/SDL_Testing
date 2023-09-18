#pragma once 

GameEntity::GameEntity() {
    posX = 10;
    posY = 10;

    velX = 0;
    velY = 0;
}

void GameEntity::setValues(std::string id, uint16_t height, uint16_t width, std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> colour) {
    this->id = id;
    this->height = height;
    this->width = width;
    this->red = std::get<0>(colour);
    this->green = std::get<1>(colour);
    this->blue = std::get<2>(colour);
    this->alpha = std::get<3>(colour);
}

void EntityInput(SDL_Event& e) {
    switch (e.key.keysym.sym){
        case SDLK_UP:
            std::cout << "Testing\n";
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
