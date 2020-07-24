#pragma once

#include "Entity.h"

Entity::Entity(/* args */)
{
    this->rect.setSize(sf::Vector2f(50.,50.));
    this->mvmspeed = 100.;
}

Entity::move(const float& dt,const float x, const float y){
    this->rect.move(x*this->mvmspeed*dt,y*this->mvmspeed*dt);
}

Entity::~Entity()
{
}