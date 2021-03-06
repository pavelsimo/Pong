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
        ~MainBitmapFont();

        // methods
        bool LoadBitmap(const std::string& filename);
    private:
        void Initialize();
};

#endif
