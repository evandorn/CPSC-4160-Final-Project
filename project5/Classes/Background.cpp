#include "Background.h"

bool Background::init() {

  if ( !Layer::init() ) return false;

   bg1= cocos2d::Sprite::create("backgrounds/clouds.png");
  bg1->setPosition(0, visibleSize.height/2);
    
  bg2 = cocos2d::Sprite::create("backgrounds/clouds.png");
  bg2->setPosition(bg1->boundingBox().size.width - 1,visibleSize.height/2);

    grass1 = cocos2d::Sprite::create("backgrounds/background1.png");
    grass1->setPosition(0, visibleSize.height/2);
    
    grass2 = cocos2d::Sprite::create("backgrounds/background1.png");
    grass2->setPosition(bg1->boundingBox().size.width - 1,visibleSize.height/2);
    
    clouds1 = cocos2d::Sprite::create("backgrounds/cloudsmove.png");
    clouds1->setPosition(0, visibleSize.height/2);
    
    clouds2 = cocos2d::Sprite::create("backgrounds/cloudsmove.png");
   clouds2->setPosition(bg1->boundingBox().size.width - 1,visibleSize.height/2);
    
    trees1 = cocos2d::Sprite::create("backgrounds/trees.png");
    trees1->setPosition(0, visibleSize.height/2);
    
    trees2 = cocos2d::Sprite::create("backgrounds/trees.png");
    trees2->setPosition(bg1->boundingBox().size.width - 1,visibleSize.height/2);
    
    treespainters1 = cocos2d::Sprite::create("backgrounds/treespainters.png");
    treespainters1->setPosition(0, visibleSize.height/2);
    
    treespainters2 = cocos2d::Sprite::create("backgrounds/treespainters.png");
    treespainters2->setPosition(bg1->boundingBox().size.width - 1,visibleSize.height/2);

    addChild(stretchFit(clouds1));
    addChild(stretchFit(clouds2));
    
  addChild(stretchFit(bg1));
  addChild(stretchFit(bg2));
    
    addChild(stretchFit(treespainters1));
    addChild(stretchFit(treespainters2));
    
    addChild(stretchFit(trees1));
    addChild(stretchFit(trees2));
    
    
    
    addChild(stretchFit(grass1));
    addChild(stretchFit(grass2));
 
  return true;
}

void Background::update(float dt) {
  srand(time(NULL));
  bg1->setPositionX(bg1->getPositionX()-scrollSpeed);
  bg2->setPositionX(bg2->getPositionX()-scrollSpeed);
   
    grass1->setPositionX(grass1->getPositionX()-scrollSpeed*3);
    grass2->setPositionX(grass2->getPositionX()-scrollSpeed*3);
    
    trees1->setPositionX(trees1->getPositionX()-scrollSpeed*2);
    trees2->setPositionX(trees2->getPositionX()-scrollSpeed*2);
    
    treespainters1->setPositionX(treespainters1->getPositionX()-scrollSpeed*1.5);
    treespainters2->setPositionX(treespainters2->getPositionX()-scrollSpeed*1.5);

if (bg1->getPositionX() < -bg1->boundingBox().size.width/2) {
    bg1->setPositionX( bg2->getPositionX() + bg2->boundingBox().size.width);
  }
  if (bg2->getPositionX() < -bg2->boundingBox().size.width/2) {
    bg2->setPositionX(bg1->getPositionX() + bg1->boundingBox().size.width);
      
  }
    if (grass1->getPositionX() < -grass1->boundingBox().size.width/2) {
        grass1->setPositionX( grass2->getPositionX() + grass2->boundingBox().size.width);
    }
    if (grass2->getPositionX() < -grass2->boundingBox().size.width/2) {
        grass2->setPositionX(grass1->getPositionX() + grass1->boundingBox().size.width);
    }
    
    if (trees1->getPositionX() < -trees1->boundingBox().size.width/2) {
        trees1->setPositionX( trees2->getPositionX() + trees2->boundingBox().size.width);
    }
    if (trees2->getPositionX() < -trees2->boundingBox().size.width/2) {
        trees2->setPositionX(trees1->getPositionX() + trees1->boundingBox().size.width);
    }
    if (treespainters1->getPositionX() < -treespainters1->boundingBox().size.width/2) {
        treespainters1->setPositionX( treespainters2->getPositionX() + treespainters2->boundingBox().size.width);
    }
    if (treespainters2->getPositionX() < -treespainters2->boundingBox().size.width/2) {
        treespainters2->setPositionX(treespainters1->getPositionX() + treespainters1->boundingBox().size.width);
    }

    if (clouds1->getPositionX() < -clouds1->boundingBox().size.width/2) {
        clouds1->setPositionX( clouds2->getPositionX() + clouds2->boundingBox().size.width);
    }
    if (clouds2->getPositionX() < -clouds2->boundingBox().size.width/2) {
        clouds2->setPositionX(clouds1->getPositionX() + clouds1->boundingBox().size.width);
    }
}
