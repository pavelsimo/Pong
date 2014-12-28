#include "PongGame.h"
#include "LOpenAL.h"

const int SCREEN_WIDTH = 1136;
const int SCREEN_HEIGHT = 640;
const std::string SCREEN_TITLE = "Pong";

int main(int argc, char *argv[])
{
    alutInit (&argc, argv);

	pong::PongGame* game = new pong::PongGame(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    game->Run();

	if (game != nullptr)
	{
		delete game;
		game = nullptr;
	}
	
    alutExit();

    return 0;
}