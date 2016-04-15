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
#include "MySprite.h"
#include "cocos2d.h"

class TrainerSprite : public MySprite {
public:
    TrainerSprite(const std::string& name, int noFrames, cocos2d::Point pos);
    virtual ~TrainerSprite() { }
    void update(float dt);
};

#endif /* TrainerSprite_h */
