#ifndef RECT_H
#define RECT_H

#include "LOpenGL.h"

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

#endif