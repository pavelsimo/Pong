#include "ScoreBar.h"
#include <iostream>

const int WIDTH_OFFSET = 31;

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
    m_intToRect[0] = draw::Rect(591, 29, 30, 42);
    m_intToRect[1] = draw::Rect(638, 29, 30, 42);
    m_intToRect[2] = draw::Rect(670, 29, 30, 42);
    m_intToRect[3] = draw::Rect(715, 29, 30, 42);
    m_intToRect[4] = draw::Rect(756, 29, 30, 42);
    m_intToRect[5] = draw::Rect(804, 29, 30, 42);
    m_intToRect[6] = draw::Rect(846, 29, 30, 42);
    m_intToRect[7] = draw::Rect(891, 29, 30, 42);
    m_intToRect[8] = draw::Rect(936, 29, 30, 42);
    m_intToRect[9] = draw::Rect(981, 29, 30, 42);
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
        draw::Rect clip = m_intToRect[digit];
        draw::DrawTexture(
            x + i * WIDTH_OFFSET, y,
            m_texture->GetTexId(),
            m_texture->GetImgWidth(), m_texture->GetImgHeight(),
            m_texture->GetTexWidth(), m_texture->GetTexHeight(),
            &clip
        );
    }
}
