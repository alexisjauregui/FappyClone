//
// Created by Alexis Jauregui on 8/30/15.
//

#include "background.h"


background::background() {
    if(!grassT.loadFromFile("media/grass.png"))
        std::cout<<"Image not found for player"<<std::endl;

    for(int i = 0; i < 2;i++){
        grass[i].setTexture(grassT);
        grass[i].setPosition({static_cast<float>(i*450),500});
    }
    base.setSize({405,109});
    base.setPosition(0,500);
    base.setFillColor(sf::Color(235,215,125));

}

void background::Update(sf::RenderWindow *window) {

        for(int i = 0; i < 2;i++) {
            grass[i].move(-2,0);
            if(grass[i].getPosition().x<-450){
                grass[i].setPosition(window->getSize().x+40,500);
            }
        }




}

void background::Render(sf::RenderWindow *window) {
    //window->draw(backS);
    window->draw(base);
    for(int i = 0; i < 2;i++) {
        window->draw(grass[i]);
    }


}
