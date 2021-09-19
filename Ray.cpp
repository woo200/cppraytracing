#include "Ray.hpp"

namespace JRay
{
    Ray::Ray(double x, double y, double angle) 
    : Sprite(x, y)
    {
        this->angle = angle;
    }

    // March the ray forward
    void Ray::march()
    {
        double g = this->angle * (M_PI / 180); // Degrees to radians

        this->x += cos(g);
        this->y += sin(g);
    }

    double Ray::getAngle()
    {
        return this->angle;
    }

}