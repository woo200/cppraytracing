#include "Camera.hpp"

namespace JRay
{
    Camera::Camera(int x, int y, int resolution, int offset)
    : Sprite(x, y)
    {
        this->resolution = resolution;
        this->offset = offset;
    }

    void Camera::setOffset(int offset)
    {
        this->offset = offset;
    }

    int Camera::getResolution()
    {
        return this->resolution;
    }

    int Camera::getOffset()
    {
        return this->offset;
    }

    point* Camera::render(Sprite** sprites, int spritesCnt)
    {
        Ray* rays = (Ray*) malloc(sizeof(Ray) * resolution); // Create all the new rays
        point* rayResults = (point*) malloc(sizeof(point) * resolution); // Create the place to put the results

        // Initialize all the rays so they will equally cover a FOV of 180 degrees
        for (int i = 0; i < resolution; i++)
        {
            double angle = i * (180.0 / resolution) + offset;
            rays[i] = Ray(this->x, this->y, angle);
        }

        for (int i = 0; i < resolution; i++)
        {
            bool intersecting = false;
            int marches = 0;
            do {
                rays[i].march(); // March the ray
                for (int ix = 0; ix < spritesCnt; ix++) // Check for intersections
                {
                    if (sprites[ix]->intersecting(rays[i]))
                        intersecting = true;
                    //std::cout << sprites[ix]->intersecting(Sprite(1.3, 2.4));
                }
                marches++;
            } while (!intersecting && marches < 1000); // Max 1000 Marches

            // Save March Results
            if (intersecting) {
                rayResults[i].x = marches;
                rayResults[i].y = rays[i].getAngle();
            } else {
                rayResults[i].x = 0;
                rayResults[i].y = 0;
            }
            
        }

        free(rays);
        return rayResults;
    }
}