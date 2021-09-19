#include "SimpleSquare.hpp"

namespace JRay
{
    SimpleSquare::SimpleSquare(int x, int y, int w, int h) 
    : Sprite(x, y)
    {
        this->w = w;
        this->h = h;
    }

    // Point intersecting sphere
    bool SimpleSquare::intersecting(Sprite sprite) 
    {
        double sx = sprite.getX();
        double sy = sprite.getY();

        double bx = x + w;
        double bh = y + h;

        if (sx < x || sx > bx)
            return false;
        if (sy < y || sy > bh)
            return false;
            
        return true;
    }
}