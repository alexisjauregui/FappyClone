//
// Created by Alexis Jauregui on 8/31/15.
//

#include "Pipes.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

Pipes::Pipes() {
        if(!texture.loadFromFile("media/temppipe.png"))
          std::cout<<"Image not found for player"<<std::endl;

    std::ifstream openfile("media/levels.txt");
    levels.clear();
    if(openfile.is_open())
    {
        float value;
        while (openfile>>value) {
            levels.push_back(value);
        }
    }

    for(int i = 0; i<levels.size();i++){
        std::cout<<levels[i]<<std::endl;
    }


        pipeb0.setTexture(texture);
        pipeb0.setPosition(501 , 350);
        pipet0.setTexture(texture);
        pipet0.setPosition(576 , 250);
        pipet0.setRotation(180);

        pipeb1.setTexture(texture);
        pipeb1.setPosition(702 , 300);

        pipet1.setTexture(texture);
        pipet1.setPosition(777 , 200);
        pipet1.setRotation(180);

        pipeb2.setTexture(texture);
        pipeb2.setPosition(900 , 400);

        pipet2.setTexture(texture);
        pipet2.setPosition(970 , 300);
        pipet2.setRotation(180);

        newLvl = 0;


        moveit = false;




}

void Pipes::Update(sf::RenderWindow* window) {
    if(pipeb0.getPosition().x<-100){
        pipeb0.setPosition(window->getSize().x+150,levels[newLvl]);
        pipet0.setPosition(pipeb0.getPosition().x+75,pipeb0.getPosition().y-150);
        newLvl++;
    }
    if(pipeb1.getPosition().x<-100){
        pipeb1.setPosition(window->getSize().x+150,levels[newLvl]);
        pipet1.setPosition(pipeb1.getPosition().x+75,pipeb1.getPosition().y-150);
        newLvl++;
    }
    if(pipeb2.getPosition().x<-100){
        pipeb2.setPosition(window->getSize().x+150,levels[newLvl]);
        pipet2.setPosition(pipeb2.getPosition().x+75,pipeb2.getPosition().y-150);
        newLvl++;
    }

    std::cout<<pipeb0.getPosition().y<<std::endl;





    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        moveit = true;
    }
    if(moveit){
        pipet0.move(-3,0);
        pipeb0.move(-3,0);
        pipet1.move(-3,0);
        pipeb1.move(-3,0);
        pipet2.move(-3,0);
        pipeb2.move(-3,0);
    }


}

void Pipes::Render(sf::RenderWindow *window) {
    window->draw(pipet0);
    window->draw(pipeb0);
    window->draw(pipet1);
    window->draw(pipeb1);
    window->draw(pipet2);
    window->draw(pipeb2);

}
