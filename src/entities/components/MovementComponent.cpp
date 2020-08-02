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
  if (this->velocity.x > 0.f)
  {
    this->velocity.x -= this->deceleration;
    if (this->velocity.y != 0.f && this->velocity.x > this->maxvelocity / 2)
    {
      this->velocity.x = this->maxvelocity / 2;
    }
    if (this->velocity.x > this->maxvelocity)
    {
      this->velocity.x = this->maxvelocity;
    }
    if (this->velocity.x < 0.f)
    {
      this->velocity.x = 0.f;
    }
  }
  else if (this->velocity.x < 0.f)
  {
    this->velocity.x += this->deceleration;
    if (this->velocity.y != 0.f && this->velocity.x < -this->maxvelocity / 2)
    {
      this->velocity.x = -this->maxvelocity / 2;
    }

    if (this->velocity.x < -this->maxvelocity)
    {
      this->velocity.x = -this->maxvelocity;
    }
    if (this->velocity.x > 0.f)
    {
      this->velocity.x = 0.f;
    }
  }
  if (this->velocity.y > 0.f)
  {
    this->velocity.y -= deceleration;
    if (this->velocity.x != 0.f && this->velocity.y > this->maxvelocity / 2)
    {
      this->velocity.y = this->maxvelocity / 2;
    }
    if (this->velocity.y > this->maxvelocity)
    {
      this->velocity.y = this->maxvelocity;
    }
    if (this->velocity.y < 0.f)
    {
      this->velocity.y = 0.f;
    }
  }
  else if (this->velocity.y < 0.f)
  {
    this->velocity.y += deceleration;
    if (this->velocity.x != 0.f && this->velocity.y < -this->maxvelocity / 2)
    {
      this->velocity.y = -this->maxvelocity / 2;
    }
    if (this->velocity.y < -this->maxvelocity)
    {
      this->velocity.y = -this->maxvelocity;
    }
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
  this->velocity.x += this->acceleration * dir_x;
  this->velocity.y += this->acceleration * dir_y;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{

  return this->velocity;
}

bool MovementComponent::isIdle()
{
  return this->velocity.x == 0.f and this->velocity.y == 0.f;
}

direction MovementComponent::getDir()
{
  direction res;
  if (velocity.x > 0)
  {
    if (velocity.y > 0)
    {
      res = up_right;
    }
    else if (velocity.y == 0)
    {
      res = right;
    }
    else if (velocity.y < 0)
    {
      res = bottom_right;
    }
  }
  else if (velocity.x < 0)
  {
    if (velocity.y > 0)
    {
      res = up_left;
    }
    else if (velocity.y == 0)
    {
      res = left;
    }
    else if (velocity.y < 0)
    {
      res = bottom_left;
    }
  }
  else if (velocity.x == 0)
  {
    if (velocity.y > 0)
    {
      res = up;
    }
    else if (velocity.y == 0)
    {
      res = idle;
    }
    else if (velocity.y < 0)
    {
      res = down;
    }
  }
  return res;
}

std::string MovementComponent::getDirString(direction dir)
{
  switch (dir)
  {
  case left:
    return "left";
    break;
  case right:
    return "right";
    break;
  case up:
    return "up";
    break;
  case down:
    return "down";
    break;
  case idle:
    return "idle";
    break;
  case bottom_left:
    return "bottom_left";
    break;
  case bottom_right:
    return "bottom_right";
    break;
  case up_left:
    return "up_left";
    break;
  case up_right:
    return "up_right";
    break;
  default:
    throw "invalid direction";
    break;
  }
}
