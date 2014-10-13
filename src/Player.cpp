#include "Player.h"

namespace pong
{
    Player::Player()
    {
        
    }

    Player::Player(float x, float y, float paddleWidth, float paddleHeight)
    : m_paddle(math::Vector2(x, y), paddleWidth, paddleHeight)
    {

    }

    Player::~Player()
    {

    }

    void Player::MoveVertical(const float dy, 
        const float minY, const float maxY)
    {
        m_paddle.MoveVertical(dy, minY, maxY);
    }

    void Player::UpdateScore(const int score)
    {
        m_score += score;
    }

    int Player::GetScore() const 
    {
        return m_score;
    }

    Paddle& Player::GetPaddle()
    {
        return m_paddle;
    }
}
