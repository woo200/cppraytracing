#pragma once

#include <stdlib.h>

namespace JUtils 
{
    template <class T>
    class Grid2D
    {
        int width, height;
        T* grid;
    public:
        Grid2D(int, int);
        
        void set(int, int, T);
        void fill(T);
        T* get(int, int);
        T* getGrid();
        int getWidth();
        int getHeight();
    };
}

#include "Grid2D.tpp"