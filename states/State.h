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

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
public:
    State(sf::RenderWindow* window);
    ~State();

    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
