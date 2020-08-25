#include "Button.hpp"

Button::Button(float x, float y, float width, float height, std::string text,
               sf::Font* font, unsigned characterSize, sf::Color idleText,
               sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
               sf::Color hoverColor, sf::Color activeColor, sf::Color outlineIdleColor,
               sf::Color outlineHoverColor, sf::Color outlineActiveColor,
               unsigned short id)
{
  this->buttonState = IDLE;
  this->rect.setSize(sf::Vector2f(width, height));
  this->rect.setPosition(sf::Vector2f(x, y));
  this->font = font;

  this->text.setFont(*this->font);
  this->text.setString(text);
  this->text.setFillColor(sf::Color::White);
  this->text.setOutlineColor(sf::Color::Red);
  this->text.setCharacterSize(((width - width / 50.f) / text.size()));
  this->text.setPosition(
    this->rect.getPosition().x + this->rect.getGlobalBounds().width / 2.f -
      this->text.getGlobalBounds().width / 2.f,
    this->rect.getPosition().y + this->rect.getGlobalBounds().height / 2.f -
      this->text.getGlobalBounds().height);
  this->text.setFillColor(idleText);
  this->idleColor = idleColor;
  this->hoverColor = hoverColor;
  this->activeColor = activeColor;
  this->outlineIdleColor = outlineIdleColor;
  this->outlineHoverColor = outlineHoverColor;
  this->outlineActiveColor = outlineActiveColor;
  this->idleText = idleText;
  this->hoverText = hoverText;
  this->activeText = activeText;
  this->rect.setFillColor(idleColor);
  this->rect.setOutlineThickness(1.f);
  this->rect.setOutlineColor(outlineIdleColor);
  this->id = id;
}

Button::~Button() {}

void Button::update(const sf::Vector2f mousePosition)
{
  this->buttonState = IDLE;

  if (this->rect.getGlobalBounds().contains(mousePosition))
  {
    this->buttonState = HOVER;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      this->buttonState = PRESSED;
    }
  }
  // if (isPressed())
  // {
  // }
  // else
  // {
  //   if (this->rect.getGlobalBounds().contains(mousePosition))
  //   {
  //     this->buttonState = HOVER;
  //   }

  //   else
  //   {
  //     this->buttonState = IDLE;
  //   }
  // }

  switch (this->buttonState)
  {
  case IDLE:
    this->rect.setFillColor(this->idleColor);
    this->text.setFillColor(this->idleText);
    this->rect.setOutlineColor(outlineIdleColor);
    break;
  case PRESSED:
    this->rect.setFillColor(this->activeColor);
    this->text.setFillColor(this->activeText);
    this->rect.setOutlineColor(outlineActiveColor);
    break;
  case HOVER:
    this->rect.setFillColor(this->hoverColor);
    this->text.setFillColor(this->hoverText);
    this->rect.setOutlineColor(outlineHoverColor);
    break;
  default:
    this->rect.setFillColor(sf::Color::Red);
    break;
  }
}

void Button::render(sf::RenderTarget* target)
{
  target->draw(this->rect);
  target->draw(this->text);
}

bool Button::isPressed()
{
  return this->buttonState == PRESSED;
}

void Button::setPosition(const float windowWidth, const float windowHeight)
{
  this->rect.setPosition(windowWidth, windowHeight);
  this->text.setPosition(
    this->rect.getPosition().x + this->rect.getGlobalBounds().width / 2.f -
      this->text.getGlobalBounds().width / 2.f,
    this->rect.getPosition().y + this->rect.getGlobalBounds().height / 2.f -
      this->text.getGlobalBounds().height);
}
sf::Vector2f Button::getSize()
{
  return sf::Vector2f(this->rect.getGlobalBounds().width,
                      this->rect.getGlobalBounds().height);
}

void Button::setSize(const float width, const float height)
{
  this->rect.setSize(sf::Vector2f(width, height));
}

bool Button::isCursorIn(const sf::Vector2f mousePosition)
{
  return this->rect.getGlobalBounds().contains(mousePosition);
}

void Button::setClicked()
{
  this->buttonState = PRESSED;
}

void Button::resetSate()
{
  this->buttonState = IDLE;
}
void Button::setText(std::string newString)
{
  this->text.setString(newString);
  this->updateTextSize();
}
std::string Button::getText()
{
  return this->text.getString();
}
sf::Vector2f Button::getPosition()
{
  return this->rect.getPosition();
}

void Button::setPosition(sf::Vector2f positions)
{
  this->setPosition(positions.x, positions.y);
}

void Button::updateTextSize()
{
  float width = this->getSize().x;
  this->text.setCharacterSize(
    ((width - width / 50.f) / this->text.getString().getSize()));
  this->text.setPosition(
    this->rect.getPosition().x + this->rect.getGlobalBounds().width / 2.f -
      this->text.getGlobalBounds().width / 2.f,
    this->rect.getPosition().y + this->rect.getGlobalBounds().height / 2.f -
      this->text.getGlobalBounds().height);
}

unsigned short Button::getId()
{
  return this->id;
}
void Button::setId(unsigned short id)
{
  this->id = id;
}