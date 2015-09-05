//
// Created by Alexis Jauregui on 8/30/15.
//

#ifndef FLAPPY1_BACKGROUND_H
#define FLAPPY1_BACKGROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>

class background {
public:
    background();
    void Update(sf::RenderWindow *window);
    void Render(sf::RenderWindow* window);


private:
    sf::RectangleShape base;
    sf::Sprite grass[2];
    sf::Texture grassT;



};


#endif //FLAPPY1_BACKGROUND_H
