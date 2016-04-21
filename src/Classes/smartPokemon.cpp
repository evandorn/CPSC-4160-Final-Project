//
//  smartPokemon.cpp
//  project4
//
//  Created by Christopher Cornejo on 4/20/16.
//
//

#include "smartPokemon.h"
#include <iostream>
#include <cmath>


SmartPokemon::SmartPokemon(const std::string& filename, int noFrames,
                     cocos2d::Point pos, const MySprite* e) :
PokemonSprite(filename, noFrames, pos),
enemy(e),
evade(false),
maxDist(150)
{ }

void SmartPokemon::update(float dt) {
    auto position = sprite->getPosition();
    cocos2d::Vec2 incr = velocity * dt;
    sprite->setPosition(position.x + incr.x, position.y + incr.y );
    
    cocos2d::Point location = getSprite()->getPosition();
    cocos2d::Point enemyLoc = enemy->getSprite()->getPosition();
    std::cout<<&enemyLoc; 
    
    evade = ((enemyLoc.x-location.x)*(enemyLoc.x-location.x) +
             (enemyLoc.y-location.y)*(enemyLoc.y-location.y)) < maxDist*maxDist;
    
    if(evade) {
        std::cout<<"run!";
        if((location.x > enemyLoc.x && velocity.x < 0) ||
           (location.x < enemyLoc.x && velocity.x > 0) ) {
            velocity.x = -1*velocity.x;
            sprite->setScaleX(sprite->getScaleX() * -1);
        }
        if((location.y > enemyLoc.y && velocity.y < 0) ||
           (location.y < enemyLoc.y && velocity.y > 0) )
            velocity.y = -1*velocity.y;
    }
    
    PokemonSprite::update(dt);
}
