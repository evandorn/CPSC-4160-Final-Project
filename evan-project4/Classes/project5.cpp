#include <iostream>
#include "project5.h"
#include "PokemonSprite.h"
#include "TrainerSprite.h"
#include <time.h>


Project4::~Project4() {
  std::list<MySprite*>::iterator ptr = sprites.begin();
  while ( ptr != sprites.end() ) {
    delete (*ptr);
    ++ptr;
  }
}

void Project4::update(float dt) {
  std::list<MySprite*>::iterator trainerSprite = sprites.begin();
  std::list<MySprite*>::iterator ptr = sprites.begin();
  ++ptr;
  (*trainerSprite)->update(dt);
  while ( ptr != sprites.end() ) {
    (*ptr)->update(dt);
    ++ptr;
  }
}

void Project4::generatePokemon() {
  MySprite *arcanineSprite;
  MySprite *moltresSprite;
  MySprite *articunoSprite;
  MySprite *dragoniteSprite;
    // Case 1
    arcanineSprite =
      new PokemonSprite("arcanine", 2, cocos2d::Point(1024, 415));
    sprites.push_back(arcanineSprite);
    addChild(arcanineSprite->getSprite());
    moltresSprite =
    new PokemonSprite("moltres", 2, cocos2d::Point(1024, 530));
    sprites.push_back(moltresSprite);
    addChild(moltresSprite->getSprite());
    articunoSprite =
    new PokemonSprite("articuno", 2, cocos2d::Point(1024, 320));
    sprites.push_back(articunoSprite);
    addChild(articunoSprite->getSprite());
    dragoniteSprite =
    new PokemonSprite("dragonite", 2, cocos2d::Point(1024, 470));
    sprites.push_back(dragoniteSprite);
    addChild(dragoniteSprite->getSprite());
}

// 'scene' and 'layer' are autorelease objects
cocos2d::Scene* Project4::createScene() {
  cocos2d::Scene* scene = cocos2d::Scene::create();
  Project4* layer = Project4::create();
  scene->addChild(layer);
  return scene;
}

bool Project4::init() {
  // 1. init the super class manually first because we don't
  //    believe in using constructors properly ;-)
  if ( !Layer::init() ) {
    return false;
  }
    
  cocos2d::Size visibleSize = 
    cocos2d::Director::getInstance()->getVisibleSize();
  cocos2d::Vec2 origin = 
    cocos2d::Director::getInstance()->getVisibleOrigin();

  // 2. add a menu item with "X" image, which is clicked to quit;
  //    you may modify it.
  // add a "close" icon to exit the progress. it's an autorelease object
  cocos2d::MenuItemImage* closeItem = 
    cocos2d::MenuItemImage::create( "CloseNormal.png", "CloseSelected.png",
                     CC_CALLBACK_1(Project4::menuCloseCallback, this));
    
	closeItem->setPosition(cocos2d::Vec2(origin.x + 
     visibleSize.width - closeItem->getContentSize().width/2,
     origin.y + closeItem->getContentSize().height/2));

  // create menu, it's an autorelease object
  cocos2d::Menu* menu = cocos2d::Menu::create(closeItem, NULL);
  menu->setPosition(cocos2d::Vec2::ZERO);
  addChild(menu, 1);

  // 3. add your codes below...

  // create and initialize a label
    cocos2d::Label * label =
    cocos2d::Label::createWithTTF("Evan Dorn, Chris Cornejo, Ryan Adventuranza.\n\n Project 5 Game - Gotta Catch 'Em All!",
                                  "fonts/Pokemon GB.ttf", 20);
    
  // position the label on the center of the screen
  label->setPosition(cocos2d::Vec2(origin.x + visibleSize.width/2,
    origin.y + visibleSize.height - label->getContentSize().height));

  // add the label as a child to this layer
  addChild(label, 1);


  // add background screen:
  background = cocos2d::Sprite::create("bridge.png");

  // position the sprite on the center of the screen
  background->setPosition(cocos2d::Vec2(visibleSize.width/2 + origin.x,
                                    visibleSize.height/2 + origin.y));

  // add the sprite as a child to this layer
  addChild(background, 0);

  MySprite * newSprite =
    new TrainerSprite("bike", 3, cocos2d::Point(1015,360));
  sprites.push_back( newSprite );
  addChild(newSprite->getSprite());

  generatePokemon();
  schedule( schedule_selector(Project4::update) );
    generatePokemon();
    
  return true;
}



void Project4::menuCloseCallback(Ref* pSender) {
  cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}
