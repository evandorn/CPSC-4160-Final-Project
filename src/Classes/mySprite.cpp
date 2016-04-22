#include <iostream>
#include "mySprite.h"


MySprite::MySprite(const std::string& name, int noFrames,
                   cocos2d::Point pos) :
viewSize( cocos2d::Director::getInstance()->getVisibleSize() ),
origin( cocos2d::Director::getInstance()->getVisibleOrigin() ),
velocity(rand()%150+100, rand()%150+100),
spriteWidth(0),
spriteHeight(0)
{
    
    std::string plistName = name +".plist";
    cocos2d::SpriteFrameCache::
    getInstance()->addSpriteFramesWithFile(plistName.c_str());
    
    // Set up the frames of animation:
    std::string filename = name + "%1d.png";
    cocos2d::Vector<cocos2d::SpriteFrame*>
    frames = getFrames(filename.c_str(), noFrames);
    
    sprite = cocos2d::Sprite::createWithSpriteFrame(frames.front());
    
    // Lower left corner is origin; put Alien at far right, center:
    sprite->setPosition(pos);
    
    cocos2d::Animation*
    animation = cocos2d::Animation::createWithSpriteFrames(frames, 1.0f/8);
    sprite->runAction(
                      cocos2d::RepeatForever::create(cocos2d::Animate::create(animation))
                      );
    
    spriteWidth = getSprite()->getContentSize().width;
    spriteHeight = getSprite()->getContentSize().height;
    
}

void MySprite::update(float dt) {
    cocos2d::Point position = getSprite()->getPosition();
    cocos2d::Vec2 incr = velocity * dt;
    getSprite()->setPosition(position.x + incr.x, position.y + incr.y );
    
    cocos2d::Point location = getSprite()->getPosition();
    
    if (location.x > getViewSize().width) {                // limits the sprite from going too far right
        getSprite()->setPosition(position.x, position.y);
    }
    if ( location.x < 0) {                                 // limits the sprite from going too far left
        getSprite()->setPosition(position.x, position.y);
    }
    if ( location.y > getViewSize().height - 600) {             // limits the sprite from going too far up
        getSprite()->setPosition(position.x, position.y);
    }
    if ( location.y < 0 ) {                                // limits the sprite from going too far down
        getSprite()->setPosition(position.x, position.y);
    }
}

void MySprite::setVelocity(cocos2d::Vec2 vel) {
    velocity = vel;
}

bool MySprite::collidedRect(const MySprite* otherSprite) const {
    int myWidth = sprite->getContentSize().width;
    int myHeight = sprite->getContentSize().height;
    int oWidth = otherSprite->getSprite()->getContentSize().width;
    int oHeight = otherSprite->getSprite()->getContentSize().height;
    
    cocos2d::Point myPos = sprite->getPosition();
    cocos2d::Point oPos  = otherSprite->getSprite()->getPosition();
    
    if ( myPos.x+myWidth/2 < oPos.x-oWidth/2 ) return false;
    if ( myPos.x-myWidth/2 > oPos.x+oWidth/2 ) return false;
    if ( myPos.y-myHeight/2 > oPos.y+oHeight/2 ) return false;
    if ( myPos.y+myHeight/2 < oPos.y-oHeight/2 ) return false;
    return true;
}

bool MySprite::collidedWith(const MySprite* otherSprite) const {
    cocos2d::Point myPos = sprite->getPosition();
    cocos2d::Point oPos  = otherSprite->getSprite()->getPosition();
    float x = myPos.x-oPos.x, y = myPos.y-oPos.y;
    float distance = hypot(x, y);
    float radii = otherSprite->getSprite()->getContentSize().width/2 +
    sprite->getContentSize().width/2;
    return distance < radii;
}


// Function getFrames marshals the sprite frames into a cocos
// vector using the format string passed to the function.
cocos2d::Vector<cocos2d::SpriteFrame*>
MySprite::getFrames(const char *format, int count) {
    
    cocos2d::SpriteFrameCache*
    spritecache = cocos2d::SpriteFrameCache::getInstance();
    cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
    char str[100];
    for(int i = 1; i <= count; i++) {
        sprintf(str, format, i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}
