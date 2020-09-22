#pragma once
#include "GameObject.h"
class PowerUp :
    public GameObject
{
private:
    int type;

    int value;

public:
    int getType() const;
    
    int getValue() const;

};

