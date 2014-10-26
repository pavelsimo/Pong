#ifndef MAINBITMAPFONT_H
#define MAINBITMAPFONT_H

#include "LOpenGL.h"
#include "BitmapFont.h"
#include <string>

class MainBitmapFont
{
    public:
        // ctor & dtor
        MainBitmapFont();
        MainBitmapFont(GLfloat width, GLfloat height);
        ~MainBitmapFont();

        // methods
        bool LoadBitmap(const std::string& filename);
        void Initialize();
        void Clean();
        BitmapFont* GetBitmapFont();
        
    private:
        GLfloat m_width;
        GLfloat m_height;
        BitmapFont* m_bitmapFont;
};




#endif
