//
//  PokemonSprite.h
//  asg4
//
//  Created by Evan Dorn on 4/10/16.
//
//

#ifndef PokemonSprite_h
#define PokemonSprite_h

#include <string>
#include "mySprite.h"
#include "cocos2d.h"

class PokemonSprite : public MySprite {

public:
PokemonSprite(const std::string& name, int noFrames, cocos2d::Point pos);
virtual ~PokemonSprite() { }
static int getNumberOfPokemon();
void update(float dt);
    
};

#endif /* PokemonSprite_h */
