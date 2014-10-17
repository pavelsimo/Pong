#ifndef SCOREBAR_H
#define SCOREBAR_H

#include "LOpenGL.h"
#include "Drawing.h"
#include "Texture.h"
#include <vector>
#include <map>
#include <string>

const int NUM_RECTS = 10;

class ScoreBar
{
    public:
        ScoreBar(int score, Texture *texture);
        ~ScoreBar();

        void SetScore(int score);
        void SetTexture(Texture *texture);
        void Render(GLuint x, GLuint y);
    private:
        void InitializeNumbers();

        int m_score;
        Texture* m_texture;
        draw::Rect m_clipRegion[NUM_RECTS];
};

#endif