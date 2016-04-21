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
    if ( location.y > getViewSize().height - 220) {             // limits the sprite from going too far up
        getSprite()->setPosition(position.x, position.y);
    }
    if ( location.y < 320 ) {                                // limits the sprite from going too far down
        getSprite()->setPosition(position.x, position.y);
    }
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
