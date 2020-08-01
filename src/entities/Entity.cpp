
#include "Entity.hpp"

Entity::Entity(/* args */)
{
  this->initVariables();
}

void Entity::initVariables()
{
  this->sprite = nullptr;
}

void Entity::move(float dt, const float x, const float y)
{
  if (this->sprite)
  {
    this->movementComponent->move(dt, x, y); // set velocity
  }
}

void Entity::render(sf::RenderTarget* target)
{
  if (this->sprite)
  {
    target->draw(*this->sprite);
  }
}

void Entity::update(float dt) {}

void Entity::createSprite(sf::Texture* texture)
{
  // this->sprite = new sf::Sprite(*texture);
  this->sprite = new sf::Sprite();
}

Entity::~Entity()
{
  if (this->sprite)
  {
    delete this->sprite;
  }
  if (this->movementComponent)
  {
    delete this->movementComponent;
  }
}

void Entity::setPosition(const float x, const float y)
{
  if (this->sprite)
  {
    this->sprite->setPosition(x, y);
  }
}

void Entity::createMovementComponent(const float maxVelocity, float acceleration,
                                     float deceleration)
{
  if (this->sprite)
  {
    this->movementComponent =
      new MovementComponent(*this->sprite, maxVelocity, acceleration, deceleration);
  }
}

void Entity::createAnimationComponent(sf::Texture& texture)
{
  if (!this->sprite)
  {
    this->createSprite(&texture);
  }
  this->animationComponent = new AnimationComponent(*this->sprite, texture);
}