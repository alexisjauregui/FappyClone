//
// Created by Alexis Jauregui on 8/28/15.
//

#ifndef FLAPPY1_GAME_H
#define FLAPPY1_GAME_H


#include "game_state.h"
#include "bird.h"
#include "background.h"
#include "Score.h"
#include "Pipes.h"
#include "main_state.h"
#include "collisions.h"

#include <SFML/Graphics.hpp>


class game :public tiny_state{
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);



private:
    sf::RectangleShape board;
    sf::Font font1;
    sf::Text* text1;
    sf::Text* Replay;
    sf::Text* Quit;
    sf::Text* Instruct;
    int selected;
    bool upKey;
    bool downKey;

    bird* bird1;
    background* background1;
    Score* score1;
    Pipes* pipes1;
    bool done;
    collisions* collisions1;

    int i;
    sf::Texture back;
    sf::Sprite* backS;



};


#endif //FLAPPY1_GAME_H
