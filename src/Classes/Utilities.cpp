#include "Utilities.h"

cocos2d::Vec2 origin;
cocos2d::Size visibleSize;

cocos2d::Sprite* stretchFit(cocos2d::Sprite* const sprite) {
  float xScale = visibleSize.width  / sprite->getContentSize().width;
  float yScale = visibleSize.height / sprite->getContentSize().height;

  sprite->setScale(xScale, yScale);
  return sprite;
}

float width(const cocos2d::Sprite* const sprite) {
  return sprite->getBoundingBox().getMaxX() - sprite->getBoundingBox().getMinX();
}

float  height(const cocos2d::Sprite* const sprite) {
  return sprite->getBoundingBox().getMaxY() - sprite->getBoundingBox().getMinY();
}

