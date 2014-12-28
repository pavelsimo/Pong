#include "PongGame.h"

namespace pong
{
    PongGame::PongGame(const std::string &title, uint32_t width, uint32_t height,
            uint32_t framesPerSecond)
    : Game(title, width, height, framesPerSecond),
      m_world(new World(width, height))
    {

    }

    PongGame::~PongGame()
    {
        if(m_world != nullptr)
        {
            delete m_world;
            m_world = nullptr;
        }
    }

    void PongGame::OnKeyDown(SDL_KeyboardEvent &event)
    {
        switch(event.keysym.sym)
        {
            case SDLK_ESCAPE:
                // TODO: (Pavel) Exit the game
                break;
        }
    }

    void PongGame::OnKeyUp(SDL_KeyboardEvent &event)
    {
        // do nothing
    }

    void PongGame::OnMouseButtonDown(SDL_MouseButtonEvent &event)
    {
        m_world->OnMouseClick(event.button, event.state, event.x, event.y);
    }

    void PongGame::OnMouseButtonUp(SDL_MouseButtonEvent &event)
    {
        // do nothing
    }

    void PongGame::OnUpdate()
    {
        m_world->Update();
    }

    void PongGame::OnRender()
    {
		m_world->Draw();
    }

    void PongGame::OnInit()
    {
		
        if(!m_world->LoadResources())
        {
            std::cerr << "ERROR: Unable to load the game resources." << '\n';
        }
		
    }

    void PongGame::OnMouseMotion(SDL_MouseMotionEvent &event)
    {
        m_world->OnMouseMove(event.x, event.y);
    }
}