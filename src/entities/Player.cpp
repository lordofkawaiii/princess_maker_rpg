#include "Player.hpp"

Player::Player(float x, float y, sf::Texture* texture)
{
  this->initVariables();
  this->setPosition(x, y);
  this->createMovementComponent(200.f, 5.f, 3.f);
  this->createAnimationComponent(*texture);
  this->animationComponent->addAnimation("left", 100.f, 0, 0, 3, 0, 32, 32);
  // this->initComponents();
}

Player::~Player() {}
void Player::initVariables() {}
void Player::initComponents()
{
  // this->createMovementComponent(200.f,5.f,3.f);
  // this->createAnimationComponent(this->sprite,this->)
}