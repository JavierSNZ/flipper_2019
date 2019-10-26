#include "SFML/Audio.hpp"
#include <iostream>

int init_sound()
{
    sf::SoundBuffer buffer_dem;
    sf::SoundBuffer buffer_fond;
    sf::Sound fond;
    sf::Sound demarrage;
    
    if (!buffer_dem.loadFromFile("../sons/demarragelong.wav")) {
        std::cerr << "erreur, impossible de charger le son" << std::endl;
        exit(84);
    }
    if (!buffer_fond.loadFromFile("../sons/musiquedeFond1.wav")) {
        std::cerr << "erreur, impossible de charger le son" << std::endl;
        exit(84);
    }
    demarrage.setBuffer(buffer_dem);
    fond.setBuffer(buffer_fond);
}

int main()
{
    init_sound();
}