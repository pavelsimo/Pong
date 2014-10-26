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

void BitmapFont::AddCharacter(unsigned int ch, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	Rect rect(x, y, w, h);
	AddCharacter(ch, rect);
}

void BitmapFont::AddCharacter(unsigned int ch, Rect rect)
{
	m_characters[ch] = rect;
}

void BitmapFont::RemoveCharacter(unsigned int ch)
{
	// IMPLEMENT ME!
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

Rect BitmapFont::GetCharacter(unsigned int ch)
{
	return m_characters[ch];
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
}