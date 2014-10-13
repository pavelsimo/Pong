#ifndef BALL_H
#define BALL_H

#include "Vector2.h"
#include "AABB2.h"

namespace pong 
{
    class Ball 
    {
        public:
            // ctor & dtor
            Ball();
            Ball(const float x, const float y, 
                const float width, const float height);
            Ball(const math::Vector2 topleft, 
                const float width, const float height);
            ~Ball();

            void Move(const math::Vector2& rhs);
            float GetWidth() const;
            float GetHeight() const;
            float GetMinX() const;
            float GetMinY() const;
            float GetMaxX() const;
            float GetMaxY() const;
            math::Vector2 GetCenter() const;
            math::AABB2 GetAABB2() const;
        private:
            math::AABB2 m_aabb2;
            float m_width;
            float m_height;
    };

}

#endif
