#pragma once
#include "MovementComponent.h"
class Entity
{
private:
protected:
    sf::Texture* texture = NULL;
    sf::Sprite* sprite = NULL;
    MovementComponent* movementComponent;

public:
    Entity();
    ~Entity();
    void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
    virtual void move(const float& dt,const float x, const float y);
    void createSprite();
    void setPosition(const float x, const float y);
    void createMovementComponent(const float maxVelocity);
    void initVariables();
};


