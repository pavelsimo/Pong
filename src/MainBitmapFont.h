#ifndef MAINBITMAPFONT_H
#define MAINBITMAPFONT_H

#include "LOpenGL.h"
#include "BitmapFont.h"
#include <string>

class MainBitmapFont : public BitmapFont
{
    public:
        // ctor & dtor
        MainBitmapFont();
        MainBitmapFont(GLfloat width, GLfloat height);
        ~MainBitmapFont();

        // methods
        bool LoadBitmap(const std::string& filename);
        void Initialize();
    private:
        GLfloat m_width;
        GLfloat m_height;
};




#endif
