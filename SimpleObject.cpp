#include "SimpleObject.hpp"

namespace JRay
{
    SimpleObject::SimpleObject(int x, int y, int radius) 
    : Sprite(x, y)
    {
        this->radius = radius;
    }

    // Point intersecting sphere
    bool SimpleObject::intersecting(Sprite sprite) 
    {
        double sx = sprite.getX();
        double sy = sprite.getY();

        float d = sqrt(pow(sx - x, 2) +
                       pow(sy - y, 2));
        
        return d <= radius;
    }
}