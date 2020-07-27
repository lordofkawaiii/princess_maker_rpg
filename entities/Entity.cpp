
#include "Entity.h"

Entity::Entity(/* args */)
{
    this->initVariables();
}

void Entity::initVariables(){
    this->sprite = NULL;
    this->texture = NULL;
}

void Entity::move(const float& dt,const float x, const float y){
    if (this->sprite)
    {
        this->movementComponent->move(x,y); // set velocity
        this->sprite->move(this->movementComponent->getVelocity()*dt);
    }
    
}

void Entity::render(sf::RenderTarget* target){
    if (this->sprite)
    {
        target->draw(*this->sprite);
    }
}

void Entity::update(const float& dt){
    
}

void Entity::createSprite(){
    this->sprite = new sf::Sprite(*this->texture);
}

Entity::~Entity()
{
    if (this->sprite)
    {
        delete this->sprite;
    }
}

void Entity::setPosition(const float x, const float y){
    if (this->sprite)
    {
        this->sprite->setPosition(x,y); 
    }
    
}

void Entity::createMovementComponent(const float maxVelocity){
    this->movementComponent = new MovementComponent(maxVelocity);
}