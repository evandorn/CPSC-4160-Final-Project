#include <list>
#include "cocos2d.h"

#include "mySprite.h"
#include "Utilities.h"
#include "Background.h"

class Project5 : public cocos2d::Layer {
public:
    Project5() : sprites() {}
    ~Project5();
  void update(float dt);
  static cocos2d::Scene* createScene();
  void menuCloseCallback(Ref* pSender);
  virtual bool init();
  void generatePokemon();
  void drawPokeball();

  CREATE_FUNC(Project5);
private:
    std::list<MySprite*> sprites;
    Background*   background;
    cocos2d::Label * collideLabel;
    cocos2d::Label * countLabel;
    cocos2d::Label *scoreLabel;
    bool labelDrawn;
    int collideCount;
    cocos2d::MenuItem* closeItem;
    cocos2d::Menu*     menu;
    cocos2d::Label*    label;
    MySprite *arcanineSprite;
    MySprite *moltresSprite;
    MySprite *articunoSprite;
    MySprite *dragoniteSprite;
    MySprite *trainerSprite;
    MySprite *pokeball;
    bool pokeballThrow = false;
};
