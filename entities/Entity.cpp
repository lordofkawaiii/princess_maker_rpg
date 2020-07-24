
#include "Entity.h"

Entity::Entity(/* args */)
{
    this->rect.setSize(sf::Vector2f(50.,50.));
    this->rect.setFillColor(sf::Color::White);
    this->mvmspeed = 100.;
}

void Entity::move(const float& dt,const float x, const float y){
    this->rect.move(x*this->mvmspeed*dt,y*this->mvmspeed*dt);
}

void Entity::render(sf::RenderTarget* target){
    target->draw(this->rect);
}

void Entity::update(const float& dt){
    
}

Entity::~Entity()
{
}