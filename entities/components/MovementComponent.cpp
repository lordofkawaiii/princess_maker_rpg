#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxvelocity)
{
    this->maxvelocity = maxvelocity;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(const float& dt){

}
void MovementComponent::move(const float dir_x, const float dir_y){
    this->velocity.x = this->maxvelocity * dir_x;
    this->velocity.y = this->maxvelocity * dir_y;
}

const sf::Vector2f& MovementComponent::getVelocity() const{
    return this->velocity;
}
