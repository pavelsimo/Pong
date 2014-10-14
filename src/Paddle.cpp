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

    void Paddle::MoveVertical(const float dy,
        const float minY, const float maxY)
    {
        m_aabb2.Move(math::Vector2(0, dy));
        
        if(m_aabb2.min.y < minY)
        {
            m_aabb2.Move(math::Vector2(0, minY - m_aabb2.min.y));
        } 
        else if(m_aabb2.max.y > maxY)
        {
            m_aabb2.Move(math::Vector2(0, maxY - m_aabb2.max.y));
        }
    }

    float Paddle::GetWidth() const
    {
        return m_width;
    }

    float Paddle::GetHeight() const
    {
        return m_height;
    }

    float Paddle::GetMinX() const
    {
        return m_aabb2.min.x;
    }

    float Paddle::GetMinY() const
    {
        return  m_aabb2.min.y;
    }
    
    float Paddle::GetMaxX() const
    {
        return m_aabb2.max.x;
    }

    float Paddle::GetMaxY() const
    {
        return m_aabb2.max.y;
    }

    math::Vector2 Paddle::GetCenter() const
    {
        return m_aabb2.GetCenter();
    }

    math::AABB2 Paddle::GetAABB2() const
    {
        return m_aabb2;
    }
}
