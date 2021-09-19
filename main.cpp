#include <stdlib.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>

#include "Camera.hpp"
#include "SimpleObject.hpp"
#include "SimpleSquare.hpp"
#include "Sprite.hpp"
#include "Grid2D.hpp"

void render(JRay::Camera camera, JRay::Sprite** sprites, int objects)
{
    JRay::point* points = camera.render(sprites, objects);
    std::cout.precision(17);

    int grid_size = 40;
    JUtils::Grid2D<char> grid(grid_size, grid_size);
    grid.fill(' ');

    int max_steps = 0;

    for (int i = 0; i < camera.getResolution(); i++)
    {
        JRay::point p = points[i];
        if (p.x == 0 && p.y == 0)
            continue;
        
        if (p.x > max_steps) // p.x = steps, p.y = angle
            max_steps = p.x;
    }
    
    double scaling_factor = (double)grid_size / (double)max_steps;
    
    grid.set(0, 0, 'C');

    // I dont understand this but it works
    for (int i = 0; i < camera.getResolution(); i++)
    {
        JRay::point p = points[i];
        double g = (p.y + camera.getOffset()) * (M_PI / 180); // Degrees to radians

        double scaled_steps = p.x * scaling_factor; // Scale down the steps to fit in the grid

        double x = scaled_steps * cos(g); // black magic fuckery
        double y = scaled_steps * sin(g);
        
        if (x > 0 && y > 0) 
            grid.set(x, y, 'X');
    }
    
    for (int y = grid.getHeight(); y > 0; y--)
    {
        for (int x = 0; x < grid.getWidth(); x++)
        {
            char* c = grid.get(x, y);
            if (c != 0)
                std::cout << *c << *c;
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    srand (time(NULL));
    int objects = 3;
    
    JRay::Camera camera(0, 0, 1000, 0);
    JRay::Sprite** sprites = (JRay::Sprite**) malloc(sizeof(JRay::Sprite*) * objects);

    JRay::SimpleObject* object = new JRay::SimpleObject(-25, -25, 5);
    sprites[0] = object;
    JRay::SimpleObject* object2 = new JRay::SimpleObject(10, 10, 5);
    sprites[1] = object2;
    JRay::SimpleSquare* object3 = new JRay::SimpleSquare(-10, -10, 5, 5);
    sprites[2] = object3;

    unsigned int microsecond = 1000000;

    int FPS = 20;
    unsigned int dps = (1/FPS) * microsecond;

    while (true) {
        render(camera, sprites, objects);
        camera.setOffset((camera.getOffset() + 3) % 360);
        usleep(dps);
    }
    
}

