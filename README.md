# JRay C++ 2D Ray Tracing
This was written mostly as an example, this all started after a friend dared me to write ray tracing in Scratch! Once I finished that, I wanted to implement it in C++, So here it is! It does its job but is terribly inefficient. As I said before, this is mostly just a proof of concept. Written in pure C++

### Building
`make build`
Then just run it as `./main`

### How to use it
My saying is, "If you can implement a collider you can render it"! Good, eh? Well, anyways, here is how you can use this.
#### Setting up a scene
The two things you need for a scene are a Camera, and a list of objects.
```cpp
    int objects = 3; // How many objects in the scene
    JRay::Camera camera(0, 0, 1000, 0); // X, Y, Resolution, Angle Offset
    JRay::Sprite** sprites = (JRay::Sprite**) malloc(sizeof(JRay::Sprite*) * objects); // Allocate the array of handles for the renderer

    JRay::SimpleObject* object = new JRay::SimpleObject(-25, -25, 5); // X, Y, Radius (Circle)
    sprites[0] = object; // Add object to array
    JRay::SimpleObject* object2 = new JRay::SimpleObject(10, 10, 5); // X, Y, Radius (Circle)
    sprites[1] = object2; // Add object to array
    JRay::SimpleSquare* object3 = new JRay::SimpleSquare(-10, -10, 5, 5); // X, Y, Width, Height (Square)
    sprites[2] = object3; // Add object to array

    JRay::point* points = camera.render(sprites, objects); // Simple as that - Returns an array of points the size of the resolution (X = Steps, Y = Angle)
```
oh, and I should probably tell you about points because that is what the renderer returns..
A point is just a simple struct that contains X and Y. The X and Y contained in this struct do not neccesarily represent coordinates, they can represent any data that requires 2 doubles, for example, the points returned by render are "Steps" and Angles.
#### Drawing the rendered result
Drawing the rendered result is a fairly simple task, all you do is take the points returned from the render, and then make a virtual grid, take an origin point (0, 0), and then for each point march ("Steps") steps at the angle defined in the point, and draw something at the resulting point. Here's how I implemented it.
```cpp
    JRay::point* points = camera.render(sprites, objects);

    int grid_size = 40; // 40x40 grid
    JUtils::Grid2D<char> grid(grid_size, grid_size); // JUtils (YAY!)
    grid.fill(' '); // Fill the grid with spaces so you dont get weird behavior in the next steps

    int max_steps = 0;

    for (int i = 0; i < camera.getResolution(); i++) // Find the maximum step size
    {
        JRay::point p = points[i];
        if (p.x == 0 && p.y == 0) // If X and Y are 0 that means the point traced out of the render distance
            continue;
        
        if (p.x > max_steps) // p.x = steps, p.y = angle
            max_steps = p.x;
    }
    
    double scaling_factor = (double)grid_size / (double)max_steps; // Calculate the scaling factor so the output doesnt get out of bounds of the array
    
    grid.set(0, 0, 'C'); // Set the origin point to 'C' just so I can see where it is

    for (int i = 0; i < camera.getResolution(); i++)
    {
        JRay::point p = points[i];
        double g = (p.y + camera.getOffset()) * (M_PI / 180); // Degrees to radians

        double scaled_steps = p.x * scaling_factor; // Scale down the steps to fit in the grid

        double x = scaled_steps * cos(g); // black magic fuckery
        double y = scaled_steps * sin(g);
        
        if (x > 0 && y > 0) // Add the point to the grid if it is in bounds
            grid.set(x, y, 'X');
    }
    
    // Draw the grid, Origin at the bottom left corner of terminal
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
```
#### The Full Thing
See [The Main File](/main.cpp)
Sorry about my spaghetti :)

