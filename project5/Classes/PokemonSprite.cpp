//
//  PokemonSprite.cpp
//  asg4
//
//  Created by Evan Dorn on 4/10/16.
//
//

#include "PokemonSprite.h"

PokemonSprite::PokemonSprite(const std::string& name, int noFrames, cocos2d::Point pos) :
MySprite::MySprite(name, noFrames, pos) {
}

void PokemonSprite::update(float dt) { //makes it go left
    cocos2d::Vec2 position = sprite->getPosition();
    position.x = position.x - 200 * dt;

    if (position.x  < 0 - (sprite->getBoundingBox().size.width / 2)) {
        position.x = 1025;
    }
    if (dt < 0 && position.x  > getViewSize().width) {
        position.x = 0;
    } 
    sprite->setPosition(position);
}

