#ifndef WORLD_H
#define WORLD_H

#include "LOpenGL.h"
#include "Vector2.h"
#include "Ball.h"
#include "Player.h"
#include "MathUtilities.h"
#include "Drawing.h"
#include "Texture.h"
#include "Sound.h"
#include "ScoreBar.h"

namespace pong
{
    enum GameState 
    {
        IDLE,
        PLAYING,
        GAMEOVER
    };

    class World 
    {
        public:
            World();
            World(const float width, const float height);
            ~World();

            void Draw();
            void Update();
            void OnKeyDown(unsigned char key);
            void OnKeyUp(unsigned char key);
            void OnMouseMove(int x, int y);
            void OnMouseClick(int button, int state, int x, int y);
            float GetWidth() const;
            float GetHeight() const;
            float GetLeft() const;
            float GetRight() const;
            float GetBottom() const;
            float GetTop() const;
        private:
            // ball
            void UpdateBall();
            void DrawBall();
            bool HasBallCollideTop() const;
            bool HasBallCollideBottom() const;
            bool HasBallCollideLeft() const;
            bool HasBallCollideRight() const;
            bool IsBallInBounds() const;

            // player 1 (AI)
            void UpdatePlayer1();
            void DrawPlayer1();
            bool HasPlayer1Score();

            // player 2 (You)
            void UpdatePlayer2();
            void DrawPlayer2();
            bool HasPlayer2Score();

            // game ui
            void LoadResources();
            void CleanResources();
            void DrawPlayField();
            void DrawScore();
            void DrawBanner();
            void ChangeState(GameState state);
            void Restart();
            bool LoadBannerTexture(const std::string& path);
            bool LoadFontTexture(const std::string& path);

            // helpers
            void DrawPlayerPaddle(Player& player);

            GameState m_state;
            float m_width;
            float m_height;
            Ball m_ball;
            Player m_player1;
            Player m_player2;
            math::Vector2 m_velBall;
            math::Vector2 m_mousePos;
            ScoreBar* m_scorePlayer1;
            ScoreBar* m_scorePlayer2;
            Texture* m_texBanner;
            Texture* m_texFonts;
            Sound* m_sndTheme;
            Sound* m_sndBallHitPaddle;
    };
}

#endif
