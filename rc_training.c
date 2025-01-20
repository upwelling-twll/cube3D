#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

// 2D World Map (simple layout)
int worldMap[mapWidth][mapHeight] =
{
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
    {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
    {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
    {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
    {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
    {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
    {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

// Texture array for 4 textures
unsigned int texture[4][texWidth * texHeight]; 

// Screen buffer
unsigned int buffer[screenHeight][screenWidth];

// SDL window and renderer
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// Function to generate basic textures (for 4 textures only)
void generateTextures() {
    for (int x = 0; x < texWidth; x++) {
        for (int y = 0; y < texHeight; y++) {
            // Generate a simple gradient texture
            texture[0][y * texWidth + x] = (x * 256 / texWidth) << 16 | (y * 256 / texHeight) << 8; // Gradient texture
            
            // Checkerboard pattern texture
            texture[1][y * texWidth + x] = ((x / 8 + y / 8) % 2 == 0) ? 0xFFFFFF : 0x000000; // Checkerboard
            
            // Stripe pattern texture
            texture[2][y * texWidth + x] = (x % 16 < 8) ? 0xFF0000 : 0x0000FF; // Red-Blue stripes
            
            // Flat color texture
            texture[3][y * texWidth + x] = 0x00FF00; // Green color
        }
    }
}

// Function to initialize SDL
int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

// Function to clear the screen buffer
void clearBuffer() {
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            buffer[y][x] = 0; // Set every pixel to black initially
        }
    }
}

// Function to draw the screen buffer to the window
void drawBuffer() {
    SDL_RenderClear(renderer);

    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            unsigned int color = buffer[y][x];
            SDL_SetRenderDrawColor(renderer, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_RenderPresent(renderer);
}

int main() {
    // Initialize SDL and textures
    if (!init()) {
        return 1;
    }

    generateTextures();

    // Main loop
    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear the screen buffer
        clearBuffer();

        // Example raycasting (you would need to add your raycasting logic here)
        for (int x = 0; x < screenWidth; x++) {
            // Simple raycasting logic (you should replace this with real raycasting)
            for (int y = 0; y < screenHeight; y++) {
                int textureID = worldMap[x / texWidth][y / texHeight] % 4; // Choose one of the 4 textures
                buffer[y][x] = texture[textureID][(y % texHeight) * texWidth + (x % texWidth)];
            }
        }

        // Draw the buffer
        drawBuffer();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
