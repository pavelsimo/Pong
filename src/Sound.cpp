#include "Sound.h"



Sound::Sound()
: m_buffer(0),
  m_source(0)
{

}

Sound::~Sound()
{

}

bool Sound::LoadFromFile(const char* filename)
{

    m_buffer = alutCreateBufferFromFile(filename);

    if ( alutGetError() != ALUT_ERROR_NO_ERROR )
    {
       std::cout << "Unable to create the buffer." << std::endl;
       return false;
    }

    alGenSources (1, &m_source);
    if(alGetError() != AL_NO_ERROR) 
    {
        std::cout << "Unable to generate the source." << std::endl;
        return false;
    }
    
    alSourcei(m_source, AL_BUFFER, m_buffer);

    /*
    // The version of ALUT that ships with OS X 10.4 
    // and earlier is fairly old, and does not include the 
    // alutCreateBufferHelloWorld or alutCreateBufferFromFile 
    // functions; you'll need to use the older, deprecated API instead:

    alutLoadWAVFile((ALbyte *)"/path/to/audio.wav",
        &format,&data,&size,&freq,&loop);
    alBufferData(buffer[0],format,data,size,freq);
    alutUnloadWAV(format,data,size,freq);
    
    */

    return true;
}

void Sound::Play()
{
    alSourcePlay(m_source);
}

void Sound::Stop()
{
    alSourceStop(m_source);
}

void Sound::Pause()
{

}
