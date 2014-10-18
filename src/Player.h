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
            void MoveVertical(float dy, float minY, float maxY);
            void UpdateScore(int score);
            int GetScore() const;
            const Paddle& GetPaddle();
        private:
            Paddle m_paddle;
            int m_score;
    };
}

#endif 
