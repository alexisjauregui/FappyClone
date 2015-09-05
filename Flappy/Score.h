//
// Created by Alexis Jauregui on 8/30/15.
//

#ifndef FLAPPY1_SCORE_H
#define FLAPPY1_SCORE_H


#include <SFML/Graphics.hpp>

class Score: public sf::Text {
public:
    Score(sf::RenderWindow* window);
    void Update(int *i,sf::RenderWindow* window);


private:
    sf::Font font;
    sf::Text* Win;
};


#endif //FLAPPY1_SCORE_H
