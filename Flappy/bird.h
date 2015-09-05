//
// Created by Alexis Jauregui on 8/29/15.
//

#ifndef FLAPPY1_BIRD_H
#define FLAPPY1_BIRD_H

#include <iostream>
#include <SFML/Graphics.hpp>


class bird {
public:
    bird(sf::RenderWindow* window);


    void Update(sf::RenderWindow* window);
    void Fall(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);


    sf::Vector2f velocity;
    const sf::Vector2f gravity{0,11.0};
    const float maxY = 50;
    bool keyclicked;
    bool start;
    sf::Clock clock1;
    float frameCounter =0 , switchFrame= 100, frameSpeed = 750;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite birdBox;
    sf::Vector2i source;

    float rotX;
};


#endif //FLAPPY1_BIRD_H
