#include "Button.h"


Button::Button(float x,float y, float width, float height,
            std::string text,sf::Font* font
            sf::Color idleColor, sf::Color colorHover, sf::Color activeColor)
{
    this->rect.setSize(sf::Vector2f(width,height));
    this->rect.setPosition(sf::Vector2f(x,y));
    this->font = font;

    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setColor(sf::Color::Red);
    this->text.setCharacterSize(12.);
    this->text.setPosition(
        this->rect.getPosition().x / 2. - this->text.getGlobalBounds().width / 2.,
        this->text.setPosition().y / 2. - this->text.getGlobalBounds().height / 2.
    );

    this->idleColor = idleColor;
    this->colorHover = colorHover;
    this->activeColor = activeColor;
    this->rect.setFillColor(idleColor)
}

Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePosition){
    if (this->rect.getGlobalBounds().contains(mousePosition))
    {
        
    }
    
}

void Button::render(sf::RenderTarget* target){
    target->draw(this->rect)
}