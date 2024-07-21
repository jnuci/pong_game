#include "ball.h"
#include "rect.h"
#include <iostream>
#include <random>
#include <cmath>

Ball::Ball(const Window &window, int ball_x, int ball_y) : Window(window), ball_x(ball_x), ball_y(ball_y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-15.0, 15.0);
    std::uniform_int_distribution<> choice_dis(0, 1);

    v_x = dis(gen);
    while (v_x == 0.0) {
        v_x = dis(gen);
    }

    float magnitude = sqrt(450.0f);
    float y_squared = 450.0f - v_x * v_x;
    v_y = sqrt(y_squared);

    int choice = choice_dis(gen);
    v_y = (choice == 0) ? v_y : -1 *  v_y;
}

void Ball::drawBall() const
{
    SDL_Rect rect;

    rect.w = 20;
    rect.h = 20;
    rect.x = ball_x;
    rect.y = ball_y;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::moveBall()
{
    ball_x += v_x;
    ball_y += v_y;
}

void Ball::collision(Window &window, const Rect &rect1, const Rect &rect2)
{
    int x_1 = rect1.get_x();
    int y_1 = rect1.get_y();
    int x_2 = rect2.get_x();
    int y_2 = rect2.get_y();

    if (ball_y + 20 >= y_1 && (ball_x >= x_1 - 20 && ball_x <= x_1 + 200))
    {
        v_y *= -1;
    }
    else if (ball_y - 19 <= y_2 && (ball_x >= x_2 - 20 && ball_x <= x_2 + 200))
    {
        v_y *= -1;
    }
    if (ball_x <= 0 || ball_x >= 779) {
        v_x *= -1;
    }
    if (ball_y <= 0 || ball_y >= 579) {
        close = true;
    }
}

bool Ball::to_close()
{
    return close;
}