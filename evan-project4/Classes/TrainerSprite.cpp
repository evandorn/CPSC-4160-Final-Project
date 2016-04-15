//
//  TrainerSprite.cpp
//  asg4
//
//  Created by Evan Dorn on 4/10/16.
//
//

#include "TrainerSprite.h"

TrainerSprite::TrainerSprite(const std::string& name, int noFrames, cocos2d::Point pos) :
MySprite::MySprite(name, noFrames, pos) {
}

void TrainerSprite::update(float dt) {
    cocos2d::Vec2 position = sprite->getPosition();
    position.x -= 150 * dt;
    if (position.x  < -10 - (sprite->getBoundingBox().size.width / 2)) {
        position.x = 1025;
    }
    sprite->setPosition(position);
}