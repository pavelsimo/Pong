#include "BitmapFont.h"

// ctor & dtor
BitmapFont::BitmapFont()
: m_texture(nullptr)
{

}

BitmapFont::~BitmapFont()
{
    Clean();
}

bool BitmapFont::LoadBitmap(const std::string& filename)
{
    Clean();

    if(m_texture == nullptr)
    {
        m_texture = new Texture();
        m_texture->LoadFromFile(filename);      
    }
}

void BitmapFont::AddCharacter(unsigned int glyph, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
    Rect rect(x, y, w, h);
    AddCharacter(glyph, rect);
}

void BitmapFont::AddCharacter(unsigned int glyph, Rect rect)
{
    m_glyphs[glyph] = rect;
}

void BitmapFont::RemoveCharacter(unsigned int glyph)
{
    if(m_glyphs.size() > 0)
    {
        std::map<unsigned int, Rect>::iterator it;
        it = m_glyphs.find(glyph);
        if(it != m_glyphs.end())
        {
            m_glyphs.erase(it);
        }
    }
}

Rect BitmapFont::GetCharacter(unsigned int glyph)
{
    if(m_glyphs.size() > 0)
    {
        std::map<unsigned int, Rect>::iterator it;
        it = m_glyphs.find(glyph);
        if(it != m_glyphs.end())
        {
            return it->second;
        }
    }
    // TODO: (Pavel) this should be a constant
    return Rect(0, 0, 0, 0);
}

Texture* BitmapFont::GetTexture()
{
    return m_texture;
}

void BitmapFont::Clean()
{
    if(m_texture != nullptr)
    {
        delete m_texture;
        m_texture = nullptr;
    }

    m_glyphs.clear();
}