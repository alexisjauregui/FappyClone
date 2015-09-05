//
// Created by Alexis Jauregui on 8/31/15.
//

#ifndef FLAPPY1_PIPES_H
#define FLAPPY1_PIPES_H


#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Pipes {
public:
    Pipes();
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);

    sf::Sprite pipeb0;
    sf::Sprite pipet0;

    sf::Sprite pipeb1;
    sf::Sprite pipet1;

    sf::Sprite pipeb2;
    sf::Sprite pipet2;

private:
    sf::Texture texture;
    std::vector<float> levels;
    int newLvl;
    bool moveit;

};


#endif //FLAPPY1_PIPES_H
