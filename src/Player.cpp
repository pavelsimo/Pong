#include "Player.h"

namespace pong
{
    Player::Player()
    : m_score(0)
    {
        
    }

    Player::Player(float x, float y, float paddleWidth, float paddleHeight)
    : m_paddle(math::Vector2(x, y), paddleWidth, paddleHeight),
      m_score(0)
    {

    }

    Player::~Player()
    {

    }

    void Player::MoveVertical(float dy, float minY, float maxY)
    {
        m_paddle.MoveVertical(dy, minY, maxY);
    }

    void Player::UpdateScore(int score)
    {
        m_score += score;
    }

    int Player::GetScore() const 
    {
        return m_score;
    }

    const Paddle& Player::GetPaddle()
    {
        return m_paddle;
    }
}
