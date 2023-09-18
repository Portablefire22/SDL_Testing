
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include <cstddef>
#include <cstdint>
#include <stdio.h>
#include <format>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <tuple>
#include <ostream>

#pragma once

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FPS_CAP 144
#define TICKS_PER_FRAME 1000/FPS_CAP

void setValues();


class GameEntity {
    public:
        std::string id;
        uint16_t height;
        uint16_t width;
        // Colour values
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
        GameEntity();
        void render();
        void EntityInput(SDL_Event& );
        void setValues(std::string id, uint16_t height, uint16_t width, std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> colour);
        uint16_t posX, posY;
        int8_t velX, velY;
};
GameEntity::GameEntity() {
    posX = 10;
    posY = 10;

    velX = 0;
    velY = 0;
}
namespace EventHandler {
    bool getEvent(SDL_Event e, GameEntity& player){}
}

void GameEntity::setValues(std::string id, uint16_t height, uint16_t width, std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> colour) {}

void EntityInput(SDL_Event& e) {}

namespace ObjectRender {
    SDL_Surface* loadMedia(std::string textureName) {}
    void ClearScreen(SDL_Renderer* renderer) {}
    void RenderObject(SDL_Renderer* renderer, GameEntity entities[64], int ArraySize) {}
}

