#include <iostream>

#include "LOpenGL.h"
#include "LOpenAL.h"
#include "World.h"

const int SCREEN_WIDTH = 1136;
const int SCREEN_HEIGHT = 640;
const int SCREEN_FPS = 60;

bool InitializeGL();
bool LoadingMedia();
void Render();
void Update();
void OnKeyboardEvent(unsigned char key, int x, int y);
void OnKeyboardUpEvent(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void GameLoop(int value);

pong::World* g_world = nullptr;

bool InitializeGL()
{
    glViewport(0.f, 0.f, g_world->GetWidth(), g_world->GetHeight());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(g_world->GetLeft(), g_world->GetRight(),
        g_world->GetBottom(), g_world->GetTop(), 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glEnable(GL_TEXTURE_2D);

    GLenum error = glGetError();
    if (error !=  GL_NO_ERROR )
    {
        std::cout << "Error initializing OpenGL! " << gluErrorString(error) << std::endl;
        return false;
    }

    // initialize DevIL and DevILU
    ilInit();
    iluInit();
    ilClearColour(0, 0, 0, 0);

    // check for errors
    ILenum ilError = ilGetError();
    if(ilError != IL_NO_ERROR)
    {
        printf( "Error initializing DevIL! %s\n", iluErrorString( ilError ) );
        return false;
    }

    return true;
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    g_world->Draw();
    glutSwapBuffers();
}

void Update()
{
    g_world->Update();
}

void OnKeyboardEvent(unsigned char key, int x, int y)
{

}

void OnMouseMoveEvent(int x, int y)
{
    g_world->OnMouseMove(x, y);
}

void OnMouseClick(int button, int state, int x, int y)
{
    g_world->OnMouseClick(button, state, x, y);
}

void GameLoop(int value)
{
    Update();
    Render();
    glutTimerFunc( 1000 / SCREEN_FPS, GameLoop, value);
}

int main(int argc, char** argv)
{
    g_world = new pong::World(SCREEN_WIDTH, SCREEN_HEIGHT);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Pong");
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    if(!InitializeGL())
    {
        std::cout << "Unable to initalize OpenGL." << std::endl;
    }

    // initialize alut
    alutInit (&argc, argv);

    glutDisplayFunc(Render);
    glutKeyboardFunc(OnKeyboardEvent);
    glutPassiveMotionFunc(OnMouseMoveEvent);
    glutMouseFunc( OnMouseClick );
    glutTimerFunc(1000 / SCREEN_FPS, GameLoop, 0);
    glutMainLoop();

    // exit alut
    alutExit();

    if(g_world != nullptr)
    {
        delete g_world;
        g_world = nullptr;
    }

    return 0;
}
