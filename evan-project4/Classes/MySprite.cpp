#include <iostream>
#include "MySprite.h"

MySprite::MySprite(const std::string& name, int noFrames, 
                   cocos2d::Point pos) :
  viewSize( cocos2d::Director::getInstance()->getVisibleSize() ),
  origin( cocos2d::Director::getInstance()->getVisibleOrigin() )
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
