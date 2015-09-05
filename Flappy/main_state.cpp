//
// Created by Alexis Jauregui on 8/28/15.
//

#include "main_state.h"

void main_state::Initialize(sf::RenderWindow* window)
{


    this->selected = 0;

    this->font= new sf::Font();
    this->font->loadFromFile("media/Pacifico.ttf");

    this->title = new sf::Text("Flappy Ave",*this->font,80U);
    this->title->setOrigin(this->title->getGlobalBounds().width/2,this->title->getGlobalBounds().height/2);
    this->title->setPosition(window->getSize().x/2,window->getSize().y/8);

    this->play = new sf::Text("Play",*this->font, 60U);
    this->play->setOrigin(this->play->getGlobalBounds().width/2,this->play->getGlobalBounds().height/2);
    this->play->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.40));


    this->quit = new sf::Text("Quit",*this->font,60U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width/2,this->quit->getGlobalBounds().height/2);
    this->quit->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.60));


    if(!back.loadFromFile("media/back2.png"))
        std::cout<<"Image not found for player"<<std::endl;
    this->backS = new sf::Sprite;
    this->backS->setTexture(back);



    this->sand = new sf::RectangleShape();
    this->sand->setSize({405,109});
    this->sand->setPosition(0,500);
    this->sand->setFillColor(sf::Color(235,215,125));

    if(!grass.loadFromFile("media/grass.png"))
        std::cout<<"Image not found for player"<<std::endl;
    this->grassS = new sf::Sprite;
    this->grassS->setTexture(grass);
    this->grassS->setPosition(0,500);

    time.restart();



}

void main_state::Update(sf::RenderWindow* window)
{

    //std::cout<<time.getElapsedTime().asSeconds()<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) and !this->upKey){
        this->selected -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) and !this->downKey){
        this->selected += 1;
    }
    if(selected < 0){
        this->selected = 1;


    }
    if(selected > 1){
        this->selected = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) and time.getElapsedTime().asSeconds() >1){
        switch (this->selected) {
            case 0:
                coreState.set_state(new game());
                std::cout<<"here"<<std::endl;
                break;
            case 1:
                quit_game = true;
                break;
            default:
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

}
void main_state::Render(sf::RenderWindow* window){
    this->play->setColor(sf::Color::White);
    this->quit->setColor(sf::Color::White);

    switch (this->selected) {
        case 0:
            this->play->setColor(sf::Color::Yellow);
            break;
        case 1:
            this->quit->setColor(sf::Color::Yellow);
            break;
        default:
            this->play->setColor(sf::Color::Yellow);
            break;


    }
    window->draw(*this->backS);
    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);
    window->draw(*this->sand);
    window->draw(*this->grassS);


}
void main_state::Destroy(sf::RenderWindow* window){

    delete this->font;
    delete this->title;
    delete this->play;
    delete this->quit;


}