//
//  TrainerSprite.hpp
//  asg4
//
//  Created by Evan Dorn on 4/10/16.
//
//

#ifndef TrainerSprite_h
#define TrainerSprite_h

#include <string>
#include <iostream>
#include "mySprite.h"
#include "cocos2d.h"
using namespace std;

class TrainerSprite : public MySprite {

  public:
    TrainerSprite(const std::string& name, int noFrames, cocos2d::Point pos);
    virtual ~TrainerSprite() { }
    void update(float dt);
    bool getMoveLeft( bool moveLeft );
    bool getMoveRight( bool moveRight );

  private:
    bool moveLeft, moveRight, moveUp, moveDown;
    const cocos2d::Vec2 saveVelocity;

};

#endif /* TrainerSprite_h */
