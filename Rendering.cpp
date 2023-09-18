
namespace ObjectRender {
    SDL_Surface* loadMedia(std::string textureName) {
        bool success = true; 

        SDL_Surface* imageSurface = SDL_LoadBMP(textureName.c_str());
        if(imageSurface == NULL) {
            std::cout << "Unable to load " << textureName << "\n";
            std::cout << SDL_GetError() << "\n";
            success = false;
        }
        return imageSurface;
    }

    void ClearScreen(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
    }

    // Render an object with given paramenters 

    // Testing with a placrholder rectangle
    void RenderObject(SDL_Renderer* renderer, GameEntity entities[64], int ArraySize) {
        ClearScreen(renderer);
        std::cout << "Array Size: " << ArraySize << std::endl;
        for(int i = 0; i < ArraySize; i++){
            // X position, Y position, width, height
            std::cout << entities[i].width << std::endl;
            SDL_Rect fillRect = {entities[i].posX, entities[i].posY, entities[i].width, entities[i].height};
            SDL_SetRenderDrawColor(renderer, entities[i].red,entities[i].green,entities[i].blue,entities[i].alpha);
            SDL_RenderFillRect(renderer, &fillRect);
            std::cout << "Rendering: " << entities[i].id << std::endl;
        }
        SDL_RenderPresent(renderer);
    }

}

