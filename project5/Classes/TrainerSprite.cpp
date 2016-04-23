//
//  TrainerSprite.cpp
//  asg4
//
//  Created by Evan Dorn on 4/10/16.
//
//

#include "TrainerSprite.h"
#include <iostream>

TrainerSprite::TrainerSprite(const std::string& name, int noFrames, cocos2d::Point pos) :
	MySprite::MySprite(name, noFrames, pos),
	moveLeft(false), moveRight(false), moveUp(false), moveDown(false),
	saveVelocity( getVelocity() ) {

cocos2d::EventListenerKeyboard* l = cocos2d::EventListenerKeyboard::create();

   l->onKeyPressed =
    [this](cocos2d::EventKeyboard::KeyCode keyCode,cocos2d::Event* event) {
    switch(keyCode) {
      case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_A:
	      moveLeft = true;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_D:
	      moveRight = true;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_S:
	      moveDown = true;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_W:
	      moveUp = true;
	      break;
       case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
        default:
	      break;
    }
   };

  l->onKeyReleased =
    [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event){
    switch(keyCode) {
      case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_A:
	      moveLeft = false;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_D:
	      moveRight = false;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_S:
	      moveDown = false;
	      break;
      case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	    case cocos2d::EventKeyboard::KeyCode::KEY_W:
	      moveUp = false;
	      break;
	    default:
	      break;
    }
  };

  cocos2d::Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(l, 1);
  
}

void TrainerSprite::update(float dt) {
static bool flipper = false;

  if(!moveLeft && !moveRight) { // this all isn't working, not getting called D:
    velocity.set(0, 0); //something velocity, this isnt saving up in base class
  }
  if(moveLeft && !moveRight) {
    velocity.set(-std::abs(saveVelocity.x), velocity.y);
    if (flipper == false) {
       sprite->setScaleX(sprite->getScaleX() * -1);
       flipper = true;
    }
  }
  if(moveRight && !moveLeft) {
    velocity.set(std::abs(saveVelocity.x), velocity.y);
    if (flipper == true) {
       sprite->setScaleX(sprite->getScaleX() * -1);
       flipper = false;
    }
  }
  if(moveDown && !moveUp) {
    velocity.set(velocity.x, -std::abs(saveVelocity.y));
  }
  if(moveUp && !moveDown) {
    velocity.set(velocity.x, std::abs(saveVelocity.y));
  }
  MySprite::update(dt);

}
