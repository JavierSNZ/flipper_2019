#include "SFML/Audio.hpp"
#include <iostream>
#include <Sound.h>

Sound::Sound(){
    init_sound();
}

int Sound::init_sound()
{

    if (!buffer_dem.loadFromFile("sons/demarrageCOC.wav")) {
        std::cerr << "erreur, impossible de charger le son" << std::endl;
        exit(84);
    }
    if (!buffer_fond.loadFromFile("sons/musiquedeFond1Noel.wav")) {
        std::cerr << "erreur, impossible de charger le son" << std::endl;
        exit(84);
    }
   if (!buffer_newBall.loadFromFile("sons/NoelDebut.wav")) {
        std::cerr << "erreur, impossible de charger le son" << std::endl;
        exit(84);
    }
}
//Obtenir la duree d'un son float duration = buffer.GetDuration();

void Sound::play_fond(){
    fond.setBuffer(buffer_fond);
    fond.play();
}
void Sound::play_begin(){
    demarrage.setBuffer(buffer_dem);
    demarrage.play();
}
void Sound::play_newBall(){
    newBall.setBuffer(buffer_newBall);
    newBall.play();
}
