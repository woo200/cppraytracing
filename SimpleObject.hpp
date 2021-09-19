#pragma once

#include <stdlib.h>
#include <math.h>

#include "Sprite.hpp"

namespace JRay
{
    class SimpleObject : public Sprite
    {  
        int radius;
    public:
        SimpleObject(int x, int y, int radius);
        bool intersecting(Sprite sprite);
    };
}