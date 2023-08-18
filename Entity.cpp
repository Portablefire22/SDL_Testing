#include <cstdint>
#include <string>

#pragma once 
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

        void render();
        void move();
        void initialise();

    private:
        uint16_t posX;
        uint16_t posY;
};
