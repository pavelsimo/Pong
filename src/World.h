#ifndef WORLD_H
#define WORLD_H

#include "LOpenGL.h"
#include "Vector2.h"
#include "Ball.h"
#include "Player.h"
#include "MathUtilities.h"
#include "Drawing.h"
#include "Texture.h"

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
            bool IsBallInBounds() const;

            // player 1 (AI)
            void UpdatePlayer1();
            void DrawPlayer1();

            // player 2 (You)
            void UpdatePlayer2();
            void DrawPlayer2();

            // game ui
            void DrawPlayField();
            void ChangeState(GameState state);
            void Restart();

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
            Texture m_texBanner;
    };
}

#endif
