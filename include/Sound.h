#ifndef SOUND_H
#define SOUND_H
#include "SFML/Audio.hpp"

// In case of error : undefined reference to sf::Sound go in settings -> Compiler -> Linker Settings
// Add usr/lib libwiringPi.so and in usr/lib/arm... libsfml.so
class Sound
{
    public:
        Sound();
        int init_sound();
        void play_fond();
        void play_begin();
        void play_newBall();
    protected:

    private:
        sf::SoundBuffer buffer_dem;
        sf::SoundBuffer buffer_fond;
        sf::SoundBuffer buffer_newBall;
        sf::Sound fond;
        sf::Sound demarrage;
        sf::Sound newBall;
};

#endif // SOUND_H
