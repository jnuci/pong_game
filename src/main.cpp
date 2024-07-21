#include "window.h"
#include "rect.h"
#include "ball.h"

void handleMovement(const Uint8 *keystates, Rect &rect1, Rect &rect2)
{
    rect1.move(keystates);
    rect2.move(keystates);
}

int main(int argc, char *argv[])
{
    Window window("Hello SDL World", 800, 600);
    Rect rect1(window, 200, 20, 299, 579, 255, 255, 255, 255, false);
    Rect rect2(window, 200, 20, 299, 0, 255, 255, 255, 255, true);

    Ball ball(window, 389, 289);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    Uint32 lastUpdate = SDL_GetTicks();
    SDL_Event event;

    while (!window.isClosed())
    {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastUpdate >= 50) {
            ball.moveBall();
            ball.collision(window, rect1, rect2);
            lastUpdate = currentTime;
            if (ball.to_close()) {
                window.close();
            }
        }
        handleMovement(keystates, rect1, rect2);
        window.pollEvents();
        rect1.draw();
        rect2.draw();
        ball.drawBall();
        window.clear();
    }

    return 0;
}