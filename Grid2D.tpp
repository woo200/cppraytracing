namespace JUtils
{
    template <class T>
    Grid2D<T>::Grid2D(int width, int height)
    {
        this->width = width;
        this->height = height;

        this->grid = (T*) malloc(width * height * sizeof(T));
    }

    template <class T>
    void Grid2D<T>::set(int x, int y, T c)
    {
        if (x >= this->width || x < 0) {
            return;
        }
        if (y >= this->height || y < 0) {
            return;
        }

        this->grid[y * this->width + x] = c;
    }

    template <class T>
    void Grid2D<T>::fill(T c)
    {
        for (int i = 0, gridSize = this->width * this->height; i < gridSize; i++)
        {
            this->grid[i] = c;
        }
    }

    template <class T>
    T* Grid2D<T>::getGrid()
    {
        return this->grid;
    }

    template <class T>
    T* Grid2D<T>::get(int x, int y)
    {
        if (x >= this->width || x < 0) {
            return 0;
        }
        if (y >= this->height || y < 0) {
            return 0;
        }

        return &this->grid[y * this->width + x];
    }   

    template <class T>
    int Grid2D<T>::getHeight()
    {
        return this->height;
    }

    template <class T>
    int Grid2D<T>::getWidth()
    {
        return this->width;
    }
}