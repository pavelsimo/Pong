#include "World.h"

namespace pong
{
	World::World()
	: m_width(640),
	  m_height(480)
	{

	}

	World::World(const float width, const float height)
	: m_width(width),
	  m_height(height),
	  m_ball(width * 0.5f, height * 0.5f, 20, 20),
	  m_player1(0, height * 0.5f, 20, 20),
	  m_player2(width - 20, height * 0.5f, 20, 60)
	{

	}

	World::~World()
	{

	}

	void World::Draw()
	{
		float ballWidth = m_ball.GetWidth();
		float ballHeight = m_ball.GetHeight();
		glLoadIdentity();

		glBegin( GL_QUADS );
			glColor3f(1.f, 1.f, 1.f); 
			glVertex2f(m_ball.m_aabb2.min.x, m_ball.m_aabb2.min.y);
			glVertex2f(m_ball.m_aabb2.max.x, m_ball.m_aabb2.min.y);
			glVertex2f(m_ball.m_aabb2.max.x, m_ball.m_aabb2.max.y);
			glVertex2f(m_ball.m_aabb2.min.x, m_ball.m_aabb2.max.y);
		glEnd();
	}

	void World::Update()
	{
		m_ball.Move(math::Vector2(1,1));
	}

	void World::OnKeyDown(unsigned char key)
	{
		
	}

	void World::OnKeyUp(unsigned char key)
	{
		
	}

	float World::GetLeft()
	{
		return 0;
	}

	float World::GetRight()
	{
		return m_width;
	}

	float World::GetBottom()
	{
		return m_height;
	}

	float World::GetTop()
	{
		return 0;
	}
}