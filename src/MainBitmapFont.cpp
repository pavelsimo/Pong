#include "MainBitmapFont.h"


MainBitmapFont::MainBitmapFont()
: m_width(30),
  m_height(42)
{
    
}

MainBitmapFont::MainBitmapFont(GLfloat width, GLfloat height)
: m_width(width),
  m_height(height)
{
    
}

MainBitmapFont::~MainBitmapFont()
{
    Clean();
}

bool MainBitmapFont::LoadBitmap(const std::string& filename)
{
    Clean();

    if(m_bitmapFont == nullptr)
    {
        m_bitmapFont = new BitmapFont();
        m_bitmapFont->LoadBitmap(filename);     
    }

    Initialize();

    return true;
}

void MainBitmapFont::Initialize()
{
    // TODO: (Pavel) this should be configuration

    // numbers
    m_bitmapFont->AddCharacter('0', 591, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('1', 638, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('2', 670, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('3', 715, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('4', 756, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('5', 804, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('6', 846, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('7', 891, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('8', 936, 29, m_width, m_height);
    m_bitmapFont->AddCharacter('9', 981, 29, m_width, m_height);
}

void MainBitmapFont::Clean()
{
    if(m_bitmapFont != nullptr)
    {
        delete m_bitmapFont;
        m_bitmapFont = nullptr;
    }
}

BitmapFont* MainBitmapFont::GetBitmapFont()
{
    return m_bitmapFont;
}
