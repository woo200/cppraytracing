#pragma once

#include <stdlib.h>
#include <math.h>

#include "Sprite.hpp"

namespace JRay
{
    class Ray : public Sprite
    { 
        double angle;
    public:
        Ray(double x, double y, double angle);
        void march();
        double getAngle();
    };
}