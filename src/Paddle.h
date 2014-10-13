#ifndef PADDLE_H
#define PADDLE_H

#include "Vector2.h"
#include "AABB2.h"

namespace pong
{
    class Paddle
    {
        public:
            // ctor & dtor
            Paddle();
            Paddle(const math::Vector2 topleft, 
                const float width, const float height);
            ~Paddle();
            
            // functions
            void MoveVertical(const float dy, 
                const float minY, const float maxY);

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
