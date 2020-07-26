#include "Button.h"


Button::Button(float x,float y, float width, float height,
            std::string text,sf::Font* font,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = IDLE;
    this->rect.setSize(sf::Vector2f(width,height));
    this->rect.setPosition(sf::Vector2f(x,y));
    this->font = font;

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setOutlineColor(sf::Color::Red);
    this->text.setCharacterSize(12.);
    this->text.setPosition(
        this->rect.getPosition().x + this->rect.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->rect.getPosition().y + this->rect.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height
    );
    this->text.setFillColor(sf::Color::White);
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;
    this->rect.setFillColor(idleColor);
}

Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePosition){
    
    this->buttonState = IDLE;
    
    if (this->rect.getGlobalBounds().contains(mousePosition))
    {
        this->buttonState = HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = PRESSED;
        }
        
    }
    
    switch (this->buttonState)
    {
    case IDLE:
        this->rect.setFillColor(this->idleColor);
        break;
    case PRESSED:
        this->rect.setFillColor(this->activeColor);
        break;
    case HOVER:
        this->rect.setFillColor(this->hoverColor);
        break;
    default:
        this->rect.setFillColor(sf::Color::Red);
        break;
    }
}

void Button::render(sf::RenderTarget* target){
    target->draw(this->rect);
    target->draw(this->text);
}

const bool Button::isPressed(){
    return this->buttonState == PRESSED;
}

void Button::setPosition(const float windowWidth, const float windowHeight){
    this->rect.setPosition(
        windowWidth,
        windowHeight);
    this->text.setPosition(
        this->rect.getPosition().x + this->rect.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->rect.getPosition().y + this->rect.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height
    );
}
sf::Vector2f Button::getSize(){
    return this->rect.getSize();
}

void Button::setSize(const float width, const float height){
    this->rect.setSize(sf::Vector2f(width,height));
}
