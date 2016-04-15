#ifndef __MYSPRITE__
#define __MYSPRITE__

#include <string>
#include "cocos2d.h"

class MySprite {
public:
  MySprite(const std::string&, int, cocos2d::Point);
  virtual ~MySprite() {}
  virtual void update(float) = 0;
  cocos2d::Point getOrigin()  const { return origin; }
  cocos2d::Size getViewSize() const { return viewSize; }
  cocos2d::Sprite* getSprite() const { return sprite; }
protected:
  cocos2d::Size viewSize;
  cocos2d::Point origin;
  cocos2d::Sprite* sprite;
  cocos2d::Vector<cocos2d::SpriteFrame*> getFrames(const char *, int);
};
#endif
