
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <stdio.h>
#include <format>
#include <SDL2/SDL.h>
#include <iostream>
#include "Rendering.h"
#include "eventHandler.cpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FPS_CAP 144
#define TICKS_PER_FRAME 1000/FPS_CAP

// Rendered Window 
SDL_Window* global_Window = NULL;

// Window Surface
SDL_Surface* global_ScreenSurface = NULL;

SDL_Surface* global_HelloWorldImage = NULL;


// Initialise SDL 
bool Init_SDL() {
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialised. SDL_Error: \n";
    } else {
        // Create the window 
        global_Window = SDL_CreateWindow("SDL Testing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(global_Window == NULL) {
            std::cout << "Window could not be created SDL_Error: \n";
            success = false;
        } else {
            // Get Window Surface 
            global_ScreenSurface = SDL_GetWindowSurface(global_Window);
        }
    }
    return success;
}

void close(){
    // Deallocate Surface
    SDL_FreeSurface(global_ScreenSurface);

    // Destroy Window
    SDL_DestroyWindow(global_Window);
    global_Window = NULL;

    // Quit SDL
    SDL_Quit();
}

bool loadMedia() {
    bool success = true; 

    global_HelloWorldImage = SDL_LoadBMP("Image.bmp");
    if(global_HelloWorldImage == NULL) {
        std::cout << "Unable to load the image\n";
        std::cout << SDL_GetError() << "\n";
        success = false;
    }
    return success;
}

int main ( int argc, char* args[]) { 
    bool quit = false;
    if(!Init_SDL()){
        std::cout << "Failed to initialise!\n";
    } else {
        if(!loadMedia()){
            std::cout << "Failed to load media\n";
        } else {
            
            SDL_BlitSurface(global_HelloWorldImage, NULL, global_ScreenSurface, NULL);
            SDL_UpdateWindowSurface(global_Window);

            // Event Handler
            SDL_Event e;

            while(!quit) {
                // Handle events in the queue 
                quit = EventHandler::getEvent(e);
            }
        }
    }
    // Free resources and close SDL
    close();

    return 0;
}

