#pragma once

#include <stdlib.h>
#include <math.h>

#include "Sprite.hpp"

namespace JRay
{
    class SimpleSquare : public Sprite
    {  
        int w, h;
    public:
        SimpleSquare(int x, int y, int w, int h);
        bool intersecting(Sprite sprite);
    };
}