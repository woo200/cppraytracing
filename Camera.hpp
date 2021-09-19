#pragma once

#include <stdlib.h>
#include "Sprite.hpp"
#include "Ray.hpp"

namespace JRay
{
    class Camera : public Sprite
    {
        int resolution, offset;
    public:
        Camera(int x, int y, int resolution, int offset);
        point* render(Sprite** sprites, int spritesCnt);
        void setOffset(int offset);
        int getOffset();
        int getResolution();
    };
}   