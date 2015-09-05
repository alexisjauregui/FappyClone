//
// Created by Alexis Jauregui on 8/29/15.
//

#include "bird.h"

bird::bird(sf::RenderWindow* window) {
     if(!texture.loadFromFile("media/bird.png"))
        std::cout<<"Image not found for player"<<std::endl;

    sprite.setTexture(texture);
    sprite.setPosition(100,window->getSize().y/4);
    sprite.setRotation(0);
    sprite.setTextureRect(sf::IntRect(source.x * 50,source.y * 25,50,25));




    rotX = 0;
    start = false;

}

void bird::Update(sf::RenderWindow* window) {



    if(start) {
        if (velocity.y < maxY) {
            velocity += gravity * clock1.restart().asSeconds();;

            sprite.setOrigin(sprite.getTextureRect().width/2,sprite.getTextureRect().width/2);
            sprite.setRotation(45);
        };
        sprite.move(velocity);
        if (sprite.getPosition().y > window->getSize().y - 130) {

            sprite.setPosition(100, window->getSize().y - 130);

        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        start = true;
        if(keyclicked) {
            velocity.y = -5;
            keyclicked = false;
        }
    }else{
        keyclicked = true;
    }

    if(velocity.y< 5 and start){
        sprite.setOrigin(sprite.getTextureRect().width/2,sprite.getTextureRect().width/2);
        if(rotX>-15)
            rotX--;
        sprite.setRotation(rotX);

        frameCounter += frameSpeed * clock1.restart().asSeconds();
        if(frameCounter>=switchFrame)
        {
            frameCounter = 0;
            source.x++;
            if(source.x * 50 >= texture.getSize().x)
                source.x=0;

        }
        sprite.setTextureRect(sf::IntRect(source.x * 50,source.y * 25,50,25));


    }
    if(velocity.y> 7){
   //     placer.setRotation(90);
        sprite.setOrigin(sprite.getTextureRect().width/2,sprite.getTextureRect().width/2);

        sprite.setRotation(90);
    }

   // std::cout<<sprite.getRotation()<<std::endl;
    if(sprite.getRotation() == 0 ){

        frameCounter += frameSpeed * clock1.restart().asSeconds();
        if(frameCounter>=switchFrame)
        {
            frameCounter = 0;
            source.x++;
            if(source.x * 50 >= texture.getSize().x)
                source.x=0;
            sprite.setTextureRect(sf::IntRect(source.x * 50,source.y * 25,50,25));



        }
    }



//std::cout<<velocity.y<<std::endl;

}

void bird::Fall(sf::RenderWindow *window) {
    if (velocity.y < maxY) {

        velocity += gravity * clock1.restart().asSeconds();;

        sprite.setOrigin(sprite.getTextureRect().width/2,sprite.getTextureRect().width/2);
        sprite.setRotation(90);
    };
    sprite.move(velocity);
    if (sprite.getPosition().y > window->getSize().y - 130) {

        sprite.setPosition(100, window->getSize().y - 130);

    }

}

void bird::Render(sf::RenderWindow *window) {

    window->draw(sprite);
}


