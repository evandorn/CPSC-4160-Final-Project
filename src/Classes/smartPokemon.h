//
//  smartPokemon.h
//  project4
//
//  Created by Christopher Cornejo on 4/20/16.
//
//


#include <stdio.h>
#include "cocos2d.h"
#include "PokemonSprite.h"

class SmartPokemon : public PokemonSprite {
public:
    SmartPokemon(const std::string& name, int noFrames, cocos2d::Point pos, const MySprite* e);
    void update(float);
    //virtual void setVelocity(cocos2d::Vec2 velocity);

private:
    const MySprite *enemy;
    bool evade;
    float maxDist;

protected:
    //cocos2d::Vec2 velocity;
};

