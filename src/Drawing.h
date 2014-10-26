#ifndef DRAWING_H
#define DRAWING_H

#include "LOpenGL.h"
#include "Rect.h"
#include "Vector2.h"
#include "BitmapFont.h"

namespace draw
{
    enum LineType { 
        SOLID, 
        DOTTED = 0x0101, 
        DASHED = 0x00FF 
    };

    void DrawLine( 
        const math::Vector2& origin, 
        const math::Vector2& end, 
        LineType type, 
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

    void DrawText(
        GLfloat x, GLfloat y,
        const std::string &text,
        BitmapFont* font,
        GLfloat xOffset = 32,
        GLfloat yOffset = 0
    );
}

#endif