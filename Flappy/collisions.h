//
// Created by Alexis Jauregui on 9/1/15.
//

#ifndef FLAPPY1_COLLISIONS_H
#define FLAPPY1_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bird.h"
#include "Pipes.h"

class collisions {
public:
    bool coll(sf::Sprite* bird,sf::Sprite* pipe);
    void check(Pipes *pipe1,bird *bird1,bool* done,int *i);
    sf::FloatRect newB;

};


#endif //FLAPPY1_COLLISIONS_H
