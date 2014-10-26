#ifndef BITMAPFONT_H
#define BITMAPFONT_H

#include <map>
#include <string>
#include "Rect.h"
#include "Texture.h"


class BitmapFont
{
    public:
        // ctor & dtor
        BitmapFont();
        ~BitmapFont();

        // methods
        void AddCharacter(unsigned int ch, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
        void AddCharacter(unsigned int ch, Rect rect);
        void RemoveCharacter(unsigned int ch);
        bool LoadBitmap(const std::string& filename);
        Rect GetCharacter(unsigned int ch);
        Texture* GetTexture();
        void Clean();
        
    private:
        Texture* m_texture;
        std::map<unsigned int, Rect> m_characters;
};

#endif