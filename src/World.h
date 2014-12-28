#ifndef WORLD_H
#define WORLD_H

#include <sstream>

#include "LOpenGL.h"
#include "Vector2.h"
#include "Ball.h"
#include "Player.h"
#include "MathUtilities.h"
#include "Drawing.h"
#include "Texture.h"
#include "Sound.h"
#include "MainBitmapFont.h"

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
            bool LoadResources();
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
            //
            void UpdateBall();
            void DrawBall();
            bool HasBallCollideTop() const;
            bool HasBallCollideBottom() const;
            bool HasBallCollideLeft() const;
            bool HasBallCollideRight() const;
            bool IsBallInBounds() const;

            // player 1 (AI)
            //
            void UpdatePlayer1();
            void DrawPlayer1();
            bool HasPlayer1Score();

            // player 2 (You)
            //
            void UpdatePlayer2();
            void DrawPlayer2();
            bool HasPlayer2Score();

            // game ui
            //
            void CleanResources();
            void DrawPlayField();
            void DrawScore();
            void DrawBanner();
            void ChangeState(GameState state);
            void Restart();
            bool LoadBannerTexture(const std::string& path);

            GameState m_state;
            float m_width;
            float m_height;
            Ball m_ball;
            Player m_player1;
            Player m_player2;
            math::Vector2 m_velBall;
            math::Vector2 m_mousePos;
            Texture* m_texBanner;
            Sound* m_sndTheme;
            Sound* m_sndBallHitPaddle;
            BitmapFont* m_bitmapFont;

            // helpers
            //
            void DrawPlayerPaddle(Player& player);

            // TODO: (Pavel) Move this to an utility class
            template <typename T>
            std::string NumberToString ( T Number )
            {
                std::ostringstream ss;
                ss << Number;
                return ss.str();
            }
    };
}

#endif
