#include "Paddle.h"

namespace pong
{

    Paddle::Paddle()
    {
        
    }

    Paddle::Paddle(const math::Vector2 topleft, 
        const float width, const float height)
    : m_aabb2(
        topleft, 
        math::Vector2(topleft.x + width, topleft.y + height)
      ),
      m_width(width),
      m_height(height)
    {

    }

    Paddle::~Paddle()
    {

    }

    void Paddle::MoveUp(const float dy)
    {
        MoveVertical(-dy);
    }

    void Paddle::MoveDown(const float dy)
    {
        MoveVertical(dy);
    }

    float Paddle::GetWidth() const
    {
        return m_width;
    }

    float Paddle::GetHeight() const
    {
        return m_height;
    }

    math::AABB2 Paddle::GetAABB2() const
    {
        return m_aabb2;
    }

    void Paddle::MoveVertical(const float dy)
    {
        m_aabb2.Move(math::Vector2(0, dy));
    }
}
