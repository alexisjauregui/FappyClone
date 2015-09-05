//
// Created by Alexis Jauregui on 9/1/15.
//

#include "collisions.h"


bool collisions::coll(sf::Sprite* bird, sf::Sprite* pipe) {

   newB.top = bird->getGlobalBounds().top+10;
    newB.left = bird->getGlobalBounds().left+10;
    newB.height = bird->getGlobalBounds().height-20;
    newB.width = bird->getGlobalBounds().width-20;


    if(newB.intersects(pipe->getGlobalBounds())){
        return true;
    } else {

        return false;
    }

}

void collisions::check(Pipes *pipe1, bird *bird1,bool* done, int *i) {
    if(coll(&pipe1->pipeb0,&bird1->sprite) or coll(&pipe1->pipet0,&bird1->sprite) or
       coll(&pipe1->pipeb1,&bird1->sprite) or coll(&pipe1->pipet1,&bird1->sprite) or
       coll(&pipe1->pipeb2,&bird1->sprite) or coll(&pipe1->pipet2,&bird1->sprite)){
        //std::cout<<"yes"<<std::endl;
       //*done = true;

    }
 // Scoring
    if(pipe1->pipeb0.getPosition().x == bird1->sprite.getPosition().x -1 or
       pipe1->pipeb1.getPosition().x == bird1->sprite.getPosition().x -1 or
       pipe1->pipeb2.getPosition().x == bird1->sprite.getPosition().x -1
            ){
        *i  = *i +1;

    }

    coll(&pipe1->pipeb1,&bird1->sprite);
    coll(&pipe1->pipet1,&bird1->sprite);
    coll(&pipe1->pipet2,&bird1->sprite);
    coll(&pipe1->pipeb2,&bird1->sprite);


}
