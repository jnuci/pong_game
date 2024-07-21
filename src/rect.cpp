#include "rect.h"

Rect::Rect(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a, bool top) : Window(window), w(w), h(h), x(x), y(y), r(r), g(g), b(b), a(a), top(top)
{
}

void Rect::draw() const
{
    SDL_Rect rect;

    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

void Rect::move(const Uint8 *keystates)
{
    if (!top)
    {
        if (keystates[SDL_SCANCODE_LEFT])
        {
            if (x > 0)
            {
                x -= 5;
            }
        }
        if (keystates[SDL_SCANCODE_RIGHT])
        {
            if (x + w < width)
            {
                x += 5;
            }
        }
    }
    else
    {
        if (keystates[SDL_SCANCODE_A])
        {
            if (x > 0)
            {
                x -= 5;
            }
        }
        if (keystates[SDL_SCANCODE_D])
        {
            if (x + w < width)
            {
                x += 5;
            }
        }
    }
}

int Rect::get_x() const {
    return x;
}

int Rect::get_y() const {
    return y;
}
