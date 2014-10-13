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
            
            // functions
            void MoveVertical(const float dy, 
                const float minY, const float maxY);
            void UpdateScore(const int score);
            int GetScore() const;
            Paddle& GetPaddle();
        private:
            Paddle m_paddle;
            int m_score;
    };
}

#endif 
