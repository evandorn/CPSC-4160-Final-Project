#include "cocos2d.h"
#include "Utilities.h"
#include <time.h>
#include <stdlib.h>

class Background : public cocos2d::Layer {
private:
    cocos2d::Sprite* bg1;
    cocos2d::Sprite* bg2;
    cocos2d::Sprite* grass1;
    cocos2d::Sprite* grass2;
    cocos2d::Sprite* trees1;
    cocos2d::Sprite* trees2;
    cocos2d::Sprite* clouds1;
    cocos2d::Sprite* clouds2;

  int scrollSpeed = 1;
public:
  void update(float dt);
  virtual bool init();
  CREATE_FUNC(Background);
};
