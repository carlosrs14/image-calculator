#include <opencv2/opencv.hpp>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Mi ventana",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        0
    );

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}