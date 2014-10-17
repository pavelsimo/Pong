#include "ScoreBar.h"
#include <iostream>

const int DIGIT_SPACE_OFFSET = 31;

ScoreBar::ScoreBar(int score, Texture *texture)
: m_score(score),
  m_texture(texture)
{
    InitializeNumbers();
}

ScoreBar::~ScoreBar()
{

}

void ScoreBar::InitializeNumbers()
{
    // digit clip rectangle
    m_clipRegion[0] = draw::Rect(591, 29, 30, 42);
    m_clipRegion[1] = draw::Rect(638, 29, 30, 42);
    m_clipRegion[2] = draw::Rect(670, 29, 30, 42);
    m_clipRegion[3] = draw::Rect(715, 29, 30, 42);
    m_clipRegion[4] = draw::Rect(756, 29, 30, 42);
    m_clipRegion[5] = draw::Rect(804, 29, 30, 42);
    m_clipRegion[6] = draw::Rect(846, 29, 30, 42);
    m_clipRegion[7] = draw::Rect(891, 29, 30, 42);
    m_clipRegion[8] = draw::Rect(936, 29, 30, 42);
    m_clipRegion[9] = draw::Rect(981, 29, 30, 42);
}

void ScoreBar::SetScore(int score)
{
    m_score = score;
}

void ScoreBar::Render(GLuint x, GLuint y)
{
    std::string strScore = std::to_string(m_score);
    for(int i = 0; i < strScore.size(); ++i)
    {
        int digit = strScore[i] - '0';
        draw::Rect clip = m_clipRegion[digit];
        draw::DrawTexture(
            x + i * DIGIT_SPACE_OFFSET, y,
            m_texture->GetTexId(),
            m_texture->GetImgWidth(), m_texture->GetImgHeight(),
            m_texture->GetTexWidth(), m_texture->GetTexHeight(),
            &clip
        );
    }
}
