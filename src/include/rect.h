#pragma once

#include "window.h"

class Rect : public Window
{
public:
    Rect(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a, bool top);

    void draw() const;
    void move(const Uint8 *keystates);
    int get_x() const;
    int get_y() const;

private:
    int w, h;
    int x, y;
    int r, g, b, a;
    bool top;
};