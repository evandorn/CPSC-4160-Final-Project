#ifndef __MYSPRITE__
#define __MYSPRITE__

#include <string>
#include "cocos2d.h"

class MySprite {
public:
  MySprite(const std::string&, int, cocos2d::Point);
  virtual ~MySprite() {}
  virtual void update(float);
  cocos2d::Point getOrigin()  const { return origin; }
  cocos2d::Size getViewSize() const { return viewSize; }
  virtual cocos2d::Sprite* getSprite() const { return sprite; }
  cocos2d::Vec2 getVelocity() const { return velocity; }
    void setVelocity(cocos2d::Vec2 velocity);

private:
  int spriteWidth;
  int spriteHeight;

protected:
  cocos2d::Size viewSize;
  cocos2d::Point origin;
  cocos2d::Sprite* sprite;
  cocos2d::Vec2 velocity;
  cocos2d::Vector<cocos2d::SpriteFrame*> getFrames(const char *, int);

};
#endif
