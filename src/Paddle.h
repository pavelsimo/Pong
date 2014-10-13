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
			void MoveUp(const float dy);
			void MoveDown(const float dy);
			float GetWidth() const;
			float GetHeight() const;
			math::AABB2 GetAABB2() const;
			
		private:
			void MoveVertical(const float dy);
			
			math::AABB2 m_aabb2;
			float m_width;
			float m_height;
	};
}

#endif