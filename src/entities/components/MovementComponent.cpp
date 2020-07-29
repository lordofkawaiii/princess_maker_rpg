#include "MovementComponent.hpp"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxvelocity,
                                     float acceleration, float deceleration)
{
  this->maxvelocity = maxvelocity;
  this->sprite = &sprite;
  this->acceleration = acceleration;
  this->deceleration = deceleration;
}

void MovementComponent::update(float dt)
{
  // deceleration
  if (this->velocity.x > 0.f) // go to the right
  {
    if (this->velocity.x > this->maxvelocity)
    {
      this->velocity.x = this->maxvelocity;
    }

    this->velocity.x -= deceleration;
    if (this->velocity.x < 0.f)
    {
      this->velocity.x = 0.f;
    }
  }
  else if (this->velocity.x < 0.f)
  { //go to the left

    if (this->velocity.x < this->maxvelocity * -1)
    {
      this->velocity.x = this->maxvelocity * -1;
    }
    this->velocity.x += deceleration;
    if (this->velocity.x > 0.f)
    {
      this->velocity.x = 0.f;
    }
  }
  if (this->velocity.y > 0.f) // go to the top
  {
    if (this->velocity.y > this->maxvelocity)
    {
      this->velocity.y = this->maxvelocity;
    }
    this->velocity.y -= deceleration;
    if (this->velocity.y < 0.f)
    {
      this->velocity.y = 0.f;
    }
  }
  else if (this->velocity.y < 0.f) //go to the bottom
  {

    if (this->velocity.y < this->maxvelocity * -1)
    {
      this->velocity.y = this->maxvelocity * -1;
    }
    this->velocity.y += deceleration;
    if (this->velocity.y > 0.f)
    {
      this->velocity.y = 0.f;
    }
  }

  this->sprite->move(this->velocity * dt);
}
void MovementComponent::move(float dt, const float dir_x, const float dir_y)
{
  // acceleration
  this->velocity.x += this->acceleration * dir_x * dt;
  this->velocity.y += this->acceleration * dir_y * dt;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{

  return this->velocity;
}
