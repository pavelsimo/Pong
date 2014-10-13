#include "World.h"

namespace pong
{
    const float BALL_SPEED = 4;
    const float PADDLE_WIDTH = 20;
    const float PADDLE_HEIGHT = 80;
    const float BALL_WIDTH = 20;
    const float BALL_HEIGHT = 20;
    const float DRAG = 0.5;

    World::World()
    : m_width(640),
      m_height(480)
    {

    }

    World::World(const float width, const float height)
    : m_width(width),
      m_height(height),
      m_ball(width * 0.5f, height * 0.5f, BALL_WIDTH, BALL_HEIGHT),
      m_player1(
        0, 
        (height - PADDLE_HEIGHT) * 0.5f, 
        PADDLE_WIDTH, 
        PADDLE_HEIGHT
      ),
      m_player2(
        width - PADDLE_WIDTH, 
        (height - PADDLE_HEIGHT) * 0.5f, 
        PADDLE_WIDTH, 
        PADDLE_HEIGHT
      ),
      m_velBall(math::Vector2(BALL_SPEED, BALL_SPEED))
    {

    }

    World::~World()
    {

    }

    void World::Draw()
    {
        DrawBall();
        DrawPlayer1();
        DrawPlayer2();
    }

    void World::Update()
    {
        UpdateBall();
        UpdatePlayer1();
        UpdatePlayer2();
    }

    void World::OnKeyDown(unsigned char key)
    {
        
    }

    void World::OnKeyUp(unsigned char key)
    {
        
    }

    void World::OnMouseMove(int x, int y)
    {
        m_mousePos.x = x;
        m_mousePos.y = y;
    }

    float World::GetWidth() const
    {
        return m_width;
    }

    float World::GetHeight() const
    {
        return m_height;
    }

    float World::GetLeft() const
    {
        return 0;
    }

    float World::GetRight() const
    {
        return m_width;
    }

    float World::GetBottom() const
    {
        return m_height;
    }

    float World::GetTop() const
    {
        return 0;
    }

    // ==================
    // BALL
    // ==================

    void World::UpdateBall() 
    {
        if(HasBallCollideBottom() || HasBallCollideTop()) 
        {
            m_velBall.y *= -1;
        }
        
        math::AABB2 player1AABB2 = m_player1.GetPaddle().GetAABB2();
        math::AABB2 player2AABB2 = m_player2.GetPaddle().GetAABB2();
        math::AABB2 ballAABB2 = m_ball.GetAABB2();

        if(ballAABB2.Intersects(player1AABB2) || ballAABB2.Intersects(player2AABB2))
        {
            m_velBall.x *= -1;
        }

        m_ball.Move(m_velBall);
    }

    void World::DrawBall() 
    {
        DrawQuad(
            m_ball.GetMinX(), m_ball.GetMinY(),
            m_ball.GetMaxX(), m_ball.GetMaxY()
        );
    }

    bool World::HasBallCollideTop() const
    {
        return m_ball.GetMinY() < 0;
    }

    bool World::HasBallCollideBottom() const
    {
        return m_ball.GetMaxY() > m_height;
    }

    // ==================
    // Player 1
    // ==================

    void World::UpdatePlayer1()
    {
        math::Vector2 ballCenter = m_ball.GetCenter();
        math::Vector2 pandleCenter = m_player1.GetPaddle().GetCenter();
        math::Vector2 displacement = ballCenter - pandleCenter;
        displacement *= DRAG;
        m_player1.MoveVertical(displacement.y, 0, m_height);
    }

    void World::DrawPlayer1() 
    {
        DrawPlayerPaddle(m_player1);
    }

    bool World::HasP1CollideTop()
    {
        return m_player1.GetPaddle().GetMinY() < 0;
    }

    bool World::HasP1CollideBottom()
    {
        return m_player1.GetPaddle().GetMaxY() > m_height;
    }

    // ==================
    // Player 2
    // ==================

    void World::UpdatePlayer2() 
    {
        math::Vector2 pandleCenter = m_player2.GetPaddle().GetCenter();
        math::Vector2 displacement = m_mousePos - pandleCenter;
        m_player2.MoveVertical(displacement.y, 0, m_height);
    }

    void World::DrawPlayer2() 
    {
        DrawPlayerPaddle(m_player2);
    }

    // ==================
    // helpers
    // ==================

    void World::DrawQuad(float minX, float minY, float maxX, float maxY)
    {
        glBegin( GL_QUADS );
            glColor3f(1.f, 1.f, 1.f); 
            glVertex2f(minX, minY);
            glVertex2f(maxX, minY);
            glVertex2f(maxX, maxY);
            glVertex2f(minX, maxY);
        glEnd();
    }

    void World::DrawPlayerPaddle(Player& player)
    {
        DrawQuad(
            player.GetPaddle().GetMinX(), player.GetPaddle().GetMinY(),
            player.GetPaddle().GetMaxX(), player.GetPaddle().GetMaxY()
        );
    }
}
