#ifndef DRAWING_H
#define DRAWING_H

#include "LOpenGL.h"
#include "Vector2.h"

namespace draw
{
    enum LINE_TYPE { DOTTED, DASHED, SOLID };

    void DrawLine( const math::Vector2 origin, const math::Vector2 end, 
        LINE_TYPE type, float width );
}

#endif