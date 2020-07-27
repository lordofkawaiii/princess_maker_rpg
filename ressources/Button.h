#pragma once
#include<stdio.h>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

enum BUTTON_STATE 
{
    IDLE = 0,
    PRESSED = 1,
    HOVER = 2
};

class Button
{
private:

    unsigned short buttonState;
    bool pressed;
    bool hover;

    sf::RectangleShape rect;
    sf::Font* font;
    sf::Text text;
    
    // colors
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    sf::Color idleText;
    sf::Color hoverText;
    sf::Color activeText;



public:
    Button(float x,float y, float width, float height,
            std::string text,sf::Font* font, unsigned characterSize,
            sf::Color idleText, sf::Color hoverText, sf::Color activeText,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    void update(const sf::Vector2f mousePosition);
    void render(sf::RenderTarget* target);
    const bool isPressed();
    void setPosition(const float windowWidth, const float windowHeight);
    sf::Vector2f getSize();
    void setSize(const float width, const float height);
};


