#include "definitions.h"
/*#include "Entity.cpp"
#include "Rendering.cpp"
#include "eventHandler.cpp"*/


// Rendered Window 
SDL_Window* global_Window = NULL;

// Window Surface
SDL_Surface* global_ScreenSurface = NULL;

SDL_Surface* global_HelloWorldImage = NULL;

SDL_Renderer* global_Renderer = NULL;

GameEntity entities[64];

int ArraySize = 0;

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
            //global_ScreenSurface = SDL_GetWindowSurface(global_Window);
        
            // Create a vsync hardware accellerated renderer
            global_Renderer = SDL_CreateRenderer(global_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(global_Renderer == NULL) {
                std::cout << "Renderer could not be created! " << SDL_GetError();
                success = false;
            } else {
                SDL_SetRenderDrawColor(global_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            }
        }
    }
    return success;
}

void close(){
    // Deallocate Surface
    SDL_FreeSurface(global_ScreenSurface);
    
    SDL_DestroyRenderer(global_Renderer);
    // Destroy Window
    SDL_DestroyWindow(global_Window);
    global_Window = NULL;
    global_Renderer = NULL;
    // Quit SDL
    SDL_Quit();
}


int main ( int argc, char* args[]) { 
    bool quit = false;
    if(!Init_SDL()){
        std::cout << "\nFailed to initialise!\n";
        std::cout << SDL_GetError();
    } else {
        //global_HelloWorldImage = ObjectRender::loadMedia("Image.bmp");
        if(global_HelloWorldImage != NULL){
            std::cout << "Failed to load media\n";
        } else {
            
            //SDL_BlitSurface(global_HelloWorldImage, NULL, global_ScreenSurface, NULL);
            SDL_UpdateWindowSurface(global_Window);

            // Event Handler
            SDL_Event e;

            Uint32 lastUpdate = SDL_GetTicks();

            GameEntity player;
            player.setValues("Player", 10, 10, std::make_tuple(0xFF, 0x00, 0x00, 0xFF) );
            entities[ArraySize] = player;
            ArraySize = 1;
            std::cout << "Array Size: " << ArraySize << std::endl;
            // Game loop
            while(!quit) {
                // Handle events in the queue 
                Uint64 start = SDL_GetPerformanceCounter();
                
                Uint32 current = SDL_GetTicks();
                quit = EventHandler::getEvent(e, player );

                // Calculate deltaTime in seconds
                float deltaTime = (current - lastUpdate) / 1000.0f;
                std::cout << "DeltaTime: " << std::to_string(deltaTime) << std::endl;
                ObjectRender::RenderObject(global_Renderer, entities, ArraySize);
                lastUpdate = current;

                Uint64 end = SDL_GetPerformanceCounter();
                float elapsed = (end - start ) / (float)SDL_GetPerformanceFrequency();
                std::cout << "Current FPS:" << std::to_string(1.0f/elapsed) << std::endl;
            }
        }
    }
    // Free resources and close SDL
    close();

    return 0;
}

