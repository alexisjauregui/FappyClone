//
// Created by Alexis Jauregui on 8/30/15.
//

#include "Score.h"

Score::Score(sf::RenderWindow* window) {
    font.loadFromFile("media/Pacifico.ttf");
    this->setFont(font);
    this->setPosition({static_cast<float>(window->getSize().x/2),50});
    this->setString("0");
    this->setCharacterSize(100);
    this->Win = new sf::Text("You Win",font,100);
    this->Win->setPosition({static_cast<float>(window->getSize().x/2),0});



}

void Score::Update(int *i,sf::RenderWindow* window) {
    this->setString(std::to_string(*i));

    if(*i == 711){
        window->draw(*this->Win);
    }
}


