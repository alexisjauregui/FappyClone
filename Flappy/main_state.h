//
// Created by Alexis Jauregui on 8/28/15.
//

#ifndef FLAPPY1_MAIN_STATE_H
#define FLAPPY1_MAIN_STATE_H

#include <iostream>
#include "game_state.h"
#include "game.h"


class main_state: public tiny_state
{
public:

    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);


private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* play;
    sf::Text* quit;

    sf::Texture back;
    sf::Texture grass;
    sf::RectangleShape*  sand;
    sf::Sprite* grassS;
    sf::Sprite* backS;

    int selected;
    bool upKey;
    bool downKey;
    bool RKey;

    sf::Clock time;
};

#endif //FLAPPY1_MAIN_STATE_H
