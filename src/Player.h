#ifndef PLAYER_H
#define PLAYER_H

#include "Paddle.h"

namespace pong
{
    class Player 
    {
        public:
            Player();
            Player(float x, float y, float paddleWidth, float paddleHeight);
            ~Player();
            
            void MoveUp(const float dy);
            void MoveDown(const float dy);
            void UpdateScore(const int score);
            int GetScore() const;
            Paddle& GetPaddle();
        private:
            Paddle m_paddle;
            int m_score;
    };
}

#endif 
