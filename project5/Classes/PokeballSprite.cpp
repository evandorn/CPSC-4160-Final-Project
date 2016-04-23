//
//  PokeballSprite.cpp
//  asg5
//
//  Created by Evan Dorn on 4/22/16.
//
//

#include "PokeballSprite.h"

PokeballSprite::PokeballSprite(const std::string& name, int noFrames, cocos2d::Point pos) :
MySprite::MySprite(name, noFrames, pos) {
}

void PokeballSprite::update(float dt) {
    cocos2d::Vec2 position = sprite->getPosition();
    position.x = position.x - 200 * -(dt);
    
    if (position.x  < 0 - (sprite->getBoundingBox().size.width / 2)) {
        position.x  = 1030;
    }
    if (dt < 0 && position.x  > getViewSize().width) {
        position.x = 1030;
    }
    sprite->setPosition(position);
}
