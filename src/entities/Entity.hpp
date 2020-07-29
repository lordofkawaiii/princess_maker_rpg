#pragma once
#include "entities/components/AnimationComponent.hpp"
#include "entities/components/MovementComponent.hpp"
class Entity
{
private:
protected:
  sf::Sprite*         sprite = nullptr;
  MovementComponent*  movementComponent;
  AnimationComponent* animationComponent;

public:
  Entity();
  virtual ~Entity();
  void         update(float dt);
  virtual void render(sf::RenderTarget* target);
  virtual void move(float dt, const float x, const float y);
  void         createSprite(sf::Texture* texture);
  void         setPosition(const float x, const float y);
  void         createMovementComponent(const float maxVelocity, float acceleration,
                                       float deceleration);
  void         createAnimationComponent(sf::Texture& texture);
  void         initVariables();
};
