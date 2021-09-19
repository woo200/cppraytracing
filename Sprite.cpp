#include "Sprite.hpp"

namespace JRay
{
    Sprite::Sprite(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double Sprite::getX()
    {
        return this->x;
    }
    double Sprite::getY()
    {
        return this->y;
    }
    bool Sprite::intersecting(Sprite sp)
    {
        if (sp.getX() != x) return false;
        if (sp.getY() != y) return false;
        return true;
    }
    // bool Sprite::intersecting(Sprite sprite) 
    // {
    //     double sx = 3;
    //     double sy = 3;

    //     float d = sqrt(pow(sx - x, 2) +
    //                    pow(sy - y, 2));
        
    //     return d <= 1;
    // }

}