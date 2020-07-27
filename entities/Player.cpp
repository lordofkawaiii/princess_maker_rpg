#include "Player.h"

Player::Player(float x, float y,sf::Texture* texture)
{
    this->initVariables();
    this->createSprite(texture);
    this->setPosition(x,y);
    this->initComponents();
}

Player::~Player()
{
}
void Player::initVariables(){

}
void Player::initComponents(){
    this->createMovementComponent(200.f,5.f,3.f);
}