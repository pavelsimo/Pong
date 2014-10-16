#include "World.h"
#include <iostream>

namespace pong
{
    const float BALL_SPEED = -4;
    const float BALL_WIDTH = 20;
    const float BALL_HEIGHT = 20;
    const float BALL_VEL_MULT = 1;
    const float PADDLE_WIDTH = 20;
    const float PADDLE_HEIGHT = 80;
    const float DRAG = 0.2;
    const float LINE_WIDTH = 4;

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
      m_velBall(math::Vector2(BALL_SPEED, BALL_SPEED)),
      m_state(IDLE),
      m_texBanner(nullptr),
      m_texFonts(nullptr),
      m_scorePlayer1(nullptr),
      m_scorePlayer2(nullptr)
    {

    }

    World::~World()
    {
        // clean m_texBanner
        if(m_texBanner != nullptr)
        {
            delete m_texBanner;
            m_texBanner = nullptr;
        }

        // clean m_texFonts
        if(m_texFonts != nullptr)
        {
            delete m_texFonts;
            m_texFonts = nullptr;
        }

        // clean m_scorePlayer1
        if(m_scorePlayer1 != nullptr)
        {
            delete m_scorePlayer1;
            m_scorePlayer1 = nullptr;
        }

        // clean m_scorePlayer2
        if(m_scorePlayer2 != nullptr)
        {
            delete m_scorePlayer2;
            m_scorePlayer2 = nullptr;
        }
    }

    void World::Draw()
    {
        if(m_state == IDLE)
        {
            if(m_texBanner != nullptr && m_texBanner->GetTexId() != 0)
            {
                DrawBanner();
            }
        }
        else if(m_state == PLAYING)
        {
            DrawPlayField();
            DrawScore();
            DrawBall();
            DrawPlayer1();
            DrawPlayer2();
        } 
        else if(m_state == GAMEOVER) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            DrawPlayField();
            DrawScore();
        }
    }

    void World::Update()
    {
        if(m_state == IDLE)
        {
            // TODO: (Pavel) move this to a new Initialize() method
            if(m_texBanner == nullptr)
            {
                // TODO: (Pavel) change to relative paths
                LoadBannerTexture("/home/pavelsimo/workspace/Games_Cpp/Pong/images/pong_banner.png");
            }
            if(m_texFonts == nullptr)
            {
                // TODO: (Pavel) change to relative paths
                LoadFontTexture("/home/pavelsimo/workspace/Games_Cpp/Pong/fonts/MainFont_EN_00.png");
                m_scorePlayer1 = new ScoreBar(0, m_texFonts);
                m_scorePlayer2 = new ScoreBar(0, m_texFonts);
            }
        }
        else if(m_state == PLAYING)
        {
            if(!IsBallInBounds())
            {
                ChangeState(GAMEOVER);
            }
            else
            {
                UpdateBall();
                UpdatePlayer1();
                UpdatePlayer2(); 
            }
        }
        else if(m_state == GAMEOVER)
        {
            if(HasBallCollideLeft())
            {
                m_player2.UpdateScore(1);
                m_scorePlayer2->SetScore(m_player2.GetScore());
            }
            else if(HasBallCollideRight())
            {
                m_player1.UpdateScore(1);
                m_scorePlayer1->SetScore(m_player1.GetScore());
            }
            Restart();
        }
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

    void World::OnMouseClick(int button, int state, int x, int y)
    {
        if(m_state == IDLE)
        {
            ChangeState(PLAYING);
        }
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
    // Ball
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
            m_velBall *= BALL_VEL_MULT;
        }

        m_ball.Move(m_velBall);
    }

    void World::DrawBall() 
    {
        draw::DrawQuad(
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

    bool World::HasBallCollideLeft() const
    {
        return m_ball.GetMinX() < 0;
    }

    bool World::HasBallCollideRight() const
    {
        return m_ball.GetMaxX() > m_width;
    }

    bool World::IsBallInBounds() const 
    {
        return !(HasBallCollideLeft() || HasBallCollideRight());
    }

    // ==================
    // Player 1 - AI
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

    // ==================
    // Player 2 - You
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
    // Game UI
    // ==================

    void World::DrawPlayField()
    {
        draw::DrawLine(
            math::Vector2(m_width * 0.5f, 0),
            math::Vector2(m_width * 0.5f, m_height),
            draw::DASHED,
            LINE_WIDTH
        );
    }

    void World::DrawScore()
    {
        m_scorePlayer1->Render(m_width / 2 - 200, 50);
        m_scorePlayer2->Render(m_width / 2 + 200 - 30, 50);
    }

    void World::DrawBanner()
    {
        // TODO: (Pavel) add method DrawBanner()
        draw::DrawTexture(
                m_width * 0.5f - m_texBanner->GetTexWidth() * 0.5f,
                m_height * 0.5f - m_texBanner->GetTexHeight() * 0.5f,
                m_texBanner->GetTexId(),
                m_texBanner->GetImgWidth(),
                m_texBanner->GetImgHeight(),
                m_texBanner->GetTexWidth(),
                m_texBanner->GetTexHeight()
        );
    }

    void World::ChangeState(GameState state)
    {
        m_state = state;
    }

    void World::Restart() 
    {
        ChangeState(PLAYING);
        m_ball = Ball(
            m_width * 0.5f, 
            m_height * 0.5f, 
            BALL_WIDTH, 
            BALL_HEIGHT
        );
        m_velBall = math::Vector2(BALL_SPEED, BALL_SPEED);
    }

    bool World::LoadBannerTexture(const std::string& path)
    {
        if(m_texBanner == nullptr)
        {
            m_texBanner = new Texture();
            if(!m_texBanner->LoadFromFile(path))
            {
                std::cout << "Unable to load the texture" << '\n';
            }
        }
    }

    bool World::LoadFontTexture(const std::string& path)
    {
        if(m_texFonts == nullptr)
        {
            m_texFonts = new Texture();
            if(!m_texFonts->LoadFromFile(path))
            {
                std::cout << "Unable to load the texture" << '\n';
            }
        }
    }


    // ==================
    // Helpers
    // ==================

    void World::DrawPlayerPaddle(Player& player)
    {
        draw::DrawQuad(
            player.GetPaddle().GetMinX(), player.GetPaddle().GetMinY(),
            player.GetPaddle().GetMaxX(), player.GetPaddle().GetMaxY()
        );
    }
}
