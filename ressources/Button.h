#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>


class Button
{
private:
    sf::RectangleShape rect;
    sf::Font* font;
    sf::Text text;
    
    // colors
    sf::Color idleColor;
    sf::Color colorHover;
    sf::Color activeColor;


public:
    Button(float x,float y, float width, float height,
            std::string text,sf::Font* font
            sf::Color idleColor, sf::Color colorHover, sf::Color activeColor);
    ~Button();

    void update(const sf::Vector2f mousePosition);
    void render(sf::RenderTarget* target);
};


