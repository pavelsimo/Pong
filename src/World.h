#ifndef WORLD_H
#define WORLD_H

#include "LOpenGL.h"
#include "Vector2.h"
#include "Ball.h"
#include "Player.h"

namespace pong
{
    class World 
    {
        // TODO: (Pavel) Add States
        public:
            World();
            World(const float width, const float height);
            ~World();

            void Draw();
            void Update();
            void OnKeyDown(unsigned char key);
            void OnKeyUp(unsigned char key);

            float GetLeft();
            float GetRight();
            float GetBottom();
            float GetTop();
        private:
            float m_width;
            float m_height;

            Ball m_ball;
            Player m_player1;
            Player m_player2;
    };
}


#endif
