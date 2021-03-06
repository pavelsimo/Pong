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
        virtual ~BitmapFont();

        // methods
        virtual bool LoadBitmap(const std::string& filename);
        void AddCharacter(unsigned int glyph, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
        void AddCharacter(unsigned int glyph, Rect rect);
        void RemoveCharacter(unsigned int ch);
        Rect GetCharacter(unsigned int glyph);
        Texture* GetTexture();
        void Clean();
        
    private:
        Texture* m_texture;
        std::map<unsigned int, Rect> m_glyphs;
};

#endif