//
//  smartPokemon.cpp
//  project4
//
//  Created by Christopher Cornejo on 4/20/16.
//
//

#include "smartPokemon.h"
#include "mySprite.h"
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
    cocos2d::Vec2 position = sprite->getPosition();
    cocos2d::Vec2 incr = velocity * dt;
    
    // sprite->setPosition(position.x + incr.x, position.y + incr.y);
    
    cocos2d::Point location = getSprite()->getPosition();
    cocos2d::Point enemyLoc = enemy->getSprite()->getPosition();

    evade = ((enemyLoc.x-location.x)*(enemyLoc.x-location.x) +
             (enemyLoc.y-location.y)*(enemyLoc.y-location.y)) < maxDist*maxDist;
    
    if(evade) {
        if((location.x > enemyLoc.x && velocity.x < 0) ||
           (location.x < enemyLoc.x && velocity.x > 0) ) {
            setVelocity(velocity*-1);
            sprite->setScaleX(sprite->getScaleX() * -1);
            // sprite->setPosition(velocity.x, position.y);
            // sprite = setVelocity(velocity*-1);
            sprite->setPosition(velocity.x * -1, position.y);
        }
        if((location.y > enemyLoc.y && velocity.y < 0) ||
           (location.y < enemyLoc.y && velocity.y > 0) )
            velocity.y = -1*velocity.y;
    }
    
    PokemonSprite::update(dt);
}
