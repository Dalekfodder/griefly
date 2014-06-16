#pragma once

#include <assert.h>

#include "constheader.h"

namespace helpers
{
    inline void move_to_dir(Dir dir, int* x, int* y, int* z = nullptr)
    {
        if (x)
        {
            *x += DirToVDir[dir].x;
            if (*x >= sizeWmap ||
                *x <= -1)
                *x -= DirToVDir[dir].x;
        }
        if (y)
        {
            *y += DirToVDir[dir].y;
            if (*y >= sizeHmap ||
                *y <= -1)
                *y -= DirToVDir[dir].y;
        }
        if (z)
        {
            *z += DirToVDir[dir].z;
            if (*z >= sizeDmap ||
                *z <= -1)
                *z -= DirToVDir[dir].z;
        }
    }
}