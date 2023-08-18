#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <string>
#include "definitions.h"
#include "Entity.cpp"

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
    void RenderObject(SDL_Renderer* renderer, GameEntity entity) {
        ClearScreen(renderer);
        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);

        SDL_RenderPresent(renderer);
    }

}

