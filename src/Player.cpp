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

	void Player::MoveUp(const float dy)
	{
		m_paddle.MoveUp(dy);
	}

	void Player::MoveDown(const float dy)
	{
		m_paddle.MoveDown(dy);
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