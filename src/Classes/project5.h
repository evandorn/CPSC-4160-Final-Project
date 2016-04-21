#include <list>
#include "cocos2d.h"

#include "mySprite.h"
#include "Utilities.h"
#include "Foreground.h"
#include "Background.h"

class Project5 : public cocos2d::Layer {
public:
    Project5() : sprites() {}
    ~Project5();
  void update(float dt);
  static cocos2d::Scene* createScene();
  virtual bool init();
  void generatePokemon();
  CREATE_FUNC(Project5);
private:
    std::list<MySprite*> sprites;
    Foreground*   foreground;
    Background*   background;
};
