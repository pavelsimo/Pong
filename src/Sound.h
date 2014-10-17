#ifndef SOUND_H
#define SOUND_H

#include "LOpenAL.h"
#include <iostream>
#include <string>

class Sound 
{
    public:
        // ctor & dtor
        Sound();
        ~Sound();

        // functions
        bool LoadFromFile(const char* filename);
        void Play();
        void Stop();
        void Pause();
    private:
        ALuint m_buffer;
        ALuint m_source;
};

#endif