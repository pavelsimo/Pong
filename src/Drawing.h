#ifndef DRAWING_H
#define DRAWING_H

#include "LOpenGL.h"
#include "Vector2.h"

namespace draw
{
    enum LINE_TYPE { DOTTED, DASHED, SOLID };

    struct Rect 
    {
        Rect()
        : x(0), y(0), w(0), h(0)
        {

        }

        Rect(GLfloat _x, GLfloat _y, GLfloat _w, GLfloat _h)
        : x(_x), y(_y), w(_w), h(_h)
        {

        }

        GLfloat x; 
        GLfloat y; 
        GLfloat w; 
        GLfloat h; 
    };

    void DrawLine( 
        const math::Vector2 origin, 
        const math::Vector2 end, 
        LINE_TYPE type, 
        float width 
    );

    void DrawQuad(
        float minX, float minY, 
        float maxX, float maxY
    );

    void DrawTexture(
        GLfloat x, GLfloat y, 
        GLuint texId,
        GLuint imgWidth, GLuint imgHeight, 
        GLuint texWidth, GLuint texHeight,
        Rect* clip = NULL
    );
}

#endif