#include "Ball.h"

namespace pong 
{
    Ball::Ball()
    : m_width(0),
      m_height(0)
    {
        
    }

    Ball::Ball(float x, float y, 
        float width, float height)
    : m_aabb2(
        math::Vector2(x, y), 
        math::Vector2(x + width, y + height)
      ),
      m_width(width),
      m_height(height)
    {

    }

    Ball::Ball(const math::Vector2 topleft, 
        float width, float height)
    : m_aabb2(
        topleft, 
        math::Vector2(topleft.x + width, topleft.y + height)
      ),
      m_width(width),
      m_height(height)
    {

    }

    Ball::~Ball()
    {
        
    }

    void Ball::Move(const math::Vector2& rhs)
    {
        m_aabb2.Move(rhs);
    }

    float Ball::GetWidth() const
    {
        return m_width;
    }

    float Ball::GetHeight() const
    {
        return m_height;
    }

    float Ball::GetMinX() const
    {
        return m_aabb2.min.x;
    }

    float Ball::GetMinY() const
    {
        return m_aabb2.min.y;
    }

    float Ball::GetMaxX() const
    {
        return m_aabb2.max.x;
    }

    float Ball::GetMaxY() const
    {
        return m_aabb2.max.y;
    }

    math::Vector2 Ball::GetCenter() const
    {
        return m_aabb2.GetCenter();
    }

    math::AABB2 Ball::GetAABB2() const
    {
        return m_aabb2;
    }
}
