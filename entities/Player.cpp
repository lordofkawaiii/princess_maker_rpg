#include "Player.h"

Player::Player(float x, float y,sf::Texture* texture)
{
    this->initVariables();
    this->texture = texture;
    this->createSprite();
    this->setPosition(x,y);
    this->initComponents();
}

Player::~Player()
{
}
void Player::initVariables(){

}
void Player::initComponents(){
    this->createMovementComponent(100.f);
}