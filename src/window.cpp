#include "window.h"
#include <sdl2/SDL.h>
#include <iostream>

Window::Window(const std::string &title, int width, int height) : title(title), width(width), height(height)
{
    closed = !init();
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
    {
        std::cerr << "Failed to init SDL.\n";
        return 0;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr)
    {
        std::cerr << "Failed to create window.\n";
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        std::cerr << "Failed to create renderer.\n";
        return 0;
    }

    return true;
}

void Window::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            closed = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                closed = true;
                break;
            }
        defualt:
            break;
        }
    }
}

void Window::clear() const
{
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 71, 171, 255);
    SDL_RenderClear(renderer);
}

void Window::close()
{
    closed = true;
}