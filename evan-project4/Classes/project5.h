#include <list>
#include "cocos2d.h"
#include "mySprite.h"

class Project4 : public cocos2d::Layer {
public:
  Project4() : sprites() {}
  ~Project4();
  static cocos2d::Scene* createScene();
  virtual bool init();
  void menuCloseCallback(cocos2d::Ref* pSender);
  void update(float);
  void generatePokemon();
    
  // implement the "static create()" method manually
  CREATE_FUNC(Project4);
private:
  std::list<MySprite*> sprites;
  cocos2d::Sprite* background;
};
