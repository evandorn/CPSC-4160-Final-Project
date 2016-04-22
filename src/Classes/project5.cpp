#include <iostream>
#include <SimpleAudioEngine.h>
#include <time.h>

#include "PokemonSprite.h"
#include "TrainerSprite.h"
#include "Project5.h"
#include "smartPokemon.h"

Project5::~Project5() {
    std::list<MySprite*>::iterator ptr = sprites.begin();
    while ( ptr != sprites.end() ) {
        delete (*ptr);
        ++ptr;
    }
    // collideLabel->release();
    countLabel->release();
}

cocos2d::Scene* Project5::createScene() {
  cocos2d::Scene* scene = cocos2d::Scene::create();
  cocos2d::Layer* layer = Project5::create();
  scene->addChild(layer);
  return scene;
}

bool Project5::init() {
  if ( !Layer::init() ) return false;
    
  visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
  origin      = cocos2d::Director::getInstance()->getVisibleOrigin();

  addChild(background   = Background::create(),  -1);
    
  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/theme_music.mp3", true);
    
//    MySprite *trainerSprite =
//    new TrainerSprite("bike", 3, cocos2d::Point(100,170));
//    sprites.push_back(trainerSprite);
//    addChild(trainerSprite->getSprite());    
    
    
    closeItem = cocos2d::MenuItemImage::create("Resources/CloseNormal.png",
                                               "Resources/CloseSelected.png",
                                               CC_CALLBACK_1(Project5::menuCloseCallback, this));
    closeItem->setPosition(visibleSize.width - closeItem->getContentSize().width/2, closeItem->getContentSize().height/2);
    
    menu = cocos2d::Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    addChild(menu, 1);
    
    label = cocos2d::Label::createWithTTF("Evan Dorn, Chris Cornejo, Ryan Venturanza.\n\n Project 5 Game - Gotta Catch 'Em All!",
                                          "fonts/Pokemon GB.ttf", 20);
    label->setPosition(visibleSize.width/2,
                       visibleSize.height - label->getContentSize().height);
    addChild(label, 1);
    
    label->setTextColor(cocos2d::Color4B::WHITE);
    
    
#pragma - collideLabel for debugging.
    
    /*
    collideLabel =
    cocos2d::Label::createWithTTF("Collision", "fonts/Marker Felt.ttf",24);
    collideLabel->setPosition(cocos2d::Vec2(origin.x + visibleSize.width/4,
                                            origin.y + visibleSize.height - label->getContentSize().height-20));
    collideLabel->retain();
    */
    
    scoreLabel =
    cocos2d::Label::createWithTTF("Score: ", "fonts/Pokemon GB.ttf",24);
    scoreLabel->setPosition(cocos2d::Vec2(origin.x + visibleSize.width/8,
                                          origin.y + visibleSize.height - label->getContentSize().height-50));
    addChild(scoreLabel,1);

    
    countLabel =
    cocos2d::Label::createWithTTF("0", "fonts/Pokemon GB.ttf",24);
    countLabel->setPosition(cocos2d::Vec2(origin.x + visibleSize.width/4,
                                          origin.y + visibleSize.height - label->getContentSize().height-50));
    addChild(countLabel,1);

    
    
  generatePokemon();
  scheduleUpdate();

  return true;
}

void Project5::generatePokemon() {
    
    
    srand(time(NULL));
    int randNumx = rand()%(1500-100 + 1) + 100;
    int randNumx2 = rand()%(1500-100 + 1) + 100;
    int randNumx3 = rand()%(1500-100 + 1) + 100;
    
    int randNumy = rand()%(150-50 + 1) + 50;
    int randNumy2 = rand()%(150-50 + 1) + 50;
    int randNumy3 = rand()%(150-50 + 1) + 50;
    
    

  
    MySprite *arcanineSprite;
    MySprite *moltresSprite;
    MySprite *articunoSprite;
    MySprite *dragoniteSprite;

   // MySprite *articunoSmart;
    
    MySprite *trainerSprite =
    new TrainerSprite("bike", 3, cocos2d::Point(100,170));
    sprites.push_back(trainerSprite);
    addChild(trainerSprite->getSprite(),0);

    // Case 1
    arcanineSprite =
    new PokemonSprite("arcanine", 2, cocos2d::Point(randNumx2, randNumy2));
    sprites.push_back(arcanineSprite);
    addChild(arcanineSprite->getSprite());
    moltresSprite =
    new PokemonSprite("moltres", 2, cocos2d::Point(randNumx3, randNumy3));
    sprites.push_back(moltresSprite);
    addChild(moltresSprite->getSprite());
    
   //NEW SMART POKEMON
    articunoSprite =
    new SmartPokemon("articuno", 2, cocos2d::Point(1024, 150), trainerSprite);
    sprites.push_back(articunoSprite);
    addChild(articunoSprite->getSprite(),0);

    dragoniteSprite =
    new PokemonSprite("dragonite", 2, cocos2d::Point(randNumx, randNumy));
    sprites.push_back(dragoniteSprite);
    addChild(dragoniteSprite->getSprite());


}


void Project5::update(float dt) {

    bool collision = false;
    
  background->update(dt);

    std::list<MySprite*>::iterator trainerSprite = sprites.begin();
    std::list<MySprite*>::iterator ptr = sprites.begin();
    ++ptr;
    static_cast<TrainerSprite*>(*trainerSprite)->update(dt);
    while ( ptr != sprites.end() ) {
        static_cast<PokemonSprite*>(*ptr)->update(dt);
        // Adding collisions
        if ( (*trainerSprite)->collidedRect(*ptr) ) {
            std::cout << "Collision!";
            collision = true;
            collideCount += 1;
            std::stringstream strm;
            strm << collideCount;
            countLabel->setString(strm.str());
    }
        ++ptr;
  }

        if ( collision && !labelDrawn ) {
            //addChild(collideLabel);
            labelDrawn = true;
        }
        else if ( !collision && labelDrawn ) {
            // removeChild(collideLabel, 1);
            labelDrawn = false;
        }
}

void Project5::menuCloseCallback(Ref* pSender) {
    cocos2d::Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
