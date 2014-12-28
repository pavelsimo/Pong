#ifndef __ASTEROIDGAME_H_
#define __ASTEROIDGAME_H_

#include "Game.h"
#include "World.h"

namespace pong
{
    class PongGame : public Game
    {
        public:
            PongGame(const std::string& title, uint32_t width, uint32_t height,
                    uint32_t framesPerSecond = 60);
            ~PongGame();

            virtual void OnKeyDown(SDL_KeyboardEvent& event) override;
            virtual void OnKeyUp(SDL_KeyboardEvent& event) override;
            virtual void OnMouseButtonDown(SDL_MouseButtonEvent& event) override;
            virtual void OnMouseButtonUp(SDL_MouseButtonEvent& event) override;
            virtual void OnMouseMotion(SDL_MouseMotionEvent &event);
            virtual void OnUpdate() override;
            virtual void OnRender() override;
            virtual void OnInit() override;

    private:
            World* m_world;
    };


}

#endif //__ASTEROIDGAME_H_
