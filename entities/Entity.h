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

class Entity
{
private:
protected:
    sf::RectangleShape rect;
    float mvmspeed;
public:
    Entity(/* args */);
    ~Entity();
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;
    virtual void move(const float& dt,const float x, const float y);
};


