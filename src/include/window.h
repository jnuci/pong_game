#pragma once

#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void pollEvents();
    void clear() const;
    void close();
    bool isClosed() const { return closed; }

private:
    bool init();

private:
    std::string title;


    SDL_Window *window = nullptr;

protected:
    bool closed = false;
    SDL_Renderer *renderer = nullptr;
    int width = 800;
    int height = 600;
};