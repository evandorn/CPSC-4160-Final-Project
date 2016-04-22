//
//  PokeballSprite.hpp
//  asg5
//
//  Created by Evan Dorn on 4/22/16.
//
//

#ifndef PokeballSprite_h
#define PokeballSprite_h

#include <string>
#include "mySprite.h"
#include "cocos2d.h"

class PokeballSprite : public MySprite {
    
public:
    PokeballSprite(const std::string& name, int noFrames, cocos2d::Point pos);
    virtual ~PokeballSprite() { }
    static int getNumberPokeballs();
    void update(float dt);
};

#endif /* PokeballSprite_h */
