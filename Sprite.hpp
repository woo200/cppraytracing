#pragma once

#include <stdlib.h>
#include <iostream>

namespace JRay
{
    struct point
    {
        double x, y;
    };

    class Sprite
    {
    protected:
        double x, y; // Current Position
    public:
        Sprite(double x, double y);
        virtual bool intersecting(Sprite sprite);
        double getX();
        double getY();
    };
}