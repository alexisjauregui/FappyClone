//
// Created by Alexis Jauregui on 8/28/15.
//

#include "game.h"


void game::Initialize(sf::RenderWindow *window) {


    this->bird1 = new bird(window);
    this->background1 = new background();
    this->score1 = new Score(window);
    this->pipes1 = new Pipes();
    this->collisions1 = new collisions();
    done = false;


    if(!back.loadFromFile("media/back2.png"))
        std::cout<<"Image not found for player"<<std::endl;
    this->backS = new sf::Sprite;
    this->backS->setTexture(back);


    board.setSize({300,300});
    board.setFillColor(sf::Color(20,100,150,80));
    board.setOrigin(board.getGlobalBounds().width/2,board.getGlobalBounds().height/2);
    board.setPosition({static_cast<float>(window->getSize().x/2), static_cast<float >(window->getSize().y/2)});


    if(!font1.loadFromFile("media/Pacifico.ttf"))
        std::cout<<"Font not found for player"<<std::endl;

    this->text1 = new sf::Text("The Bird is Dead\n",font1,25);
    this->text1->setOrigin(this->text1->getGlobalBounds().width/2,this->text1->getGlobalBounds().height/2);
    this->text1->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.40));

    this->Replay = new sf::Text("PLay Again",font1, 25U);
    this->Replay->setOrigin(this->Replay->getGlobalBounds().width/2,this->Replay->getGlobalBounds().height/2);
    this->Replay->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.50));


    this->Quit = new sf::Text("Exit",font1,25U);
    this->Quit->setOrigin(this->Quit->getGlobalBounds().width/2,this->Quit->getGlobalBounds().height/2);
    this->Quit->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.60));

    this->Instruct = new sf::Text("Press Space to Start",font1,25u);
    this->Instruct->setOrigin(this->Instruct->getGlobalBounds().width/2,this->Instruct->getGlobalBounds().height/2);
    this->Instruct->setPosition(window->getSize().x/2, static_cast<float>(window->getSize().y*.60));


    i = 0;

}

void game::Update(sf::RenderWindow *window) {

    if(this->bird1->sprite.getPosition().y == window->getSize().y - 130){
        done = true;
    }

    if(done){
        // dont update
        this->bird1->Fall(window);
        ///////////////////////// END OF GAME POST
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
            switch (this->selected) {
                case 0:
                    Initialize(window);
                    break;
                case 1:
                    coreState.set_state(new main_state);
                    break;
                default:
                    break;
            }
        }

        this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
       //////////////////////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            coreState.set_state(new main_state);





    }else {

        this->bird1->Update(window);
        this->background1->Update(window);
        this->score1->Update(&i,window);
        this->pipes1->Update(window);
        this->collisions1->check(this->pipes1,this->bird1,&this->done,&i);
    }




}

void game::Render(sf::RenderWindow *window) {


    window->draw(*this->backS);
    this->pipes1->Render(window);
    this->bird1->Render(window);
    this->background1->Render(window);
    window->draw(*this->score1);

    if(done){
        window->draw(board);
        window->draw(*this->text1);
        this->Replay->setColor(sf::Color::White);
        this->Quit->setColor(sf::Color::White);

        switch (this->selected) {
            case 0:
                this->Replay->setColor(sf::Color::Yellow);
                break;
            case 1:
                this->Quit->setColor(sf::Color::Yellow);
                break;
            default:
                this->Replay->setColor(sf::Color::Yellow);
                break;


        }
        window->draw(*this->Replay);
        window->draw(*this->Quit);
    }

    if(!this->bird1->start){
        window->draw(*this->Instruct);
    }


}

void game::Destroy(sf::RenderWindow *window) {


}
