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
                     cocos2d::Point pos, const MySprite* e) : // e is enemy
PokemonSprite(filename, noFrames, pos),
enemy(e),
evade(false),
maxDist(150)
{ }

void SmartPokemon::update(float dt) {
    cocos2d::Vec2 position = sprite->getPosition();
    cocos2d::Vec2 incr = velocity * dt;
    static bool switcher = false;
    static int bounds = 0;  //prevents evade from getting called multiple times
    
    cocos2d::Point location = getSprite()->getPosition();
    cocos2d::Point enemyLoc = enemy->getSprite()->getPosition();

    evade = (((enemyLoc.x-location.x)*(enemyLoc.x-location.x) +
             (enemyLoc.y-location.y)*(enemyLoc.y-location.y)) < (maxDist*maxDist));

   if(evade && bounds == 0) { //force this to be called only once
        if (switcher == true) {
           switcher = false;  
        }
        else {
        switcher = true;
        }

        sprite->setScaleX(sprite->getScaleX() * -1); // only setting for one smartpokemon sprite
        bounds = bounds + 150;
    }

   if (!switcher) {
      PokemonSprite::update(dt); // goes to the left
        if (bounds > 0)
           bounds--;
   }

   if (switcher) {
      PokemonSprite::update(-dt); //makes it go right
        if (bounds > 0)
           bounds--;
   }


}
