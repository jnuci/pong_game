#pragma once

#include "window.h"
#include "rect.h"

class Ball : public Window 
{
public:
    Ball(const Window &window, int ball_x, int ball_y);

    void drawBall() const;
    void moveBall();
    void collision(Window &window, const Rect &rect1, const Rect &rect2);
    bool to_close();

private:
    int ball_x, ball_y;
    float v_x, v_y;
    bool close = false;
};