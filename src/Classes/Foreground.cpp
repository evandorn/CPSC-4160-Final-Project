#include "Foreground.h"

bool Foreground::init() {
  if ( !Layer::init() ) return false;
    
  closeItem = cocos2d::MenuItemImage::create(
    "Resources/CloseNormal.png",
    "Resources/CloseSelected.png",
    CC_CALLBACK_1(Foreground::menuCloseCallback, this));
  closeItem->setPosition(visibleSize.width - closeItem->getContentSize().width/2, closeItem->getContentSize().height/2);

  menu = cocos2d::Menu::create(closeItem, NULL);
  menu->setPosition(cocos2d::Vec2::ZERO);
  addChild(menu, 1);

label = cocos2d::Label::createWithTTF("Evan Dorn, Chris Cornejo, Ryan Adventuranza.\n\n Project 5 Game - Gotta Catch 'Em All!",
                                          "fonts/Pokemon GB.ttf", 20);
  label->setPosition(visibleSize.width/2,
    visibleSize.height - label->getContentSize().height);
  addChild(label, 1);

  label->setTextColor(cocos2d::Color4B::WHITE);

  return true;
}

void Foreground::menuCloseCallback(Ref* pSender) {
  cocos2d::Director::getInstance()->end();
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
  #endif
}

