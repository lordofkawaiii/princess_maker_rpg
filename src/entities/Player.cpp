#include "Player.hpp"

Player::Player(float x, float y, sf::Texture* texture)
{
  this->initVariables();
  this->setPosition(x, y);
  this->createAnimationComponent(*texture);
  this->createMovementComponent(100.f, 5.f, 3.f);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(up), 25.f,
                                         0, 0, 3, 0, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(down),
                                         25.f, 0, 13, 3, 13, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(left),
                                         25.f, 0, 4, 3, 4, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(right),
                                         25.f, 0, 5, 3, 5, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(idle),
                                         25.f, 0, 3, 3, 3, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(up_left),
                                         25.f, 0, 1, 3, 1, 32, 32);
  this->animationComponent->addAnimation(this->movementComponent->getDirString(up_right),
                                         25.f, 0, 2, 3, 2, 32, 32);
  this->animationComponent->addAnimation(
    this->movementComponent->getDirString(bottom_left), 25.f, 0, 14, 3, 14, 32, 32);
  this->animationComponent->addAnimation(
    this->movementComponent->getDirString(bottom_right), 25.f, 0, 15, 3, 15, 32, 32);
  // this->initComponents();
  this->dir = this->movementComponent->getDirString(idle);
}

Player::~Player() {}
void Player::initVariables() {}
void Player::initComponents()
{
  // this->createMovementComponent(200.f,5.f,3.f);
  // this->createAnimationComponent(this->sprite,this->)
}

void Player::update(float dt)
{
  Entity::update(dt);
  this->movementComponent->update(dt);
  if (this->movementComponent->getDirString(this->movementComponent->getDir()) ==
      this->dir)
  {
    this->animationComponent->play(this->dir, dt);
  }
  else
  {
    this->animationComponent->play(
      this->movementComponent->getDirString(this->movementComponent->getDir()), dt);
    this->dir = this->movementComponent->getDirString(this->movementComponent->getDir());
  }
}
