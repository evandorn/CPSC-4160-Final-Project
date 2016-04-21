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

  addChild(foreground   = Foreground::create(),   1);
  addChild(background   = Background::create(),  -1);
    
  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/theme_music.mp3", true);
    
//    MySprite *trainerSprite =
//    new TrainerSprite("bike", 3, cocos2d::Point(100,170));
//    sprites.push_back(trainerSprite);
//    addChild(trainerSprite->getSprite());    
    
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
  foreground->update(dt);
  background->update(dt);
    
    std::list<MySprite*>::iterator trainerSprite = sprites.begin();
    std::list<MySprite*>::iterator ptr = sprites.begin();
    ++ptr;
    static_cast<TrainerSprite*>(*trainerSprite)->update(dt);
    while ( ptr != sprites.end() ) {
        static_cast<PokemonSprite*>(*ptr)->update(dt);
        ++ptr;
    }
}

