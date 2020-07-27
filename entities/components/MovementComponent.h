#pragma once
#include<iostream>
#include<ctime>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<stack>

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

class MovementComponent
{
private:
protected:
    float maxvelocity;
    sf::Vector2f velocity;
    float acceleration;
    float deceleration;

    sf::Sprite* sprite;

    //init fonctions
public:
    MovementComponent(sf::Sprite& sprite,float maxvelocity,float acceleration, float deceleration);
    ~MovementComponent();

    const sf::Vector2f& getVelocity() const;

    void update(const float& dt);
    void move(const float& dt,const float dir_x, const float dir_y);
};

